#include <bits/stdc++.h>
using namespace std;


int n, m;
int a[510];
int cnt = 0;
int sum = 0;
bool b[510];
bool vis[510];
bool all_0, all_1;
void dfs(int cnt, int nocnt) {
//	if (nocnt > n - m) {
//		cout << nocnt << " " << n - m << endl;
//		return;
//	}
	if (cnt > n) {
		if (cnt - nocnt >= m) {
			sum++;
//			cout << "sum++" << endl;
		}
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = 1;
//			cout << string(cnt - 1, '\t') << i << " " << nocnt + int(nocnt >= a[i] || b[i]) << endl;
			dfs(cnt + 1, nocnt + int(nocnt >= a[i] || b[i]));
			vis[i] = 0;
		}
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	all_1 = all_0 = 1;
	for (int i = 1; i <= n; i++) {
		char ch;
		cin >> ch;
		b[i] = (ch == '1');
		if (b[i] == 0) {
			all_1 = 0;
		} else {
			all_0 = 0;
			cnt++;
		}
	}
	for (int i = 1; i <= n; i++) cin >> a[i];
	memset(vis, 0, sizeof(vis));
	if (m == n) {
		if (all_1) {
			long long ans = 1;
			for (int i = 1; i <= n; i++) {
				ans = ans * i % 998244353; 
			} 
			cout << ans << endl;
		} else {
			cout << 0 << endl;
		}
	} else if (m == 0) {
		long long ans = 1;
		for (int i = 1; i <= n; i++) {
			ans = ans * i % 998244353; 
		} 
		cout << ans << endl;
	} else if (all_0) {
		long long ans = 1;
		for (int i = 1; i <= n; i++) {
			ans = ans * i % 998244353; 
		} 
		cout << ans << endl;
	} else if (cnt < m) {
		cout << 0 << endl;
	} else {
		dfs(1, 0);
		cout << sum << endl; 
	}
	return 0;
}
