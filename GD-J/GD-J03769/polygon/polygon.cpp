#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int maxn = 5e3 + 10, mod = 998244353;
ll ans;
int n, a[maxn];
void dfs(int i, ll sum, int mx, int cnt) {
	if (i > n) {
		if (sum > 2 * mx && cnt >= 3) ans = (ans + 1) % mod;
		return;
	}
	dfs(i + 1, sum + a[i], max(mx, a[i]), cnt + 1);
	dfs(i + 1, sum, mx, cnt);
}
ll qpow(int x) {
	ll ans = 1;
	for (int i = 1; i <= x; i++) ans = ans * 2 % mod;
	return ans;
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	int mx = 0;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), mx = max(mx, a[i]);
	if (mx == 1) {
		cout << (qpow(n) - n - 1ll * n * (n - 1) / 2 % mod - 1 + mod) % mod;
		exit(0);
	}
	dfs(1, 0, 0, 0);
	printf("%lld", ans);
	return 0;
}

