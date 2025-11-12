#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 2;
const int MOD = 998244353;
int n, m, c[N], ans, box[N];
char s[N];
bool vis[N];
void dfs(int st) {
	if(st == n + 1) {
		int failcnt = 0, cnt = 0;
		for(int i = 1; i <= n; i++) {
			//cout << "box:" << box[i] << endl;
			if(failcnt >= c[box[i]] || s[i] == '0') {
				failcnt++;
			} else {
				cnt++;
			}
			//cout << "cnt:" << cnt << " fialcnt:" << failcnt << endl;
		}
		if(cnt >= m) ans++;
		ans %= MOD;
		return;
	}
	for(int i = 1; i <= n; i++) {
		if(vis[i]) continue;
		box[st] = i;
		vis[i] = true;
		dfs(st + 1);
		box[st] = 0;
		vis[i] = false;
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> s[i];
	for(int i = 1; i <= n; i++) cin >> c[i];
	if(n == m) {
		bool flag = true;
		for(int i = 1; i <= n; i++) {
			if(s[i] == '0') {
				flag = false;
				break;
			}
		}
		ans = 1;
		if(flag) {
			for(int i = n; i >= 1; i--) {
				ans *= i;
				ans %= MOD;
			}
			cout << ans;
		} else {
			cout << 0;
		}
		return 0;
	}
	dfs(1);
	cout << ans;
	return 0;
}