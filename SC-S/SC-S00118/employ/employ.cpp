#include <iostream>
#define ll long long
#define MOD 998244353
using namespace std;
int n, m, t, c, fl, fl2;
ll ans;
int s[505], b[505], a[505], u[505];
void dfs(int x) {
	if (x == n) {
		int st = 0, lv = 0;
		for (int i = 1; i <= n; ++i) {
			if (lv >= a[b[i]]) {
				lv++;
				continue;
			}
			if (s[i] == 1) {
				st++;
			} else {
				lv++;
			}
		}
		if (st >= m) {
			++ans;
		}
		return;
	}

	for (int i = 1; i <= n; ++i) {
		if (u[i]) continue;
		b[++t] = i;
		u[i] = 1;
		dfs(x + 1);
		u[i] = 0;
		--t;
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	fl = 1;
	for (int i = 1; i <= n; ++i) {
		char c;
		cin >> c;
		s[i] = c - '0';
		if (s[i] == 0) fl = 0;
		if (s[i] == 1) fl2 = 0;
	}
	if (fl2) {
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= n; ++i) c += s[i];
	for (int i = 1; i <= n; ++i) cin >> a[i];
	dfs(0);
	cout << ans;
	return 0;
}