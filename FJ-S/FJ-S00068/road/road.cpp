#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M = 1e6+5,K = 15,N = 1e4+100;
int n,m,k,c[K],ans = 0x3f3f3f3f;
// Edge
int cnt = 0;
struct Edge
{
	int u,v,w,p;
}e[2*M];
bool operator < (Edge a,Edge b)
{
	return a.w < b.w;
}
inline void add(int u,int v,int w,int p)
{
	e[++cnt] = Edge{u,v,w,p};
}
// Krusal
int fa[N],siz[N];
inline void init()
{
	for(int i=1;i<=n;i++)
	{
		fa[i] = i;
		siz[i] = 1;
	}
	for(int j=1;j<=k;j++)
	{
		fa[j+n] = j+n;
		siz[j+n] = 0;
	}
}
inline int find(int x)
{
	if(fa[x] == x) return x;
	int fath = find(fa[x]);
	return fa[x] = fath;
}
inline void merge(int x,int y)
{
	int fx = find(x),fy = find(y);
	fa[fx] = fy;
	siz[fy] += siz[fx];
	siz[fx] = 0;
}
// sol
int is[K];
void sol()
{
	init();
	int sum = 0;
	for(int i=1;i<=k;i++)
		if(is[i]) sum += c[i];
	for(int i=1;i<=cnt;i++)
	{
		int fx = find(e[i].u),fy = find(e[i].v);
		if(fx == fy || !is[e[i].p]) continue;
		fa[fx] = fy;
		siz[fy] += siz[fx];
		siz[fx] = 0;
		sum += e[i].w;
		if(siz[fy] == n) 
		{
			ans = min(ans,sum);
			return;	
		} 
	}
}
// DFS
void dfs(int p)
{
	if(p > k)
	{
		sol();
		return;
	}
	is[p] = 1;
	dfs(p+1);
	is[p] = 0;
	dfs(p+1);
	return;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		add(u,v,w,0);
	}
	for(int j=1;j<=k;j++)
	{
		cin >> c[j];
		for(int i=1;i<=n;i++)
		{
			int w;
			cin >> w;
			add(j+n,i,w,j);
		}
	}
	sort(e+1,e+1+cnt);
	is[0] = 1;
	dfs(1);
	cout << ans;
	return 0;
}
