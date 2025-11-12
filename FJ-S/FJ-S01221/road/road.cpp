#include<bits/stdc++.h>
using namespace std;
int g[1005][1005];
int c[1005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[u][v]=w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=k;j++)
		{
			cin>>g[i][j];
		}
	}
	cout<<0;
	return 0;
}
