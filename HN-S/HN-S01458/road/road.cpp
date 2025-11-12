#include <algorithm>
#include <cstdio>
#include <array>
#include <cstring>

namespace Fujiwara
{
using std::sort;
using ll = long long;
const int N = 1e6 + 5;

int n, m, k;
struct Edge
{
	ll w;
	int u, v;
	bool operator<(const Edge& nbr) const
	{
		return w < nbr.w;
	}
} e[N];

int f[N];
static int fd(int x)
{
	return f[x] == x ? x : f[x] = fd(f[x]);
}

static int Azusa()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; ++i)
		scanf("%d%d%lld", &e[i].u, &e[i].v, &e[i].w);

	ll res = 0;
	sort(e + 1, e + m + 1);
	for (int i = 1; i <= n; ++i)
		f[i] = i;
	for (int i = 1, cnt = 0; i <= m; ++i)
	{
		int u = fd(e[i].u), v = fd(e[i].v);
		if (u != v)
		{
			++cnt;
			f[u] = v;
			res += e[i].w;
		}
	}
	printf("%lld\n", res);
	return 0;
}
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	return Fujiwara::Azusa();
}