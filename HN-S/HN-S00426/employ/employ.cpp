#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int n, m, ans, c[510], a[510];
bool flag = true, vis[510];
string s;
bool check(int a[]) {
	int cnt = 0, res = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i - 1] == '0' || cnt >= a[i]) {
			cnt++;
		}
		else {
			res++;
		}
	}
	return res >= m;
}
void dfs(int x) {
	if (x > n) {
		if (check(a)) {
			ans = (ans + 1) % mod;
		}
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = true;
			a[x] = c[i];
			dfs(x + 1);
			vis[i] = false;
		} 
	}
	return;
}
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != '1') {
			flag = false;
		}
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	if (m == n) {
		if (!flag) {
			cout << 0 << '\n';
			return 0;
		}
		for (int i = 1; i <= n; i++) {
			if (c[i] == 0) {
				cout << 0 << '\n';
				return 0;
			}
		}
		ans = n;
		while (--n) {
			ans = ans * n % mod;
		}
		cout << ans << '\n'; 
	}
	else if (n <= 18) {
		dfs(1);
		cout << ans << '\n';
	}
	else if (m == 1) {
		int pre = 0;
		for (int i = 1; i <= n; i++) {
			if (c[i]) {
				pre++;
			}
		}
		ans = 1;
		while (--n) {
			ans = (ans * n) % mod;
		}
		cout << ans << endl;
	}
	else if (flag) {
		int ans = 1, s = 1;
		for (int i = 1; i <= n; i++) {
			if (c[i] > n) {
				c[i] = n;
			}
			if (c[i]) ans = ans * n % mod;
			s = s * (n - c[i]) % mod;
		}
		cout << ans - s << '\n';
	}
	return 0;
}
