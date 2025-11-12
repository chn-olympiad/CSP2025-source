#include <bits/stdc++.h>

using namespace std;
int n, m, c[15], g[15], f[15], ans, sum;
string s;
bool pd() {
	sum ++;
	int cnt = 0, ff = 0;
	for(int i = 1; i <= n; i ++) {
//		if(g[i] == 0) cout << "T\n";
		if(i - 1 - cnt >= c[g[i]]) continue;
		if(s[ff ++] == '1')
			cnt ++;
	}
	return cnt >= m;
}
void solve(int x) {
	if(x > n) {
		if(pd())ans ++;
		return;
	}
	for(int i = 1; i <= n; i ++) if(!f[i]) {
		f[i] = 1, g[x] = i;
		solve(x + 1);
		f[i] = 0;
	}
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for(int i = 1; i <= n; i ++) cin >> c[i];
	if(n <= 10) {
		solve(1);
		cout << ans << '\n';
	}
	return 0;
}


