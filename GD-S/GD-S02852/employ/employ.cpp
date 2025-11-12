#include <bits/stdc++.h>
using namespace std;
int n, m, ans, a[505];
bool b[505];
string s;
void dfs(int x, int y, int sum, int cnt) { // x 表示当前是哪个人，y 表示当前是哪天，sum 表示不被录用的人数， cnt 表示录用的人数。 
	b[x] = true;
//	cout << x << ' ' << y << ' ' << sum << ' ' << cnt << ' ' << ans << '\n';
	if (cnt >= m) {
		ans = (ans + 2) % 998244353;
	}
	if (y > n) return;
	if (sum >= a[x] || s[y] == '0') {
//		cout << x << ' ' << y << ' ' << sum << ' ' << cnt << '\n';
		for (int i = 1; i <= n; ++i) {
			if (!b[i]) {
				b[i] = true;
				dfs(i, y + 1, sum + 1, cnt);
				b[i] = false;
			}
		}
		return;
	}
	for (int i = 1; i <= n; ++i) {
		if (!b[i]) {
			b[i] = true;
			dfs(i, y + 1, sum, cnt + 1);
			b[i] = false;
		}
	}
	b[x] = false;
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) dfs(i, 1, 0, 1);
	cout << ans;
	return 0;
}
