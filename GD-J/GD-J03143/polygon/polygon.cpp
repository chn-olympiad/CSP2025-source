#include <bits/stdc++.h>
using namespace std;
int n, ans = 1, a[50005];
bool b[500005];
void dfs(int x, int val, int sum, int Max) {
	if (b[val]) return;
	if (x == n) {
		if (sum > Max * 2)
			ans = (ans + 1) % 998244353;
		return;
	}
	dfs(x + 1, a[x] + a[x + 1], sum, Max);
	b[sum + val] = true;
	dfs(x + 1, a[x] + a[x + 1], sum + val, max(Max, x));
	b[sum + val] = false;
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(0); 
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	if (n == 3) {
		int sum = 0, maxx = 0;
		for (int i = 1; i <= n; ++i) {
			sum += a[i];
			maxx = max(maxx, a[i]);
		}
		if (sum > maxx * 2) cout << 1;
		else cout << 0;
		return 0;
	}
	for (int i = 1; i <= n; ++i) dfs(i, a[i], 0, 0);
	cout << ans;
	return 0;
}
