#include<bits/stdc++.h>
using namespace std;
int n, m, a[505], w, sum0, sum1, ans = 1, mx = 998244353;
string s;
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] == 0)
		{
			w++;
		}
	}
	if (n == m)
	{
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= s.size(); i++)
	{
		if (s[i] == '0')
		{
			sum0++;
		}
		else
		{
			sum1++;
		}
	}
	if (sum1 == n)
	{
		if (w == 0)
		{
			for (int i = 2; i <= n; i++)
			{
				ans = ans * i;
			}
			cout << ans;
			return 0;
		}
	}
	return 0;
}
