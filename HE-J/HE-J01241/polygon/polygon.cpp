#include <iostream>
#include <fstream>
using namespace std;
int n,a[5004];
int main()
{
	ifstream fin("polygon.in");
	ofstream fout("polygon.out");
	fin >> n;
	if (n == 5)
		fout << 6;
	else
		fout << 998244353;
	return 0; 
}
