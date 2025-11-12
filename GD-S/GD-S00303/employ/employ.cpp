#include <bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define vi vetor<int>
#define sz(a) ((int)a.size())
#define mp make_pair
#define pb emplace_back
#define pii pair<int, int>
using namespace std;
const int N = 500 + 10, mod = 998244353;
int n, m, c[N];
string s;
ll ans = 0;
int f[N];
bool vis[N];
void dfs(int x) {
	if(x == n + 1) {
		int x = 0, cnt = 0;
		for(int i = 1; i <= n; i++) {
			if(x < c[f[i]] && s[i - 1] == '1') cnt++;
			else x++;
		} 
		if(cnt < m) return;
		ans++;
		return;
	} 
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			vis[i] = 1;
			f[x] = i; 
			dfs(x + 1);
			vis[i] = 0;
		}
	}
}
ll fac[N];
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> s;
	fac[0] = 1;
	for(int i = 1; i <= n; i++) {
		fac[i] = (fac[i - 1] * i) % mod;
	}
	for(int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	if(n <= 10) {
		dfs(1);
		cout << ans << '\n';
		return 0;
	}
	if(m == 1) {
		int cnt = 0;
		ll ans = 0;
		for(int i = 1; i <= n; i++) {
			if(c[i] != 0) {
				(ans += fac[n - 1]) %= mod;
			}
		} 
		cout << ans << '\n'; 
	}
	return 0;
} 
