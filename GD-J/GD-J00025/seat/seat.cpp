#include<cstdio>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],x,s,w,c,r;
bool cmp(int u,int v)
{
	return u>v;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(x==a[i])
		{
			s=i;
			break;
		}
	}
	c=ceil(s*1.0/n);
	w=(s%n==0?n:s%n);
	r=(c%2==0?n-w+1:w);
	cout<<c<<" "<<r<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
