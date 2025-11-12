#include <bits/stdc++.h>
using namespace std;
#define int long long
int c[505];
signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	long long n, m, cnt = 0;
	cin >> n >> m;
	string s;
	cin >> s;
	for (long long i = 1; i <= n; i++)
	{
		cin >> c[i];
		if (s[i - 1] == '1') cnt++;
	}
	if (m == 1)
	{
		sort(c + 1, c + n + 1);
		for (long long i = 1; i <= n; i++)
		{
			if (c[i] >= i)
			{
				long long mul = 1;
				for (long long j = 1; j <= n; j++)
				{
					mul *= j;
				}
				cout << mul;
				return 0;
			}
		}
		cout << 0;
		return 0;
	}
	if (m == n)
	{
		if (cnt == n)
		{
			for (int i = 1; i <= n; i++)
			{
				if (c[i] == 0)
				{
					cout << 0;
					return 0;
				}
			}
			long long mul = 1;
			for (long long i = 1; i <= n; i++)
			{
				mul *= i;
			}
			cout << mul;
			return 0;
		}
		else
		{
			cout << 0;
			return 0;
		}
	}
	cout << 0;
	return 0;
}
