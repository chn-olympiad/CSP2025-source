#include <bits/stdc++.h>
using namespace std;
int dis[1005];
bool vis[1005];
struct node{
	int v,w;	
};
int ans=0;
vector<node> e[1005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			int mini=0;
			for(int j=1;j<=n;j++)
			{
				if(!vis[j]&&dis[j]<dis[mini])
					mini=j;
			}
			if(mini==0) break;
			vis[mini]=1;
			for(int j=0;j<e[mini].size();j++)
			{
				if(dis[e[mini][j].v]>e[mini][j].w+dis[mini])
					dis[e[mini][j].v]=e[mini][j].w+dis[mini];
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			ans+=dis[i];
		cout<<ans;
	}
	return 0;	
}