#include <bits/stdc++.h>
using namespace std; 
const int N = 505, MOD = 998244353; 
int n, m, c[N]; 
long long ans; 
bool vis[N]; 
string s; 
void dfs(int pos, int cnt) {
	if (pos == n + 1) {
		if (cnt <= n - m)
			ans++; 
		return; 
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i])
			continue; 
		vis[i] = true; 
		dfs(pos + 1, cnt + ((s[pos - 1] == '0') || (cnt >= c[i]))); 
		vis[i] = false; 
	}
}
int main() {
	ios :: sync_with_stdio(false); 
	cin.tie(nullptr), cout.tie(nullptr); 
	freopen("employ.in", "r", stdin); 
	freopen("employ.out", "w", stdout); 
	cin >> n >> m; 
	cin >> s; 
	for (int i = 1; i <= n; i++)
		cin >> c[i]; 
	dfs(1, 0); 
	cout << ans << endl; 
	return 0; 
}
