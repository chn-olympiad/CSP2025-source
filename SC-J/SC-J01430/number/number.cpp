#include<fstream>
#include<iostream>
#include<string> 
using namespace std;
int main()
{
	ifstream fin("number.in");
	ofstream fout("number.out");
	bool s;
	fin>>s;
	fout<<s;
	fin.close();
	fout.close();
	return 0;
}