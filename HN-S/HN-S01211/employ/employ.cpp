#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll P = 998244353;

int n, m, c[505], cnt, p[505], vis[505], ne;
string s;
ll fac, ans;

void dfs(int x) {
	if (x > n) {
		int f = 0;
		for (int i = 1; i <= n; i++) {
			if (f >= c[p[i]] || s[i] == '0') 
				f++;
		}
		ans += (f <= n - m);
		return;
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i]) {
			p[x] = i;
			vis[i] = 1;
			dfs(x + 1);
			vis[i] = 0;
		}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> s;
	s = ' ' + s;
	fac = 1;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		ne += (!c[i]);
		cnt += (s[i] == '1');
		fac = fac * i % P;
	}
	if (m > cnt || m > n - ne) {
		cout << 0;
		return 0;
	}
	if (m == n) {
		cout << fac;
		return 0;
	}
	if (n <= 10) {
		dfs(1);
		cout << ans;
		return 0;
	}
	if (m == 1) {
		sort(c + 1, c + n + 1);
		ans = 1;
		ll now0 = 0, now1 = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i] == '1') {
				ll pos = upper_bound(c + 1, c + n + 1, i - 1) - c - 1;
				ans = (ans * (pos - now1)) % P;
				now1++;
			} else {
				now0++;
				ans = (ans * now0) % P;
			}
		}
		cout << fac - ans;
		return 0;
	}
	cout << 0;
	return 0;
}
// cute zrr
