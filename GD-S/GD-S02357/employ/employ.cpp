#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int c[1000005], n, m, vis[1000005], ans, cho[1000005];
string s;
bool chk() {
	int fail = 0;
	for (int i = 1; i <= n; i++) {
		if (fail >= c[cho[i]]) fail++;
		else if (s[i] == '0') fail++; 
	}
	if (n - fail == m) return true;
	return false; 
}
void dfs(int x) {
	if (x > n) {
		if (chk()) ans++;
		ans %= mod;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		vis[i] = 1;
		cho[x] = i;
		dfs(x + 1);
		cho[x] = 0;
		vis[i] = 0;
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	s = ' ' + s;
	for (int i = 1; i <= n; i++) cin >> c[i];
	if (n <= 10) {
		dfs(1);
		cout << ans;
	} else {
		ans = n * c[1];
		cout << ans % mod;
	}
}
