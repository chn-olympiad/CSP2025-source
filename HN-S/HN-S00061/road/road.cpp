#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5, M = 1e6 + 5;
long long n, m, k;
long long f[N];
struct Node{
	long long u, v, w;
}e[M * 4];
bool cmp(Node a, Node b)
{
	return a.w < b.w;
}
long long Find(long long x)
{
	if (f[x] == x)
		return x;
	return f[x] = Find(f[x]);
}
long long a[15][N], c[15];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	if (k == 0)
	{
		for (int i = 1; i <= n; ++ i)
			f[i] = i;
		for (int i = 1; i <= m; ++ i)
			cin >> e[i].u >> e[i].v >> e[i].w;
		sort(e + 1, e + m + 1, cmp);
		long long ans = 0, cnt = 0;
		for (int i = 1; i <= m; ++ i)
		{
			long long u = Find(e[i].u), v = Find(e[i].v), w = e[i].w;
			if (f[u] != f[v])
			{
				f[u] = v;
				ans += w;
				cnt ++;
			}
			if (cnt == n - 1)
				break;
		}
		cout << ans << "\n"; 
	} 
	else
	{
		for (int i = 1; i <= n; ++ i)
			f[i] = i;
		for (int i = 1; i <= m; ++ i)
			cin >> e[i].u >> e[i].v >> e[i].w;
		bool af = 0;
		for (int i = 1; i <= k; ++ i)
		{
			cin >> c[i];
			if (c[i] != 0)
				af = 1;
			for (int j = 1; j <= n; ++ j)
				cin >> a[i][j];
		}
		if (af == 0)
		{
			long long tmp = m;
			for (int i = 1; i <= k; ++ i)
				for (int j = 1; j <= n; ++ j)
					e[++ tmp] = {i, j, a[i][1] + a[i][j]};
			sort(e + 1, e + tmp + 1, cmp);
			long long ans = 0, cnt = 0, j = -1;
			for (int i = 1; i <= tmp; ++ i)
			{
				long long u = Find(e[i].u), v = Find(e[i].v), w = e[i].w;
				if (f[u] != f[v])
				{
					j = u;
					f[u] = v;
					ans += w;
					cnt ++;
				}
				if (cnt == n - 1)
					break;
			}
			cout << ans << "\n"; 
		}
		else
		{
			long long tmp = m;
			for (int i = 1; i <= k; ++ i)
				for (int j = 1; j <= n; ++ j)
					e[++ tmp] = {i, j, c[i] + a[i][1] + a[i][j]};
			sort(e + 1, e + tmp + 1, cmp);
			long long ans = 0, cnt = 0, j = -1;
			bool q = 1;
			for (int i = 1; i <= tmp; ++ i)
			{
				if (i > m && e[i].u == j)
				{
					e[i].w -= c[j];
				} 
				long long u = Find(e[i].u), v = Find(e[i].v), w = e[i].w;
				if (f[u] != f[v])
				{
					j = u;
					f[u] = v;
					ans += w;
					cnt ++;
				}
				if (cnt == n - 1)
					break;
			}
			cout << ans << "\n"; 
		}
	}
	return 0;
}
/*
4 4 0
1 2 4
2 3 5
2 4 3
3 4 7
*/ 
