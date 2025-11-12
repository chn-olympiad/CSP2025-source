#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
const int maxn=4e6+10;
int n,m,k;
int head[maxn];
int nxt[maxn];
int to[maxn];
int eval[maxn];
int pval[maxn];
int vis[maxn];
int dis[maxn];
int sum=0;
int cnt=0;
void add(int u,int v,int w)
{
	cnt++;
	to[cnt]=v;
	eval[cnt]=w;
	nxt[cnt]=head[u];
	head[u]=cnt;
}
priority_queue<P,vector<P>,greater<P> > q;
void dfs()
{
	for(int i=1;i<=n;i++) dis[i]=INT_MAX;
	dis[1]=1;
	q.push(P(0,1));
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=nxt[i])
		{
			int v=to[i];
			
			if(dis[v]>dis[u]+eval[i])
			{
				if(dis[v]==INT_MAX) sum+=eval[i];
				else sum-=dis[v]-dis[u]-eval[i];
				dis[v]=dis[u]+eval[i];
				q.push(P(dis[v],v));
			}
		}
	}
	
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++)
	{
		int csp;
		cin>>csp;
		pval[i+n]=csp;
		for(int j=1;j<=n;j++)
		{
			int w;
			cin>>w;
			add(i+n,j,w);
			add(j,i+n,w);
		}
	}
	dfs();
	cout<<sum;
	return 0;
}
