#include <bits/stdc++.h>
using namespace std;

struct node
{
	int u, v, w;
} d[1000005], e[100005];

bool cmp(node x, node y)
{
	if (x.w < y.w)
	{
		return true;
	}
	return false;
}

long long ans = 2e18;

int n, m, k, xx, yy, ttt, c[11], a[11][10005], f[10015];

bool v[11];

int cha(int x)
{
	if (f[x] == x)
	{
		return x;
	}
	return f[x] = cha(f[x]);
}

void dfs(int x, int cnt, long long sum)
{
	if (x > k)
	{
		if (sum >= ans)
		{
			return;
		}
		for (int i = 1; i <= n + k; i++)
		{
			f[i] = i;
		}
		ttt = 0;
		for (int i = 1, j; i <= k; i++)
		{
			if (v[i] == true)
			{
				for (j = 1; j <= n; j++)
				{
					e[++ttt].u = j, e[ttt].v = n + i;
					e[ttt].w = a[i][j];
				}
			}
		}
		if (cnt != 0)
		{
			sort(e + 1, e + ttt + 1, cmp);
		}
		for (int i = 1, j = 1; i <= m || j <= ttt; )
		{
			if (i <= m && j <= ttt)
			{
				if (d[i].w <= e[j].w)
				{
					xx = cha(d[i].u), yy = cha(d[i].v);
					if (xx != yy)
					{
						f[xx] = yy;
						sum += d[i].w;
					}
					i++;
				}
				else
				{
					xx = cha(e[j].u), yy = cha(e[j].v);
					if (xx != yy)
					{
						f[xx] = yy;
						sum += e[j].w;
					}
					j++;
				}
			}
			else if (i <= m)
			{
				xx = cha(d[i].u), yy = cha(d[i].v);
				if (xx != yy)
				{
					f[xx] = yy;
					sum += d[i].w;
				}
				i++;
			}
			else
			{
				xx = cha(e[j].u), yy = cha(e[j].v);
				if (xx != yy)
				{
					f[xx] = yy;
					sum += e[j].w;
				}
				j++;
			}
			if (sum >= ans)
			{
				return;
			}
		}
		ans = min(ans, sum);
		return;
	}
	v[x] = false;
	dfs(x + 1, cnt, sum);
	v[x] = true;
	dfs(x + 1, cnt + 1, sum + c[x]);
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &d[i].u, &d[i].v, &d[i].w);
	}
	sort(d + 1, d + m + 1, cmp);
	for (int i = 1, j; i <= k; i++)
	{
		scanf("%d", &c[i]);
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	dfs(1, 0, 0);
	printf("%lld\n", ans);
	return 0;
}
