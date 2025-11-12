#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int z = 507, mod = 998244353;
int n, m, c[z], p[z];
ll ans;
bool vis[z];
string s;
void dfs(int d) {
	if(d > n) {
		int ct = 0, sm = 0;
		for(int i = 1; i <= n; ++i) 
			if(s[i - 1] == '0' || ct >= c[p[i]]) ++ct;
			else ++sm;
		if(sm >= m) ans = (ans + 1) % mod;
	}
	for(int i = 1; i <= n; ++i) {
		if(vis[i]) continue;
		vis[i] = 1;
		p[d] = i;
		dfs(d + 1);
		vis[i] = 0;
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
	cin >> n >> m >> s;
	for(int i = 1; i <= n; ++i) cin >> c[i];
	if(n <= 10) {
		dfs(1);
		cout << ans << "\n";
	}
	else cout << "zai jian, bing qie zai ye bu jian.\n";
	return 0;
}
/*
baolimeiju
O(n*n!)
fen:8
*/
