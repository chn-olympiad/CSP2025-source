#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, k;
int ans = 0;
vector<pair<int, int> > v[10001];
map<int, int> c;
vector<vector<int> > a;
signed main()
{
	#ifndef DEBUG
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	#endif // DEBUG
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		v[x].push_back({y, w});
		v[y].push_back({x, w});
	}
	a.push_back({0});
	for (int i = 1; i <= k; i++)
	{
		cin >> c[i];
		a.push_back({0});
		for (int j = 1; j <= n; j++)
		{
			int x;
			cin >> x;
			a[i].push_back(x);
		}
	}
	bool flg[n + 2];
	for (int i = 1; i <= n; i++) flg[i] = false;
	for (int i = 2; i <= n; i++) 
	{
		int sum = INT_MAX; // 最小花费
		for (auto p : v[i]) // 1: 连接城市
		{
			if (p.first < i && p.second < sum)
			{
				sum = p.second;
			}
		}
		for (int j = 1; j <= k; j++)
		{
			int cost = 0;
			if (!flg[j]) cost = c[j];
			int mn = INT_MAX;
			for (int s = 1; s < i; s++)
			{
				if (mn > a[j][s]) 
				{
					mn = a[j][s];
				}
			}
			sum = min(sum, mn + cost);
		}
		cerr << "[INFO] " << sum << " " << ans << endl;
		ans += sum;
	}
	cout << ans << endl;
	return 0;
}
