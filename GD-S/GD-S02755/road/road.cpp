#include <stdio.h>
#include <algorithm>
#define ll long long 
void read(int &x)
{
	x = 0;char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
}
inline int maxx(int x, int y) {return x > y ? x : y;}
constexpr int maxn = 1e6 + 10;
int n, m, k, fa[maxn];
struct Edge
{
	int u, v, w;
}edge[maxn];
int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
bool merge(int x, int y) {int u = find(x), v = find(y);if (u == v) return false;fa[u] = v;return true;}
int main()
{
	freopen("road.in", "r", stdin), freopen("road.out", "w", stdout);
	read(n), read(m), read(k);
	for (int i = 1;i <= n;i++) fa[i] = i;
	for (int i = 1;i <= m;i++)
		read(edge[i].u), read(edge[i].v), read(edge[i].w);
	std::sort(edge + 1, edge + 1 + m, [](Edge x, Edge y){return x.w < y.w;});
	ll ans = 0;
	for (int i = 1;i <= m;i++)
		if (merge(edge[i].u, edge[i].v))
			ans += edge[i].w;
	printf("%lld\n", ans);
	return 0;
}
