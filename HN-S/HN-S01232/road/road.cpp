#include <bits/stdc++.h>
using namespace std;

const int M = 1e6 + 50, N = 1e4 + 50;
int n, m, k, c[15], v[15][N], fa[N];
struct node{
	int u, v, w;
} a[M];
bool cmp(node A, node B)
{
	return A.w < B.w;
}
void work()
{
	sort(a + 1, a + m + 1, cmp);
	int ans = 0, sum = 0;
	for (int i = 1; i <= m; i++)
	{
		if (sum < n - 1)
		{
			sum++;
			ans += a[i].w;
		}
		else
		{
			break;
		}
	}
	printf("%d", ans);
}
int find(int x)
{
	if (x == fa[x])
	{
		return x;
	}
	return fa[x] = find(fa[x]);
}
void work2()
{
	sort(a + 1, a + m + 1, cmp);
	for (int i = 1; i <= n; i++)
	{
		fa[i] = i;
	}
	int sum = 0;
	for (int i = 1; i <= k; i++)
	{
		int f = 0, cnt = 0;
		if (c[i] == 0)
		{
			for (int j = 1; j <= n; j++)
			{
				if (v[i][j] == 0)
				{
					if (!f)
					{
						f = j;
					}
					else
					{
						fa[j] = find(fa[f]);
					}
					cnt++;
				}
			}
			sum += max(cnt - 1, 0); 
		}
	}
//	for (int i = 1; i <= n; i++)
//	{
//		cout << fa[i] << ' ';
//	}
//	cout << endl;
	int ans = 0;
	for (int i = 1; i <= m; i++)
	{
//		cout << a[i].u << ' ' << a[i].v << endl;
//		cout << find(a[i].u) << ' ' << find(a[i].v) << endl;
//		cout << endl;
		int x = find(a[i].u), y = find(a[i].v);
		if (sum < n - 1 && x != y)
		{
			sum++;
			ans += a[i].w;
			fa[x] = y;
		}
		else if (sum >= n - 1)
		{
			break;
		}
	}
	printf("%d", ans);
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &a[i].u, &a[i].v, &a[i].w);
	}
	for (int i = 1; i <= k; i++)
	{
		scanf("%d", &c[i]);
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &v[i][j]);
		}
	}
	if (k == 0)
	{
		work();
		return 0;
	}
	work2();
	return 0;
}

