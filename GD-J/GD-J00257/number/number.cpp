#include<bits/stdc++.h>

using namespace std;

string s;
int a[10]={0};

int main()
{
	ifstream fin("number.in");
	ofstream fout("number.out");
	
	fin>>s;
	
	for(int i=0;i<s.size();i++)
		if(s[i]>='0' && s[i]<='9')
			a[ s[i] - '0' ] ++ ;
	
	for(int i=9;i>=0;i--)
		if(a[i]>0)	
			for(int j=1;j<=a[i];j++)
				fout<<i;
	
	fin.close();
	fout.close();
	return 0;	
} 
