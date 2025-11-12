#include<bits/stdc++.h>
using namespace std;
struct Edge
{
	int v,w;
};
struct Node
{
	int id,val;
	friend bool operator<(Node A,Node B)
	{
		return A.val>B.val;
	}
};
int U[1000010],V[1000010],W[1000010],E[10010],dis[10020],c[20],a[20][10010],n,m,k;
long long ans=LONG_LONG_MAX;
vector<Edge> e[10020];
bool st[20],vis[10020];
void prim()
{
	long long cnt=0;
	int N=n;
	for(int i=1;i<=k;i++)
	{
		e[n+i].clear();
		if(st[i])
		{
			N++;
			cnt+=c[i];
			for(int j=1;j<=n;j++) 
			{
				e[n+i].push_back({j,a[i][j]});
				e[a[i][j]].push_back({n+i,a[i][j]});
				E[a[i][j]]++;
			}
		}
	}
	priority_queue<Node> q;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	q.push({1,0});
	dis[1]=0;
	while(!q.empty())
	{
		int u=q.top().id;q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		N--;
		cnt+=dis[u];
		if(!N) break;
		for(auto z:e[u])
		{
			int v=z.v;
			int w=z.w;
			if(dis[v]>w)
			{
				dis[v]=w;
				q.push({v,w});
			}
		}
	}
	for(int i=1;i<=n;i++) 
	{
		for(int j=1;j<=E[i];j++)e[i].pop_back();
		E[i]=0;
	}
	ans=min(ans,cnt);
	return ;
}
void dfs(int x)
{
	if(x==k+1)
	{
		prim();
		return ;
	}
	st[x]=1;
	dfs(x+1);
	st[x]=0;
	dfs(x+1);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>U[i]>>V[i]>>W[i];
		e[U[i]].push_back({V[i],W[i]});
		e[V[i]].push_back({U[i],W[i]});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
