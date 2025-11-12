#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e6 + 10;
struct Edge{int u,v,w;}E[maxn],G[maxn],tmp[maxn];
int fa[maxn],n,m,k,ans = 1e18,cnt;
int c[maxn],a[15][maxn];
int Find(int u){return u == fa[u] ? u : fa[u] = Find(fa[u]);};
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++)cin >> E[i].u >> E[i].v >> E[i].w;
	sort(E + 1,E + m + 1,[&](const Edge &u,const Edge &v){return u.w < v.w;});
	for(int i = 1;i <= n;i++)fa[i] = i;
	for(int i = 1;i <= m;i++)
	{
		if(Find(E[i].u) != Find(E[i].v))
		{
			fa[Find(E[i].u)] = Find(E[i].v);
			G[++cnt] = {E[i].u,E[i].v,E[i].w};
		}
	}
	for(int i = 0;i < k;i++)
	{
		cin >> c[i];
		for(int j = 1;j <= n;j++)cin >> a[i][j];
	}
	for(int S = 0;S < 1 << k;S++)
	{
		int res = 0;cnt = n - 1;
		for(int i = 1;i <= cnt;i++)tmp[i] = G[i];
		for(int i = 0;i < k;i++)
		{
			if(S & (1 << i))
			{
				res += c[i];
				for(int j = 1;j <= n;j++)G[++cnt] = {n + 1 + i,j,a[i][j]};
			}
		}
		sort(G + 1,G + cnt + 1,[&](const Edge &u,const Edge &v){return u.w < v.w;});
		for(int i = 1;i <= n + k;i++)fa[i] = i;
		for(int i = 1;i <= cnt;i++)
		{
			if(Find(G[i].u) != Find(G[i].v))
			{
				fa[Find(G[i].v)] = Find(G[i].u);
				res += G[i].w;
			}
		}
		ans = min(ans,res);
		for(int i = 1;i < n;i++)G[i] = tmp[i];
	}
	cout << ans;
	return 0;
}

/*
没有意识到2^k nk log nk其实远远跑不满.jpg。 
*/
