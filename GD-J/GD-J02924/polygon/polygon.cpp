#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long n, a[5005], maxn, cnt, ans = 0;
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 1; i < (1 << n); i++)
	{
		maxn = -1;
		cnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				maxn = max(maxn, a[j]);
				cnt += a[j];
			}
		}
		if (cnt > maxn * 2)
			ans = (ans + 1) % mod;
	}
	cout << ans << endl;
	return 0;
}
