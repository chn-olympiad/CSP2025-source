#include<bits/stdc++.h>
using namespace std;

int n,m,ct=0;
int sum[5500],a[5500];
 
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3)
	{
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	m=max(a[1],max(a[2],a[3]));
	if(a[1]+a[2]+a[3]>m*2)
	{
		ct++;
	}
	cout<<ct;
	return 0;
} 
