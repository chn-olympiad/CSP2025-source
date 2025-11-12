#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 10;
const int M = 2e6 + 10;
int t, n, m, k, x, cnt, nd;
int fa[N], c[20], vis[N];
long long sum = 0;
struct edge
{
	int u, v, w;
} e[M];
bool cmp(edge x, edge y)
{
	return x. w < y. w;
}
int read()
{
	int x = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9')
	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x;
}
int find(int x)
{
	return (x == fa[x] ? fa[x] : find(fa[x]));
}
void kruscal()
{
	sort(e + 1, e + m + 1, cmp);
	for(int i = 1; i <= m; ++i)
	{
		int fa_u = find(e[i]. u), fa_v = find(e[i]. v);
		if(fa_u == fa_v) continue;
		fa[fa_u] = fa_v;
		if(e[i]. u > n && !vis[e[i]. u])
		{
			vis[e[i]. u] = 1;
			++nd;
		}
		sum += e[i]. w;
		if(++cnt > nd) return ;
//		printf("%d %d %d cnt: %d\n", e[i]. u, e[i]. v, e[i]. w, cnt);
	}
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	t = nd = n;
	for(int i = 1; i <= m; ++i)
	{
		e[i]. u = read(), e[i]. v = read(), e[i]. w = read();
	}
	for(int i = 1; i <= k; ++i)
	{
		c[++t] = read();
		for(int j = 1; j <= n; ++j)
		{
			x = read();
			e[++m] = (edge) {t, j, x};
		}
	}
	for(int i = 1; i <= t; ++i) fa[i] = i;
	kruscal();
	printf("%lld", sum);
	return 0;
}
