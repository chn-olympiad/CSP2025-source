#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int N = 1e5 + 5;

int t, n;
array<array<int, 3>, N> a;
array<int, N> cs, cnt;

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> t;
	while (t--)
	{
		cnt[0] = cnt[1] = cnt[2] = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
		for (int i = 1; i <= n; i++)
		{
			int val = max({a[i][0], a[i][1], a[i][2]});
			if (a[i][0] == val) cs[i] = 0;
			else if (a[i][1] == val) cs[i] = 1;
			else cs[i] = 2;
			cnt[cs[i]]++;
		}
		int d = -1;
		for (int i = 0; i < 3; i++)
		{
			if (cnt[i] > n / 2) d = i;
		}
		vector<int> ve;
		for (int i = 1; i <= n; i++)
		{
			if (cs[i] == d)
			{
				int maxn = 0;
				for (int j = 0; j < 3; j++)
				{
					if (j != d) maxn = max(maxn, a[i][j]);
				}
				ve.emplace_back(a[i][d] - maxn);
			}
		}
		sort(ve.begin(), ve.end());
		ll sum = 0;
		for (int i = 1; i <= n; i++) sum += a[i][cs[i]];
		if (d != -1)
		{
			int nowc = cnt[d] - (n / 2);
			for (int i = 0; i < nowc; i++) sum -= ve[i];
		}
		cout << sum << "\n";
	}
	return 0;
}
