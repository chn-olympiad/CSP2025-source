#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	bool city[10001][10001];
	int road[10001][1000001],dp[100001],village[11][100001];
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		road[u][v]=w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>village[i][1];
		for(int j=0;j<n;j++)
			cin>>village[i][j+1];
	}
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
			{
				road[j][k]=min(road[j][k],village[i][j]+village[i][k]);
			}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(city[i][j]==true)
			{
				dp[i]=road[i][j];
				for(int k=j+1;k<=n;k++)
				{
					if(dp[i]<=road[i][k]+road[j][k])
						city[i][k]=false,city[j][k]=false;
					dp[i]=min(dp[i],road[i][k]+road[j][k]);
					city[i][j]=true;
				}
			}
		}
	}
	cout<<dp[n];
} 
