#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 8, K = 20, T = 1e4 + 20, PWK = 1024;

namespace dsu
{

int fat[N], siz[N];

void init(int n)
{
	memset(fat, 0, sizeof(int) * (n + 2));
	fill(siz, siz + n + 2, 1);
}

int getrt(int x)
{ return !fat[x] ? x : (fat[x] = getrt(fat[x])); };

bool merge(int x, int y)
{
	x = getrt(x), y = getrt(y);
	if(x == y)
		return false;
	if(siz[x] > siz[y])
		swap(x, y);
	fat[x] = y;
	siz[y] += siz[x];
	return true;
}

}

struct edge
{ int w, u, v; };

edge es[N];

void sort_edge(int n)
{
	sort(es + 1, es + 1 + n, [](const edge& x, const edge& y) { return x.w < y.w; });
}

inline ll calc(int n, int m, edge tre[])
{
	ll res = 0;
	int tot = 0;
	sort_edge(m);
	dsu::init(n);
	for(int i = 1; i <= m && tot < n - 1; i++)
	{
		int u = es[i].u, v = es[i].v, w = es[i].w;
		if(dsu::merge(u, v))
		{
			res += w;
			++tot;
			tre[tot] = es[i];
		}
	}
	return res;
}

edge tre[PWK][T];

int a[K][N];

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= m; i++)
		scanf("%d%d%d", &es[i].u, &es[i].v, &es[i].w);
	for(int i = 1; i <= k; i++)
		for(int j = 0; j <= n; j++)
			scanf("%d", &a[i][j]);
	ll ans = calc(n, m, tre[0]);
	for(int s = 1; s < (1 << k); s++)
	{
		int lb = s & -s;
		memcpy(es, tre[s ^ lb], sizeof(edge) * (n + k + 2));
		ll res = 0;
		for(int j = 1; j <= k; j++)
			if((s >> (j - 1)) & 1)
				res += a[j][0];
		int cn = n + __builtin_popcount(s), tot = cn - 2;
		{
			int j = __lg(lb) + 1;
			for(int i = 1; i <= n; i++)
			{
				++tot;
				es[tot].u = cn, es[tot].v = i, es[tot].w = a[j][i];
			}
		}
		res += calc(cn, tot, tre[s]);
		ans = min(ans, res);
	}
	printf("%lld\n", ans);
	return 0;
}