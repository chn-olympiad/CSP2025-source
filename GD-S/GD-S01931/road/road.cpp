#include <bits/stdc++.h>
using namespace std;

int n, m, k, w[1000005], c[15];
long long f[1005][1005], a[15][1005];
long long ans = 0;
struct edge
{
	int v, w;
};

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	memset(f, 0x3f, sizeof f);
	for (int i = 1; i <= n; i++)
		f[i][i] = 0;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d%d%d", &u, &v, &w[i]);
		f[v][u] = f[u][v] = min(f[u][v], 1ll * w[i]);
		ans += 1ll * w[i];
	}
	for (int i = 1; i <= k; i++)
	{
		scanf("%d", &c[i]);
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	}
	if (k == 0)
	{
		printf("%lld\n", ans);
		return 0;
	}
	for (int K = 1; K <= n; K++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				f[i][j] = min(f[i][j], f[i][K] + f[K][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int l = 1; l <= k; l++)
				f[i][j] = min(f[i][j], a[l][i] + a[l][j]);
	ans = 0;
	for (int i = 1; i <= n; i++)
	{
		long long minn = 1e18;
		for (int j = 1; j <= n; j++)
			if (i != j)
				minn = min(f[i][j], minn);
		ans += minn;
	}
	printf("%lld", ans);
	return 0;
}
