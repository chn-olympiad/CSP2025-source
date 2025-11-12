//GZ-S00144 幸进尧 贵阳市云城中学
#include <bits/stdc++.h>
using namespace std;

int read()
{
	static constexpr int S = 1 << 20;
	static char b[S], *p1, *p2;
	#define gc() (p1 == p2 && (p2 = (p1 = b) + fread(b, 1, S, stdin), p1 == p2) ? EOF : *p1++)
	#define dg(c) (c >= '0' && c <= '9')
	int x = 0, c = gc();
	while (!dg(c)) c = gc();
	while (dg(c)) x = x * 10 + (c & 15), c = gc();
	return x;
	#undef gc
	#undef dg
}

typedef long long LL;
constexpr int N = 1e4 + 15, M = 1e6 + 5, K = 12, L = 1 << 10 | 5;

int n, m, k;
array <int, 3> edg[M];
array <int, 3> ext[K][N];
vector <array <int, 3>> tre[L];
LL sum[L];
int par[N], siz[N];

void init(int l)
{
	for (int i = 1; i <= l; i ++)
		par[i] = i, siz[i] = 1;
}

int find(int x)
{
	while (x != par[x]) x = par[x] = par[par[x]];
	return x;
}

int merge(int x, int y)
{
	x = find(x), y = find(y);
	if (x == y) return 1;
	if (siz[x] > siz[y]) swap(x, y);
	par[x] = y, siz[y] += siz[x];
	return 0;
}

void kruskalInit()
{
	init(n);
	for (int i = 1; i <= m; i ++)
		if (!merge(edg[i][1], edg[i][2]))
			sum[0] += edg[i][0], tre[0].push_back(edg[i]);
}

void kruskalExtn(int sta, int ano)
{
	init(n + k);
	int i = 0, j = 1;
	int nxt = sta | 1 << (ano - 1);
	LL cur = 0; vector <array <int, 3>> now;
	int tot = n + __builtin_popcount(sta) + 1;
	while (tot > 1)
	{
		int w, u, v;
		if (i < tre[sta].size() && tre[sta][i][0] < ext[ano][j][0])
		{
			w = tre[sta][i][0];
			u = tre[sta][i][1];
			v = tre[sta][i][2];
			++i;
		}
		else
		{
			w = ext[ano][j][0];
			u = ext[ano][j][1];
			v = ext[ano][j][2];
			++j;
		}
		if (merge(u, v)) continue;
		--tot, cur += w, now.push_back({w, u, v});
	}
	if (cur < sum[nxt]) sum[nxt] = cur, tre[nxt] = now;
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	n = read(), m = read(), k = read();
	for (int i = 1; i <= m; i ++)
	{
		int w, u, v;
		u = read(), v = read(), w = read();
		edg[i] = {w, u, v};
	}
	sort(edg + 1, edg + m + 1);
	for (int i = 1; i <= k; i ++)
	{
		ext[i][0] = {read(), 0, 0};
		for (int j = 1; j <= n; j ++)
			ext[i][j] = {read(), j, n + i};
		sort(ext[i] + 1, ext[i] + n + 1);
	}
	
	LL res = 1e18; kruskalInit();
	for (int i = 1; i < 1 << k; i ++) sum[i] = 1e18;
	for (int i = 0; i < 1 << k; i ++)
	{
		LL cur = 0;
		for (int j = 1; j <= k; j ++)
			if (i >> (j - 1) & 1)
				cur += ext[j][0][0];
		res = min(res, cur + sum[i]);
		for (int j = 1; j <= k; j ++)
			if (~i >> (j - 1) & 1)
				kruskalExtn(i, j);
		tre[i] = {};
	}
	printf("%lld\n", res);
	
	return 0;
}
