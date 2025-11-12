#include <bits/stdc++.h>
using namespace std;
int n, a[5010], cnt;
const int MOD = 998244353;
void solvebig() { // all 1
	long long ans = 1;
	for (int i = 1; i <= n; i++)
		ans = (ans << 1) % MOD;
	ans = (ans - n + MOD) % MOD;
	long long k = 1ll * n * (n - 1) / 2;
	ans = (ans - k + MOD) % MOD;
	cout << ans - 1 << '\n'; // answer = 2^n - C(1, n) - C(2, n) - 1
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	if (n > 20) {
		solvebig();
		return 0;
	}
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 1; i < (1 << n); i++) {
		int mx = -1, sum = 0, num = 0;
		for (int j = 0; j < n; j++)
			if (i & (1 << j)) {
				if (a[j] > mx) mx = a[j];
				sum += a[j]; num++;
			}
		if (num >= 3 && sum > 2 * mx)
			cnt = (cnt + 1) % MOD;
	}
	cout << cnt << '\n';
	return 0;
}
