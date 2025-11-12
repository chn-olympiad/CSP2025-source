#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+20;
int n,m,k;
struct node
{
	int qv,quan;
};
vector<node> g[MAXN];
int vis[MAXN];
int csh[15];
int t;
long long ans=1e9;
void bfs(int x,int p,long long cnt)
{
	if(x>n)
	{
		p--;
		cnt+=csh[x-n];
	}
	if(vis[x]) return;
	if(p==n)
	{
		ans=min(ans,cnt);
		return;
	}
	queue<node> q;
	for(node i:g[x])
	{
		q.push(i);
	}
	vis[x]=1;
	while(!q.empty())
	{
		node qp=q.front();
		q.pop();
		bfs(qp.qv,p+1,cnt+qp.quan);
	}
	vis[x]=0;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++)
	{
		int l;
		cin>>l;
		csh[i]=l;
		t=n+i;
		for(int j=1;j<=n;j++)
		{
			int w;
			scanf("%d",&w);
			g[j].push_back({t,w});
			g[t].push_back({j,w});
		}
	}
	bfs(1,1,0);
	printf("%d",ans);
	return 0;
}
