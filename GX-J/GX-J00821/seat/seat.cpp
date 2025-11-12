#include<bits/stdc++.h>
using namespace std;
int n,m;
int v[100000],d,d1,ax,ay;
bool arm(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{		
		cin>>v[i];
		if(i==1) d=v[i];
	}
	sort(v+1,v+1+n*m,arm);
	for(int i=1;i<=n*m;i++)
	{
		if(v[i]==d)
		{
			 d1=i;
			 break;
		 }
	}
	ax=d1/n;
	int y=d1%n;
	if(y!=0) ax++;
	if(ax%2==0)
	{
		ay=n-y+1;
	}
	else ay=y;
	if(y==0)
	{
		if(ax%2==0) ay=1;
		else ay=n;
	}
	cout<<ax<<" "<<ay;
	return 0; 
}
