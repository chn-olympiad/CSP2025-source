#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
string s;
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	ifstream fin("number4.in");
	ofstream fout("number4.out"); 
	fin >> s;
	vector <int> a;
	for (int i = 0;i < s.size();i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			a.push_back(s[i] - '0');
		}
	}
	sort(a.begin(),a.end(),cmp);
	for (int i = 0;i < a.size();i++)
	{
		fout << a[i];
	}
	fin.close();
	fout.close();
	return 0;
}
