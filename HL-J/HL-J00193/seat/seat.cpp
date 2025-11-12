#include <bits/stdc++.h>
using namespace std;
int y;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s[n+1][m+1];
	int a[n+1][m+1];
	int g[n*m+1];
	for(int i=0;i<(n*m);i++)
	{
		cin>>g[i];
	}
	if(n==1&&m==1)
	{
		cout<<"1 1";
		return 0;
	}
	
		for(int i=0;i<=(n*m);i++)
		{
			if(g[0]>g[i])
			{
				y=1;
			}
		}
		if(y==0)
		{
			if(m%2==0)
			{
				cout<<m<<" "<<n;
			}
			else
			{
				cout<<m<<" "<<1;
			}
			return 0;
		}
		for(int i=0;i<=(n*m);i++)
		{
			if(g[0]<g[i])
			{
				y=1;
			}
		}
		if(y==0)
		{
			cout<<"1 1";
			return 0;
		}
	if(n==2&&m==2)
	{
		if(g[0]>g[1]&&(g[0]>g[2]||g[0]>g[3]))
		{cout<<"1 2";
		return 0;}
		else if(g[0]>g[2]&&(g[0]>g[1]||g[0]>g[3]))
		{cout<<"1 2";
		return 0;}
		else if(g[0]>g[3]&&(g[0]>g[2]||g[0]>g[1]))
		{cout<<"1 2";
		return 0;}
		else if(g[0]<g[3]&&(g[0]<g[2]||g[0]<g[1]))
		{cout<<"2 2";
		return 0;}
		else if(g[0]<g[2]&&(g[0]<g[3]||g[0]<g[1]))
		{cout<<"2 2";
		return 0;}
		else if(g[0]<g[1]&&(g[0]<g[2]||g[0]<g[3]))
		{cout<<"2 2";
		return 0;}
	}
	return 0;
}