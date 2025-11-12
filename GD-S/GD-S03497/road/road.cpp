#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
#define fi first
#define se second
const int N = 1e4+100,M = 1e6+10,INF = 1e9+10;
bool Mst;
struct edge
{
	int u,v,w;
}a[M];
int n,m,k,cnt,mark[N],ans = INF,nd[N],c[N];
vector<PII>e0[N],e[N];
priority_queue<PII,vector<PII>,greater<PII> >q;
bool Med;
void work(int tmp)
{
	int res = tmp;
	for(int i = 0;i<(int)e[1].size();i++)
		q.push({e[1][i].se,e[1][i].fi});
	mark[1] = 1;
	while(!q.empty())
	{
		int v = q.top().se,w = q.top().fi;
		q.pop();
		if(mark[v])
			continue;
		mark[v] = 1;
		res+=w;
		for(int i = 0;i<(int)e[v].size();i++)
			if(!mark[e[v][i].fi])
				q.push({e[v][i].se,e[v][i].fi});
	}
	ans = min(ans,res);
}
void dfs(int x)
{
	if(x==k+1)
	{
		for(int i = 1;i<=n+k;i++)
			e[i].clear();
		for(int i = 1;i<=m;i++)
		{
			int u = a[i].u,v = a[i].v,w = a[i].w;
			e[u].push_back({v,w});
			e[v].push_back({u,w});
		}
		int tmp = 0;
		for(int i = 1;i<=cnt;i++)
		{
			tmp+=c[nd[i]];
			for(int j = 0;j<(int)e0[nd[i]].size();j++)
			{
				int v = e0[nd[i]][j].fi,w = e0[nd[i]][j].se;
				e[v].push_back({nd[i],w});
				e[nd[i]].push_back({v,w});
			}
		}
		memset(mark,0,sizeof(mark));
		work(tmp);
		return;
	}
	dfs(x+1);
	nd[++cnt] = x+n;
	dfs(x+1);
	cnt--;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i = 1;i<=m;i++)
		scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
	for(int i = 1;i<=k;i++)
	{
		scanf("%lld",&c[i+n]);
		for(int j = 1;j<=n;j++)
		{
			int w;
			scanf("%lld",&w);
			e0[i+n].push_back({j,w});
		}
	}
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}
/*4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4*/
