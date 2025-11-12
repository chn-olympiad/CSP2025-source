#include<bits/stdc++.h>
using namespace std;
int a[10];
int main()
{
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	
	string s;
	getline(cin,s);
	for(int i=0;i<'\n';i++)
	{
		if(char(s[i])>=48&&char(s[i])<=57)
		{
			a[char(s[i])-48]++;
		}
	}
	for(int k=9;k>=0;k--)
	{
		if(a[k]!=0)
		{
			for(int j=1;j<=a[k];j++)
			{
				cout<<k;
			}
		}
	}
}
