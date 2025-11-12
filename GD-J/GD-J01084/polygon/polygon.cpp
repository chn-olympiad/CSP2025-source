#include <bits/stdc++.h>
using namespace std;
const int N = 5002, MD = 998244353;
int n, a[N], f[5000][4500], s[N], res;
// f[i, j, k]表示前i个木棍，选了j个木棍，木棍的长度和为k的方案数
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	f[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 3; j <= i; j++)
			for (int k = 2 * a[i] + 1; k <= s[i]; k++)
				(res += f[j - 1][k - a[i]]) %= MD;
		for (int j = i; j >= 1; j--)
			for (int k = 1; k <= s[i]; k++)
				if (k >= a[i]) f[j][k] = (f[j - 1][k - a[i]] + f[j][k]) % MD;
	}
	cout << res << '\n';
	return 0;
}
/*
20
75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1
*/
