#include <ctime>
#include <cstdio>
#include <random>
#include <algorithm>
#define lowbit(x) ((x) & (-(x)))
#define inset(u) ((u) <= n || ((s >> ((u) - n - 1)) & 1))
template <typename _T>
inline void read(_T &x)
{
	x = 0;
	char c = getchar();
	while (c < '0' || c > '9')
		c = getchar();
	for (; c >= '0' && c <= '9'; c = getchar())
		x = (x << 3) + (x << 1) + (c & 15);
}
const int MAXN = 1e4 + 17, MAXM = 1.3e6 + 7;
std::mt19937 rnd(std::random_device{}());
int n, m, n1, starttime, fa[MAXN];
long long ans = 1e18, cst[MAXN];
struct Edge { int u, v, w; } e[MAXM];
inline int getfa(int u) { return fa[u] == u ? u : fa[u] = getfa(fa[u]); }
inline long long Kruskal(int s)
{
	int blk = __builtin_popcount(s) + n; long long res = 0;
	for (int i = 1; i <= n + n1; ++i)
		fa[i] = i;
	for (int i = 1, u, v; i <= m; ++i)
		if (inset(e[i].u) && inset(e[i].v) && (u = getfa(e[i].u)) != (v = getfa(e[i].v)) && (fa[u] = v, res += e[i].w, (--blk) == 1))
			break;
	return res + cst[s];
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	starttime = clock();
	read(n), read(m), read(n1);
	for (int i = 1; i <= m; ++i)
		read(e[i].u), read(e[i].v), read(e[i].w);
	for (int i = n + 1; i <= n + n1; ++i)
	{
		read(cst[1 << (i - n - 1)]);
		for (int j = 1, w; j <= n; ++j)
			read(w), e[++m] = {i, j, w};
	}
	std::sort(e + 1, e + m + 1, [&](const Edge &x, const Edge &y) { return x.w < y.w; });
	const int sV = (1 << n1) - 1;
	for (int s = 0; s <= sV; ++s)
		__builtin_popcount(s) != 1 && (cst[s] = cst[lowbit(s)] + cst[s & (s - 1)]);
	if (sV * m <= 100000000)
		for (int s = 0; s <= sV; ++s)
			ans = std::min(ans, Kruskal(s));
	else
		for (int s = 0; clock() - starttime < 0.85 * CLOCKS_PER_SEC; s = rnd() & sV)
			ans = std::min(ans, Kruskal(s));
	printf("%lld", ans);
	fclose(stdin), fclose(stdout);
	return 0;
}