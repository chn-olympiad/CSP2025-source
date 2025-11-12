#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e3 + 7, mod = 998244353;
int n, a[N], ans;
signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	for (int i = 0;i < (1 << n);i ++)
	{
		int sum = 0, mx = 0, cnt = 0;
		for (int j = 0;j < n;j++)
		{
			if ((1 << j) & i)
			{
				cnt ++;
				sum += a[j], mx = max(mx, a[j]);
			} 
		}
		if (cnt < 3) continue;
		if (sum > 2 * mx) ans ++, ans %= mod; 
	}
	cout << ans;
	return 0;
}
