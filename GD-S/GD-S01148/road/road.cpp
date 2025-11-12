#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 5;
struct EDGE
{
	int from,to,val;
}E[MAXN];
int c[20],a[20][10005],fa[MAXN],siz[MAXN];
inline int Find(int x)
{
	if (fa[x] == x) return x;
	return fa[x] = Find(fa[x]);
}
inline void Merge(int u,int v)
{
	if (siz[u] > siz[v]) swap(u,v);
	fa[u] = v,siz[v] += siz[u];
}
inline bool cmp(const EDGE tmpa,const EDGE tmpb)
{
	return tmpa.val < tmpb.val;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,tot = 0;
	cin >> n >> m >> k;
	for (int i = 1,u,v,w; i <= m; i++)
	{
		cin >> u >> v >> w;
		E[++tot] = (EDGE){u,v,w};
	}
	for (int i = 1; i <= k; i++)
	{
		cin >> c[i];
		for (int j = 1; j <= n; j++) cin >> a[i][j],E[++tot] = (EDGE){n + i,j,a[i][j]};
	}
	for (int i = 1; i <= n + k; i++) fa[i] = i,siz[i] = 1;
	sort(E + 1,E + tot + 1,cmp);
	long long ans = 0;
	for (int i = 1,u,v; i <= tot; i++)
	{
		u = Find(E[i].from),v = Find(E[i].to);
		if (u == v) continue;
		Merge(u,v),ans += E[i].val;
	}
	cout << ans << '\n';
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
