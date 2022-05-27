#include <iostream>
#include <iomanip>

using namespace std;

//«найти найб≥льш≥ елементи кожного р€дка матриц≥ Y(8,8) ≥ пом≥стити њх на головну д≥агональ, а д≥агональн≥ елементи на м≥сц€ найб≥льших 

void create(int** a, const int rowCount, const int colCount);	
void print(int** a, const int rowCount, const int colCount);
void findmax(int** a, const int rowCount, const int colCount, int* max);
void change (int** a, const int rowCount, const int colCount, int* max);

int main()
{
	srand((unsigned)time(NULL));
	cout << " Your matrix " << endl;
	int rowCount = 8;
	int colCount = 8;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	create(a, rowCount, colCount);
	print(a, rowCount, colCount);
	cout << " Max elements " << endl;
	int* max = new int[rowCount];
	findmax(a, rowCount, colCount, max);	
	for (int i = 0; i < rowCount; i++)
		cout << max[i] << " ";
	cout << endl;
	cout << " New matrix" << endl;
	change(a, rowCount, colCount, max);
	print(a, rowCount, colCount);
	return 0;
	
}

void create(int** a, const int rowCount, const int colCount)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = rand() % 10;
}

void print(int** a, const int rowCount, const int colCount)
{
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(3) << a[i][j];
		cout << endl;
	}
}
void findmax(int** a, const int rowCount, const int colCount, int* max)
{
	for (int i = 0; i < rowCount; i++)
	{
		int max_row = a[i][0];
		for (int j = 1; j < colCount; j++)
			if (a[i][j] > max_row)
				max_row = a[i][j];
		max[i] = max_row;
	}
}

void change(int** a, const int rowCount, const int colCount, int* max)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			if (i == j)
				a[i][j] = max[i];
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			if (i != j && a[i][j] == max[i])
				a[i][j] = max[j];
	
}
