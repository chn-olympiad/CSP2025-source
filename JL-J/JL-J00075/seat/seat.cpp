#include<bits/stdc++.h>
using namespace std;
int s[105];
int a[15][15];
bool tmp(int x,int y)
{
	return x>=y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int r;
	cin>>r;
	int sum=0;
	for(int i=0;i<n*m-1;i++)
	{
		cin>>s[i];
		sum++;
	}
	s[n*m]=r;
	sort(s,s+n*m,tmp);
	int x=1;
	int y=1;
	int num=0;
	for(int i=0;i<n*m;i++)
	{
		if(y>=1&&y<=m)
		{
			a[y][x]=s[num];
			num++;
		}
		if(y>m)
		{
			if(x%2==0)
			{
				y=m-(y-m);
				x++;
			}
			else
			{
				y=y-m;
				x++;
			}
			a[y][x]=s[num];
			num++;
			
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[j][i]==r)
			{
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
}
