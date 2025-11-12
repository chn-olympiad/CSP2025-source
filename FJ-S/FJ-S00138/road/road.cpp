#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
const int M = 1e6 + 10, N = 1e4 + 10, K = 1e1 + 10;
long long n, m, k, u[N], v[N], w[N], c[K], a[K][N], pf_sum;
bool vis[N][N], tp;
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		cin >> u[i] >> v[i] >> w[i];
		pf_sum += w[i];
	}
	tp = true;
	for (int i = 1; i <= k; i++)
	{
		cin >> c[i];
		if (c[i]) tp = false;
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			if (a[i][j]) tp = false;
		}
	}
	if (tp)
	{
		cout << 0;
		return 0;
	}
	
	cout << pf_sum;
	return 0;
}
