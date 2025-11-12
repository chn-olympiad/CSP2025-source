#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a.begin() + 1, a.end());
	if (n <= 2)
	{
		cout << "0" << endl;
		return 0;
	}
	else if (n == 3)
	{
		if (a[1] + a[2] > a[3])
		{
			cout << "1" << endl;
		}
		else
		{
			cout << "0" << endl;
		}
		return 0;
	}
	int cnt = 0;
	for (int i = 0; i <= (1LL << n); i++)
	{
		int x = i;
		int sum = 0;
		int j = 1;
		int mx = -1;
		while (x)
		{
			if (x & 1)
			{
				mx = max(mx, a[j]);
				sum += a[j];
			}
			j++;
			x >>= 1;
		}
		if (j >= 3 && sum > 2 * mx) cnt++;
		cnt %= 998244353;
	}
	cout << cnt;
	return 0;
}
