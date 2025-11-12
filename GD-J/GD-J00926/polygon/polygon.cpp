#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
const int mod = 998244353;
int n, a[N], ans;
void dfs(int x, int sum, int maxx) {
	if (x == n + 1) {
		if (sum > 2 * maxx) {
			ans++;
			ans %= mod;
		}
		return;
	}
	dfs(x + 1, sum + a[x], max(maxx, a[x]));
	dfs(x + 1, sum, maxx);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout); 
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(1, 0, 0);
	cout << ans << '\n';
	return 0;
}
