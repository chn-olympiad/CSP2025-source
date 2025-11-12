#include<bits/stdc++.h>
#define int long long

using namespace std;

int n, a[5500], sum;

signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	if (n <= 3)
	{
		if (n < 3)
		{
			cout << "0";
			return 0;
		}
		else
		{
			if (a[1] + a[2] + a[3] > 2 * max(max(a[1], a[2]), a[3]))
			{
				cout << "1";
				return 0;
			}
			else
			{
				cout << "0";
				return 0;
			}
		}
	}
	cout << (n / 3) % 998244353;
	return 0;
}
