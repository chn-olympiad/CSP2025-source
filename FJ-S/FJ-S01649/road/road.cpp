#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int inf=0x3f3f3f3f;
const ll INF=1e16;
const int N=1e4+10;
unsigned int dis[N][N];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dis[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++)
	{
		int u,v,w;cin>>u>>v>>w;
		dis[u][v]=w;
		dis[v][u]=w;
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	cout<<dis[1][n];

	return 0;
}

