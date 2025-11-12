#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;
int a[5005], n;
ll ans;
bool vis[505];
void dfs(int cnt, int mx, int sum, int lst) {
	if (cnt >= 3) {
		ans += (sum > 2 * mx ? 1 : 0);
		ans %= mod;
		if (cnt == n) return ;
	}
	for (int i = lst + 1; i <= n; i ++) {
		if (! vis[i]) {
			vis[i] = true;
			dfs(cnt + 1, max(mx, a[i]), sum + a[i], i);
			vis[i] = false;
		}
	}
}
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	if (n <= 27) {
		dfs(0, 0, 0, 0);
		cout << ans << '\n';
	} else {
		ll sum = 1; ans = 1;
		for (int i = n; i > 3; i --) {
			sum = sum * i % mod;
			ans = (ans + sum) % mod; 
		}
		cout << ans << '\n';
	}
	return ;
}
int main(void) {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(0);
	cout.tie(nullptr) -> sync_with_stdio(0);
	solve();
	return 0;
} 
