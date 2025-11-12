#include<bits/stdc++.h>
using namespace std;
const int N = 15, mod = 998244353;
int n, m, c[N], p[N], ans = 0;
string s;
bool vis[N];
void solve() {
	int cnt = 0, sum = 0; 
	for (int i = 1; i <= n; ++i) {
		if (cnt >= c[p[i]]) {
			cnt++;
			continue;
		}
		if (s[i] == '0') {
			cnt++;
		}else if (s[i] == '1') {
			sum++;
		}
	}
	if (sum >= m) ans++;
}
void dfs(int x) {
	if (x == n + 1) {
		solve();
		return ;
	}
	for (int i = 1; i <= n; ++i) {
		if (vis[i]) continue;
		vis[i] = 1;
		p[x] = i;
		dfs(x + 1);
		vis[i] = 0;
	}
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	s = ' ' + s;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
	}
	dfs(1);
	cout << ans << '\n';
	return 0;
}

