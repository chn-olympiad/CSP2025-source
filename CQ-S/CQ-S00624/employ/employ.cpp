#include <bits/stdc++.h>
#define int long long 
const int N = 5e2 + 5, mod = 998244353; 	
using namespace std; 
int n, m, fw, tjx, ans; 
string s; 
int c[N]; 
bool vis[N]; 
inline void dfs(int x, int sum) {
	if(x == n + 1) {
		if(sum < m) return ; 
		++ans; 
		return ; 
	}
	if(s[x] == '0') return dfs(x + 1, sum); 
	int flag = 0; 
	for(int i = 1; i <= n; ++i)
		if(!vis[i]) {
			vis[i] = 1; 
			flag = (x - 1 - sum >= c[i] ? 0 : 1); 
			dfs(x + 1, sum + flag); 
			vis[i] = 0; 
		}
	return ; 
}
inline void bl() {
	fw = n - fw; 
	tjx = fw; 
	for(int i = 1; i < fw; ++i) tjx = tjx * i % mod; 
	dfs(1, 0); 
	ans = ans * tjx % mod; 
	cout << ans << "\n"; 
	return ; 
}
inline void solve() {
	cin >> n >> m >> s; s = ' ' + s; 
	for(int i = 1; i <= n; ++i) cin >> c[i]; 
	for(int i = 1; i <= n; ++i)
		if(s[i] == '1') ++fw; 
	if(fw < m) return cout << "0\n", void(); 
	if(n <= 18) return bl(); 
	return ; 
}
signed main() {
	freopen("employ.in", "r", stdin); 
	freopen("employ.out", "w", stdout); 
	ios::sync_with_stdio(false); 
	cin.tie(0); cout.tie(0); 
	solve(); 
	return 0; 
}
