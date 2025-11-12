#include <bits/stdc++.h>
using namespace std;

struct r
{
	int p,c;
};
vector<r> edge[10005];
int cost[10005],vis[10005];

void bfs(int i)
{
	vis[i]=1;
	for(int j = 0;j<edge[i].size();j++)
	{
		if(vis[i]!=1)
		{
			cost[edge[i][j].p]=min(cost[i]+edge[i][j].c,cost[edge[i][j].p]);	
			vis[j]=1;
			bfs(j);
			vis[j]=0;
		}
	}
	return ;
}


int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(cost,0x7f,sizeof(cost));
	int n,m,k;
	cin>>n>>m>>k;
	for(int i = 1;i<=m;i++)
	{
		int c,u,v;
		cin>>c>>u>>v;
		edge[u].push_back({v,c});
		edge[u].push_back({u,c});
	}
	bfs(1);
	int mx = 0;
	for(int i = 1;i<=n;i++)if(cost[i]>mx)mx=cost[i];
	cout<<mx;
}
