#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 5;
int n, m, a[N], ans, c[N];
bitset<N> vis;
string s;
void solve(int cur) {
	if (cur == n + 1) {
		int num = 0;
		for (int i = 1; i <= n; ++i) {
			if (num >= c[i] || s[i] == '0') ++num;
		}
		if (n - num >= m) ++ans;
		return;
	}
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			vis[i] = true;
			c[cur] = a[i];
			solve(cur + 1);
			vis[i] = false;
		}
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m >> s;
	s = " " + s;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	solve(1);
	cout << ans;
	return 0;
}
