#include <bits/stdc++.h>
using namespace std;
const int N = 4000100;
int a[15][100010], ans;
struct Edge
{
	int a, b, c;
}e[N];
bool cmp(Edge x, Edge y)
{
	return x.c < y.c;
}
int c[N], f[N], n, m, k;
int find(int i)
{
	return f[i] == i ? i : f[i] = find(f[i]);
}
void kruscal()
{
	for (int i = 1; i <= n; i ++ ) f[i] = i;
	for (int i = 1; i <= m; i ++ )
	{
		int fa =find(e[i].a), fb = find(e[i].b); 
		if (fa != fb)
		{
			f[fb] = fa;
			ans += e[i].c;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i ++ )
	{
		int u, v, w;
		cin >> u >> v >> w;
		e[i] = {u, v, w};
	}
//	bool flag = 1;
	for (int i = 1; i <= k; i ++ )
	{
		cin >> c[i];
		for (int j = 1; j <= n; j ++ )
		{
			cin >> a[i][j];
		}
//		bool t1 = 0;
//		for (int j = 1; j <= n; j ++ )
//		{
//			if (a[i][j] == 0)
//			{
//				t1 = 1;
//			}
//		}
//		flag &= t1;
	}
		for (int i = 1; i <= k; i ++ )
		{
			for (int j = 1; j <= n; j ++ )
			{
				if (a[i][j] == 0)
				{
					for (int x = 1; x <= n; x ++ ) if (j != x)
					{
						e[ ++ m] = {j, x, a[i][x]};
					}
				}
			}
		}
	
	sort(e + 1, e + m + 1, cmp);
	kruscal();
	cout << ans << '\n';
	return 0;
}