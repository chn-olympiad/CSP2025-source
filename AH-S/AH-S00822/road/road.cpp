#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 4000010;
const long long INF = 1e18;

int n, m, k;
int c[N];
int h[N], e[N], ne[N], w[N], idx;
int fa[N], p[15][10010];
struct node
{
	int u, v, w;
} E[N];

void add(int u, int v, int c)
{
	e[idx] = v, ne[idx] = h[u], w[idx] = c, h[u] = idx ++;
	return;
}

int find(int u)
{
	if(fa[u] != u) return fa[u] = find(fa[u]);
	else return fa[u];
}

bool cmp(node x, node y)
{
	return x.w < y.w;
}

long long work(int s, int n, int m)
{
	int tot = 0; long long res = 0;
	for (int i = 0; i < k; i ++ )
	{
		if((s >> i) & 1)
		{
			res += c[i + 1]; tot ++;
			for (int j = 1; j <= n; j ++ ) E[ ++ m] = {j, n + tot, p[i + 1][j]};
		}
	}
	n += tot;
	
	for (int i = 1; i <= n; i ++ ) fa[i] = i;
	sort(E + 1, E + m + 1, cmp);
	
	int cnt = 0;
	for (int i = 1; i <= m; i ++ )
	{
		int u = E[i].u, v = E[i].v, c = E[i].w;
		int fu = find(u), fv = find(v);
		if(fu != fv)
		{
			res += 1ll * c;
			cnt ++;
			fa[fu] = fv;
		}
		if(cnt == n - 1) break;
	}
	return res;
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	memset(h, -1, sizeof h);
	
	scanf("%d%d%d", &n, &m, &k); 
	for (int i = 1; i <= m; i ++ )
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		
		add(u, v, w);
		add(v, u, w);
		E[i] = {u, v, w};
	}
	bool flagA = 1;
	for (int i = 1; i <= k; i ++  )
	{
		scanf("%d", &c[i]); if(c[i] != 0) flagA = 0;
		for (int j = 1; j <= n; j ++ ) scanf("%d", &p[i][j]);
	}
	if(k == 0)
	{
		for (int i = 1; i <= n; i ++ ) fa[i] = i;
		sort(E + 1, E + m + 1, cmp);
		
		long long ans = 0; int cnt = 0;
		for (int i = 1; i <= m; i ++ )
		{
			int u = E[i].u, v = E[i].v, c = E[i].w;
			int fu = find(u), fv = find(v);
			if(fu != fv)
			{
				ans += 1ll * c;
				cnt ++;
				fa[fu] = fv;
			}
			if(cnt == n - 1) break;
		}
		printf("%lld\n", ans);
		return 0;
	}
	else if(flagA)
	{
		for (int i = 1; i <= k; i ++  )
		{
			for (int j = 1; j <= n; j ++ )
			{
				E[ ++ m] = {j, n + i, p[i][j]};
			}
		}
		n += k;
		for (int i = 1; i <= n; i ++ ) fa[i] = i;
		sort(E + 1, E + m + 1, cmp);
		
		long long ans = 0; int cnt = 0;
		for (int i = 1; i <= m; i ++ )
		{
			int u = E[i].u, v = E[i].v, c = E[i].w;
			int fu = find(u), fv = find(v);
			if(fu != fv)
			{
				ans += 1ll * c;
				cnt ++;
				fa[fu] = fv;
			}
			if(cnt == n - 1) break;
		}
		printf("%lld\n", ans);
		return 0;
	}
	
	long long ans = INF;
	for (int s = 0; s < (1 << k); s ++ )
	{
		ans = min(ans, work(s, n, m));
	}
	printf("%lld\n", ans);
	
	return 0;
}
