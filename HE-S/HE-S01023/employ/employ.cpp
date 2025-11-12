#include <bits/stdc++.h>
using namespace std;
const int N = 510, M = 998244353;
#define int long long
int n, m, c[N], p[N], cur, s, ans;
string a;
signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> a, a = " " + a;
	for (int i = 1; i <= n; i++)
		cin >> c[i], p[i] = i;
	if (m == n)
	{
		ans = 1;
		for (int i = 1; i <= n; i++)
			if (!c[i] || a[i - 1] == '0')
			{
				cout << 0;
				return 0;
			}
		for (int i = 1; i <= n; i++)
			ans = ans * i % M;
		cout << ans;
	}
	else if (n <= 10)
	{
		do
		{
			cur = s = 0;
			for (int i = 1; i <= n; i++)
			{
				if (a[i] == '0' || cur >= c[p[i]])
					cur++;
				else
					s++;
				if (s >= m)
				{
					ans = (ans + 1) % M;
					break;
				}
			}
		} while (next_permutation(p + 1, p + 1 + n));
		cout << ans;
	}
	else
		cout << 0;
}
/*
10 10
1111111111
6 1 4 2 1 2 5 4 3 3
*/
