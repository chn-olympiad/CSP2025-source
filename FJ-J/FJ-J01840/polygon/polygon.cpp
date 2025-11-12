#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;

int n, ans = 0, a[5005];
bool xzA = 1;

void solve1() {
	int ans = 0;
	for(int len = 3;len <= n;len ++) {
		ans = (ans + (n - len + 1)) % mod;
	}
	cout << ans << "\n";
	return;
}

void dfs(int x, int sum, int maxn) {
	if(x > n) {
		if(sum == 0) return;
		if(sum > maxn * 2) ans = (ans + 1) % mod;
		return;
	}
	dfs(x + 1, sum, maxn);
	dfs(x + 1, sum + a[x], max(a[x], maxn));
}

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i ++) {
		cin >> a[i];
		if(a[i] > 1) xzA = 0;
	}
	if(xzA) {
		solve1();
		return 0;
	}
	dfs(1, 0, -1);
	cout << ans << "\n";
	return 0;
}
