#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll inf = 1e18;

namespace IO
{
	char ch;
	inline void read() {}
	template<class T1, class... T2>
	inline void read(T1& num1, T2&... num2)
	{
		num1 = 0; ch = getchar();
		for (; !isdigit(ch); ch = getchar());
		for (; isdigit(ch); ch = getchar())
			num1 = num1 * 10 + (ch ^ '0');
		read(num2...);
	}
}
using IO::read;

const int N = 2e4 + 5;
const int M = 5e6 + 5;
const int K = 15;

int n, m, k, lim;

ll a[K][N], c[K];

bool choose[N], vis[N];

struct disjoint
{
	int fath[N];
	inline int find(int x)
	{
		return fath[x] == x ? x : (fath[x] = find(fath[x]));
	}
}dsu;

struct edge
{
	int u, v; ll w;
	inline bool operator<(const edge& mem) const
	{
		return w < mem.w;
	}
}e[M], bck[M];

int tot;
inline void kruskal()
{
	sort(e + 1, e + 1 + m);
	for (int i = 1; i <= n; ++i)
	{
		dsu.fath[i] = i;
	}
	int u, v;
	for (int i = 1; i <= m; ++i)
	{
		u = dsu.find(e[i].u);
		v = dsu.find(e[i].v);
		if (u == v) continue;
		bck[++tot] = e[i];
		dsu.fath[u] = v;
	}
}

ll ans, crt, dist[N];

inline void solve()
{
	int crtedges = n - 1;
	int ntot = 0; crt = 0;
	for (int i = 1; i <= n + k; ++i)
	{
		dsu.fath[i] = i;
	}
	for (int i = 1; i <= tot; ++i)
	{
		e[++ntot] = bck[i];
	}
	for (int i = 1; i <= k; ++i)
	{
		if (choose[i + n])
		{
			crt += c[i]; ++crtedges;
			for (int j = 1; j <= n; ++j)
			{
				e[++ntot] = {n + i, j, a[i][j]};
			}
		}
	}
	sort(e + 1, e + 1 + ntot);
	for (int i = 1; crtedges; ++i)
	{
		int u = dsu.find(e[i].u);
		int v = dsu.find(e[i].v);
		if (u == v) continue;
		crt += e[i].w;
		dsu.fath[u] = v;
		--crtedges;
	}
	ans = min(ans, crt);
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	dist[0] = inf;
	ans = inf;
	
	int u, v; ll w;
	read(n, m, k);
	
	for (int i = 1; i <= m; ++i)
	{
		read(e[i].u, e[i].v, e[i].w);
	}
	
	kruskal();
	
	for (int i = 1; i <= k; ++i)
	{
		read(c[i]);
		for (int j = 1; j <= n; ++j)
		{
			read(a[i][j]);
		}
	}
	
	lim = 1 << k;
	for (int s = 0; s < lim; ++s)
	{
		crt = 0;
		for (int i = 0; i < k; ++i)
		{
			if (s >> i & 1)
			{
				choose[n + i + 1] = true;
			}
			else
			{
				choose[n + i + 1] = false;
			}
		}
		solve();
	}
	
	printf("%lld", ans);
	
	return 0;
}
