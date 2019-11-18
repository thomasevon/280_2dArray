#include <iostream>
#include <fstream>
#include <string>
using namespace std; 

const int ROWS = 9;
const int COLS = 6;

class Array {
private:
	double matrix[ROWS][COLS];
public:
	Array(); // constructor
	void display(); 
	void set(int, int, double); 
	void rowFinder(int);
	void colFinder(int);
};


int main() {
	ifstream input;
	string line; 
	input.open("altitudes.txt");
	Array arr = Array(); // matrix initialized with all zeros
	int row = 0;
	int col = 0;
	while (!input.eof()) {
		if (col == COLS) {
			col = 0;
			row++; 
		}
		double num;
		input >> num; 
		arr.set(row, col, num);
		col++;
	}
	arr.display(); 
	for (int x = 0; x < ROWS; x++)
		arr.rowFinder(x);
	for (int x = 0; x < COLS; x++)
		arr.colFinder(x);
	input.close();
	return 0;
}

Array::Array() {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			matrix[i][j] = 0;
		}
	}
}

void Array::set(int row, int columnNum, double num) {
	matrix[row][columnNum] = num; 
}

void Array::display() {
	cout << "here is the 2d array: " << endl; 
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl; 
	}
	cout << endl; 
}

void Array::rowFinder(int row) {
	bool EW = true;
	bool WE = false; 
	double runner = matrix[row][0];
	double runner2 = matrix[row][COLS - 1];
	for (int i = 1; i < COLS; i++) {
		if (matrix[row][i] < runner) {
			EW = false;
			break;
		}
		runner = matrix[row][i];
	}
	for (int j = COLS - 2; j > -1; j--) {
		if (matrix[row][j] < runner2) {
			WE = false;
			break; 
		}
		runner2 = matrix[row][j];
	}
	if (EW == true) cout << "Row " << row << " East - West is a long incline!" << endl;
	else if (EW == false) cout << "Row " << row << " East - West is not a long incline!" << endl;
	if (WE == true) cout << "Row " << row << " West - East is a long incline!" << endl;
	else if (WE == false) cout << "Row " << row << " West - East is not a long incline!" << endl;
}

void Array::colFinder(int col) {
	bool NS = true;
	bool SN = false;
	double runner = matrix[0][col];
	double runner2 = matrix[ROWS - 1][col];
	for (int i = 1; i < ROWS; i++) {
		if (matrix[i][col] < runner) {
			NS = false;
			break;
		}
		runner = matrix[i][col];
	}
	for (int j = ROWS - 2; j > -1; j--) {
		if (matrix[j][col] < runner2) {
			SN = false;
			break;
		}
		runner2 = matrix[j][col];
	}
	if (NS == true) cout << "Column " << col << " North - South is a long incline!" << endl;
	else if (SN == false) cout << "Column " << col << " North - South is not a long incline!" << endl;
	if (SN == true) cout << "Column " << col << " South - North is a long incline!" << endl;
	else if (SN == false) cout << "Column " << col << " South - North is not a long incline!" << endl;
}
