#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	unsigned int n,m,k,ans=0;
	cin >> n >> m >> k;
	unsigned int dis[n+1][n+1],pdis[n+1][n+1],p[n+1],pdist[n+1],vis[n+1];
	memset(vis,0,n+1);
	for(unsigned int i=1;i<=n;++i)
	{
		for(unsigned int j=1;j<=n;++j)
		{
			dis[i][j]=0x7f7f7f7f;
			pdis[i][j]=0x7f7f7f7f;
		}
		dist[i]=0x7f7f7f7f;
		pdist[i]=0x7f7f7f7f;
	}
	for(unsigned int i=1;i<=m;++i)
	{
		int u,v,w;
		cin >> u >> v >> w;
		dis[u][v]=dis[v][u]=w;
	}
	dist[1]=0;
	pdist[1]=0;
	for(unsigned int i=1;i<=n;++i)
	{
		for(unsigned int j=1;j<=n;++j)
		{
			if(dist[i]+dis[i][j]<dist[j])
			{
				dist[j]=dis[i][j]+dist[i];
			}
		}
	}
	for(unsigned int i=1;i<=k;++i)
	{
		int cost;
		cin >> cost;
		p[i]=cost;
		for(int j=1;j<=n;++j)
		{
			int w;
			cin >> w;
			pdis[i][j]=pdis[j][i]=w;
		}
	}
	for(unsigned int i=1;i<=n;++i)
	{
		for(unsigned int j=1;j<=n;++j)
		{
			if(pdist[i]+pdis[i][j]<pdist[j])
			{
				pdist[j]=pdis[i][j]+pdist[i];
			}
		}
	}
	for(unsigned int i=1;i<=n;++i)
	{
		for(unsigned int j=1;j<=n;++j)
		{
			if(dis[i][j]==0x7f7f7f7f&&pdis[i][j]!=0x7f7f7f7f)
			{
				if(vis[i])
				{
					ans+=pdis[i][j];
				}
				else if(vis[j])
				{
					ans+=pdis[i][j];
				}
				else
				{
					if(p[i]<p[j])
					{
						vis[i]=1;
						ans+=p[i];
						ans+=pdis[i][j];
					}
					else
					{
						vis[j]=1;
						ans+=p[j];
						ans+=pdis[i][j];
					}
				}
			}
		}
	}
	cout << rand() << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
