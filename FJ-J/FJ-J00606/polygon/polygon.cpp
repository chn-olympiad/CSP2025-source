#include <bits/stdc++.h>
using namespace std;
long long a[5005], n, ans;
int dfs(long long x, long long sum, long long ma, long long t) {
	if (!x) {
		return sum > 2 * ma;
	}
	if (t > n) {
		return 0;
	}
	int m = 0;
	m += dfs(x - 1, sum + a[t], max(ma, a[t]), t + 1) % 998244353;
	m += dfs(x, sum, ma, t + 1) % 998244353;
	return m;
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 3; i <= n; i++) {
		ans += dfs(i, 0, 0, 1) % 998244353;
		ans %= 998244353;
	}
	cout << ans;
	return 0;
}
