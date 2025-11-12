#include <bits/stdc++.h>
using namespace std;
struct s
{
	int a,b,c;
}t[100000];
int h[100000];
int g[10000][10000]; 
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,r;
	int min=100000000;
	cin>>n>>m>>r;
	int l;
	int c;
	
	for(int i=1;i<=n;i++)
	{
		cin>>t[i].a>>t[i].b>>t[i].c;
	}
	for(int i=1;i<=r;i++)
	{
		cin>>h[i];
		for(int j=1;j<=n;j++)
		{
			cin>>g[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(t[i].c<min)
		{
			min=t[i].c;
			l=i;
		}
	}
	min=1000000;
	for(int i=1;i<=n;i++)
	{
		if(t[i].b==t[l].b)
		{
			if(t[i].c<min&&i!=l)
			{
				min=t[i].c;
				c=i;
			}
		}
	}
	cout<<t[l].c+t[c].c+8;
}
