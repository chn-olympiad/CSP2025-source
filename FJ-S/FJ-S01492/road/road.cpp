#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
const int M = 5e6 + 10;

struct Node {
	int u, v, w;
	bool operator<(Node a) const
	{
		return w < a.w;
	}
}edge[M];

int d[10][N], fa[N], n, m, k;

long long ans, s, mi;

vector<pair<int, int> > dg[N];

inline int fnd(int x)
{
	if (fa[x] == x)
	{
		return x;
	}
	return fa[x] = fnd(fa[x]);
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
	{
		fa[i] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
	}
	if (k == 0)
	{
		sort(edge + 1, edge + 1 + m);
		for (int i = 1; i <= m; i++)
		{
			int f1 = fnd(edge[i].u);
			int f2 = fnd(edge[i].v);
			if (f1 != f2)
			{
				ans += edge[i].w;
				fa[f1] = f2;
			}
		}
	}
	else
	{
		for (int i = 1; i <= k; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				scanf("%d", &d[i][j]);
			}
		}
		sort(edge + 1, edge + 1 + m);
		for (int i = 1; i <= m; i++)
		{
			int f1 = fnd(edge[i].u);
			int f2 = fnd(edge[i].v);
			if (f1 != f2)
			{
				mi = edge[i].w;
				int q = -1;
				for (int j = 1; j <= k; j++)
				{
					s = 1ll * d[j][0] + d[j][edge[i].v] + d[j][edge[i].v];
					if (mi > s)
					{
						mi = s;
						q = j;
					}
				}
				if (q != -1)
				{
					d[q][0] = 0;
				}
				ans += mi;
				fa[f1] = f2;
			}
		}
	}
	printf("%lld", ans);
	return 0;
}
