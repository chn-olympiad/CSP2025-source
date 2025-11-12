#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int n, a[10], t, d[10];

void solve()
{
	int sum = 0;
	multiset <int> s[10];
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		int mx = 0, cnt = 0;
		for (int j = 1;j <= 3;j++)
		{
			cin >> a[j];
			mx = max(mx, a[j]);
		}
		for (int j = 1;j <= 3;j++)
		{
			if (a[j] == mx)
			{
				d[j] ++;
				cnt = j;
			}
		}
		sort (a + 1, a + 4);
		sum += mx;
		s[cnt].insert(mx - a[2]);
	}
	for (int i = 1;i <= 3;i++)
	{
		if (d[i] > n / 2)
		{
			int k = 1;
			for (auto v : s[i])
			{
				sum -= v;
				if (k == d[i] - n / 2) break;
				k ++;
			}
		}
	}
	cout << sum <<"\n";
	d[1] = d[2] = d[3] = 0;
}
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) solve();
	return 0;
}
