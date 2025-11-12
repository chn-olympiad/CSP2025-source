#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;
const int maxn = 505, mod = 998244353;
int a[maxn], ans, c[maxn], n, m;
char s[maxn];
bool vis[maxn];
void dfs(int dep){
	if (dep > n){
		int now = 0;
		for (int i = 1; i <= n; i++){
			if (!(s[i] - '0') || c[a[i]] <= now) now++; 
			if (n - now < m) return;
		}ans++; return;
	}for (int i = 1; i <= n; i++) if (!vis[i]) a[dep] = i, vis[i] = 1, dfs(dep + 1), vis[i] = a[dep] = 0;
}
main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> s + 1;
	for (int i = 1; i <= n; i++) cin >> c[i];
	if (m == n){
		for (int i = 1; i <= n; i++) {
			if (!(s[i] - '0')) cout << "0", exit(0);
		}for (int i = 1; i <= n; i++) if (!c[i]) cout << "0", exit(0);
		int ans = 1; for (int i = 1; i <= n; i++) ans = ans * i % mod; cout << ans;
		return 0;
	}
	dfs(1); cout << ans % mod;
}