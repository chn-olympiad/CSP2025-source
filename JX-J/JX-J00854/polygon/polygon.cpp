#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const ull M = 998244353;
int n;
ull ans;
ull a[5003];
void dfs(int x, ull sum, ull maxx, ull num) {
	if (x == n + 1) {
		if (num >= 3 && sum > 2 * maxx) {
			ans++;
			ans %= M;
		}
		return;
	}
	dfs(x + 1, sum + a[x], max(maxx, a[x]), num + 1);
	dfs(x + 1, sum, maxx, num);
	return;
}
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	ull maxx = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxx = max(maxx, a[i]);
	}
	dfs(1, 0, 0, 0);
	cout << ans % M << endl;
	return 0;
}
// luogu uid: 1277793
// €€₤ 🐷
