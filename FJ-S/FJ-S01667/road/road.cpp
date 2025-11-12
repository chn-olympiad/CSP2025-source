#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef pair<LL, int> PII;
const int N = 1e4 + 10;
const int M = 2e6 + 10;
int n, m, k, fa[N], p;
LL c[N], a[20][N], ans = 1e18;
bool flag = true;

struct Node
{
	int u, v;
	LL w;
	bool operator< (const Node & t) const
	{
		return w < t.w;
	}
}g[M];

int find(int x)
{
	if(fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1;i <= m; ++ i)
		scanf("%d%d%lld", &g[i].u, &g[i].v, &g[i].w);
	for(int i = 1;i <= k; ++ i)
	{
		scanf("%lld", &c[i]);
		if(c[i] != 0) flag = false;
		for(int j = 1;j <= n; ++ j)
		{
			scanf("%lld", &a[i][j]);
			if(a[i][j] != 0) flag = false;
		}
	}
	if(flag)
	{
		printf("0");
		return 0;
	}
	int K = (1 << k) - 1;
	for(int i = 0;i <= K; ++ i)
	{
		for(int j = 1;j <= n + k; ++ j)
			fa[j] = j;
		p = 0;
		int num = i;
		LL sum = 0;
		for(int j = 1;j <= k; ++ j)
		{
			if(num & 1)
			{
				for(int x = 1;x <= n; ++ x)
					g[( ++ p) + m] = {n + j, x, a[j][x]};
				sum += c[j];
			}
			num >>= 1;
		}
		sort(g + 1, g + m + p + 1);
		for(int j = 1;j <= m + p; ++ j)
		{
			if(find(g[j].u) != find(g[j].v))
				sum += g[j].w, fa[find(g[j].u)] = find(g[j].v);
		}
//		cout << ans << " " << sum << endl;
		ans = min(ans, sum);
	}
	printf("%lld", ans);
	return 0;
}
