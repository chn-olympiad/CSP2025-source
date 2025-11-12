#include<bits/stdc++.h>
using namespace std;
int n,m,k,s,a[1010][1010],x,y,z;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[i][j]=0x3f3f3f3f;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		a[x][y]=z;
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
	/*
	4 4 2
	1 4 6
	2 3 7
	4 2 5
	4 3 4
	*/
	cout<<a[1][n];
	//Ren5Jie4Di4Ling5%
	return 0;
}
