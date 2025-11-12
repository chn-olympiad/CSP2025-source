#include"bits/stdc++.h"
using namespace std;
string s;
int a[11],t;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>=48&&s[i]<=57)a[int(s[i])-48]++;
	}
	for(int i=9;i>0;i--)
	{
		while(a[i]--)
		{cout<<i;t=1;}
	}
	
	if(t==0)
	{
		cout<<0;return 0;
	}
	else for(int i=1;i<=a[0];i++)
	cout<<"0";
} 
