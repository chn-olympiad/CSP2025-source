#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
int n,u,m,e,i,j,l,r,x,y,xx,yy;
string s;
int a[15];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	if(s.size()==1&&s[0]>='0'&&s[0]<='9')
	{
		cout<<s[0]-48;
		return 0;
	}
	u=0;
	for(i=0;i<s.size();i++)
	{
		if(s[i]>=48&&s[i]<=57)
		{
			a[(int(s[i])-48)]++;
		}
	}
	for(i=9;i>=0;i++)
	{
		if(a[i]>0)
		{
			for(j=0;j<a[i];j++)
			{
				u=u*10+a[i];
			}
		}
		
	}
	cout<<u;
}