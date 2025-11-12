#include <bits/stdc++.h>
#define ing long long
using namespace std;
signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, k, sumans = 0, sumcnt= 0;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i ++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		sumans += z;
	}
	for (int i = 1; i <= k; i ++)
	{
		int c;
		cin >> c;
		sumcnt += c;
		for (int j = 1; j <= n; j ++)
		{
			int p;
			cin >> p;
			sumcnt += p;
		}
	}
	cout << min(sumans, sumcnt);
	return 0;
}
