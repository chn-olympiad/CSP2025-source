#include <bits/stdc++.h>

using namespace std;

int n, m, k, ans = 0;

int main ()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		ans += w;
	}
	for (int i = 1; i <= k; i++)
	{
		int j;
		cin >> j;
		for (int j = 0; j < n; j++)
		{
			int cnt;
			cin >> cnt;
		}
	}
	cout << ans;
	return 0;
}
