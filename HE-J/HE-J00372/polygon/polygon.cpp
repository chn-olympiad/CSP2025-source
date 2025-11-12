#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 1e6 + 10, mod = 998244353;

int n, a[N], dp[N], pre[N];
int cnt[N];

int quick_pow(int a, int b) {
	int res = 1 % mod;
	for (; b; b >>= 1) {
		if (b & 1)
			res = (res % mod * a % mod) % mod;
		a = (a % mod * a % mod) % mod;
	}
	return res % mod;
}

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	int maxx = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
		maxx = max(maxx, a[i]);
	}
//	for (int i = 1; i <= maxx; i++)
//		cout << cnt[i] << ' ';
//	cout << '\n';
	pre[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = maxx; j >= a[i]; j--)
			pre[j] = (pre[j] % mod + pre[j - a[i]] % mod) % mod;
	}
//	for (int i = 1; i <= maxx; i++)
//		cout << pre[i] << ' ';
//	cout << '\n';
	dp[1] = pre[1] % mod;
	for (int i = 2; i <= maxx; i++)
		dp[i] = (dp[i - 1] % mod + pre[i] % mod) % mod;
	for (int i = 1; i <= maxx; i++)
		dp[i]--;
//	for (int i = 1; i <= maxx; i++)
//		cout << dp[i] << ' ';
//	cout << '\n';
	for (int i = 1; i <= maxx; i++)
		cnt[i] += cnt[i - 1];
	int res = 0;
	for (int i = 1; i <= n; i++) {
		res += (quick_pow(2, cnt[a[i]] - 1) % mod - 1 % mod - dp[a[i]] % mod + mod + mod) % mod;
//		cout << cnt[a[i]] - 1 << ' ';
	}
//	cout << '\n';
	cout << res % mod << '\n';
	return 0;
}
