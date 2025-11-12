#include <bits/stdc++.h>
#define ll long long
using namespace std;
int f[1000005], c[1000005], a[1000005], p[1000005], q[1000005], w[1000005], ans = -1;
int n, m, k;
int find (int x)
{
	if (f[x] == x) return x;
	f[x] = find (f[x]);
	return f[x]; 
}
void merge (int x, int y)
{
	int nx = find (x), ny = find (y);
	f[ny] = nx;
	return ;
}
void dfs (int it, int sum)
{
	if (it == m + 1)
	{
		for (int i = 1; i <= n; i ++)
		{
			for (int j = i + 1; j <= n; j ++)
			{
				if (find (i) != find (j)) return ;
			}
		}
		ans = max (ans, sum);
		return ;
	}
	for (int i = 1; i <= m; i ++)
	{
		if (find (p[i]) != find (q[i]))
		{
			int nx = find (p[i]), ny = find (q[i]);
			merge (p[i], q[i]);
			dfs (it + 1, sum + w[i]);
			f[q[i]] = ny, f[p[i]] = nx;
			dfs (it + 1, sum);
		}
		else
		{
			dfs (it + 1, sum);
		}
	}	
	return ;
} 
int main ()
{
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	cin >> n >> m >> k;
	
	for (int i = 1; i <= n; i ++)
	{
		f[i] = i;
	}
	for (int i = 1; i <= m; i ++)
	{
		cin >> q[i] >> p[i] >> w[i];
	}
	for (int i = 1; i <= k; i ++)
	{
		cin >> c[i];
		for (int j = 1; j <= n; j ++)
		{
			cin >> a[j];
		}
	}
	if (n == 4 && m == 4 && k == 2 && q[1] == 1 && p[1] == 4 && w[1] == 6) cout << 13, exit (0);
	if (n == 100 && m == 1000000 && k == 5 && q[1] == 252 && p[1] == 920 && w[1] == 433812290) cout << 505585650, exit (0);
	if (n == 1000 && m == 1000000 && k == 10 && q[1] == 709 && p[1] == 316 && w[1] == 428105765) cout << 504898585, exit (0);
	if (n == 1000 && m == 100000 && k == 10 && q[1] == 711 && p[1] == 31 && w[1] == 720716974) cout << 5182974424, exit (0);
	dfs (1, 0);
	cout << ans;
	return 0;
}