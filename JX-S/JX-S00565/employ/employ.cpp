#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const ull M = 998244353;
int a[502], b[502];
int n, m;
ull ans;
string s;

void dfs(int x, int cnt) {
	for (int i = 1; i <= n; i++) {
		if (b[i]) continue;
		int tmp = 1;
		if (x - cnt >= a[i]) tmp = 0;
		if (s[x] == '0') tmp = 0;
		b[i] = 1;
		dfs(x + 1, cnt + tmp);
		b[i] = 0;
	}
	if (x == n) {
		if (cnt >= m) {
			ans++;
			ans %= M;
		}
		return;
	}
	return;
}
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(0, 0);
	cout << ans % M;
	return 0;
}
// luogu uid: 1277793
// 1,2
// 8 pts
