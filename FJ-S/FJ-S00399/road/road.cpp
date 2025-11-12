#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 1e4 + 5, M = 1e6 + 5, P = 2e7 + 5;

int n, m, k, fa[N], c[15], h[15][N];
struct Node
{
	int u, v, w;
} a[P];

void read(int &x)
{
	char c;
	c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
}

int find(int x)
{
	if (x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

bool cmp(Node x, Node y)
{
	return x.w < y.w;
}

void work()
{
	sort(a + 1, a + m + 1, cmp);
	int cnt = 0, res = 0;
	for (int i = 1; i <= m; i ++ )
	{
		int f1 = find(a[i].u), f2 = find(a[i].v);
		if (f1 != f2) fa[f1] = f2, cnt ++ , res += a[i].w;
		if (cnt == n - 1) break;
	}
	cout << res << endl;
}

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	read(n);
	read(m);
	read(k);
	for (int i = 1; i <= n; i ++ ) fa[i] = i;
	for (int i = 1; i <= m; i ++ )
	{
		read(a[i].u);
		read(a[i].v);
		read(a[i].w);
	}
	bool flag = 0;
	for (int i = 1; i <= k; i ++ )
	{
		read(c[i]);
		if (c[i]) flag = 1;
		for (int j = 1; j <= n; j ++ ) read(h[i][j]);
	}
	if (k == 0)
	{
		work();
		return 0;
	}
	if (!flag)
	{
		for (int i = 1; i <= k; i ++ )
		{
			for (int j = 1; j <= n; j ++ )
			{
				for (int k = j + 1; k <= n; k ++ )
				{
					a[ ++ m].u = j;
					a[m].v = k;
					a[m].w = h[i][j] + h[i][k];
				}
			}
		}
		work();
		return 0;
	}
	work();
	return 0;
}


