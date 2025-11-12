#include <stdio.h>
#include <algorithm>
#include <vector>
int n, m, k, c[10];
struct road
{
	int u, v, w;
	bool operator<(const road& other)const
	{
		return w < other.w;
	}
} r[1000005], er[10][10005];
std::vector<road> realRoad[1024];
int rcnt;
namespace DSU
{
	int fa[10015], siz[10015];
	void init(void)
	{
		for (int i = 1; i <= n + k; ++i)
		{
			fa[i] = i;
			siz[i] = 1;
		}
	}
	int find(int x)
	{
		return fa[x] == x ? x : fa[x] = find(fa[x]);
	}
	bool merge(int x, int y)
	{
		x = find(x);
		y = find(y);
		if (x == y)
			return false;
		if (siz[x] < siz[y])
			x ^= y ^= x ^= y;
		fa[y] = x;
		siz[x] += siz[y];
		return true;
	}
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; ++i)
		scanf("%d%d%d", &r[i].u, &r[i].v, &r[i].w);
	std::sort(r + 1, r + m + 1);
	for (int i = 0; i < k; ++i)
	{
		scanf("%d", c + i);
		for (int j = 1, w; j <= n; ++j)
		{
			scanf("%d", &w);
			er[i][j] = { n + i + 1, j, w };
		}
		std::sort(er[i] + 1, er[i] + n + 1);
	}
	DSU::init();
	for (int i = 1; i <= m; ++i)
		if (DSU::merge(r[i].u, r[i].v))
			realRoad[0].push_back(r[i]);
	for (int msk = 1; msk < (1 << k); ++msk)
	{
		int now = __builtin_ctz(msk);
		int last = msk ^ (1 << now);
		std::vector<road>::iterator i = realRoad[last].begin();
		int j = 1;
		DSU::init();
		while (i != realRoad[last].end() || j != n + 1)
			if (i != realRoad[last].end() && (j == n + 1 || *i < er[now][j]))
			{
				if (DSU::merge(i->u, i->v))
					realRoad[msk].push_back(*i);
				++i;
			}
			else
			{
				if (DSU::merge(er[now][j].u, er[now][j].v))
					realRoad[msk].push_back(er[now][j]);
				++j;
			}
	}
	long long ans = 1e18;
	for (int msk = 0; msk < (1 << k); ++msk)
	{
		long long sum = 0;
		for (int i = 0; i < k; ++i)
			if ((msk >> i) & 1)
				sum += c[i];
		for (road x : realRoad[msk])
			sum += x.w;
		if (sum < ans)
			ans = sum;
	}
	printf("%lld\n", ans);
	return 0;
}