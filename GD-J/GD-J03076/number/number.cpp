#include<bits/stdc++.h>
using namespace std;
int a[1000005]; 
int main(){
	ifstream fin("number.in");
	ofstream fout("number.out");
	string s;
	fin>>s;int j = 0;
	for(int i = 0;i<s.length();i++)
	{
		if (s[i]>='0' and s[i]<='9')
		{
			a[j] = s[i]-'0';
			j++;
		}
	}
	sort(a,a+j);
	for(int i = j-1;i>=0;i--)
	{
		fout<<a[i];
	}
	fin.close();
	fout.close();
} 
