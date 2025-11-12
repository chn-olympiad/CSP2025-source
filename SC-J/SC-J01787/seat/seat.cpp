#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
int n,u,m,e,i,j,l,r,s,x,y,xx,yy;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>x>>y;
	cin>>m;
	a[m]++;
	if(x==1&&y==1)
	{
		cout<<1<<' '<<1;
		return 0;
	}
	for(i=2;i<=x*y;i++)
	{
		cin>>u;
		a[u]++;
	}
	s=0;
	for(i=100;i>=1;i--)
	{
		if(a[i]>0)
		{
			s++;
			a[i]=s;
		}
	}
	l=a[m];
	if(l%x==0)
	{
		xx=l/x;
		if(xx%2==0)
		{
			yy=1;
		}
		else
		{
			yy=x;
		}
	}
	else
	{
		xx=l/x+1;
		if(xx%2==0)
		{
			yy=x-l%x; 
		}
		else
		{
			yy=l%x; 
		}
	}
	cout<<xx<<' '<<yy;
}
/*
2 2
99 100 97 98*/