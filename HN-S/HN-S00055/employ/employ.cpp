#include<bits/stdc++.h>
using namespace std; 
#define endl '\n'
#define LL long long
#define fer(i, a, b, args...) for(int i = (a), ##args; i <= (b); i ++)
#define fel(i, a, b, args...) for(int i = (a), ##args; i >= (b); i --)
template <typename T> void chmin(T &x, T y) { if(y < x) x = y; }
template <typename T> void chmax(T &x, T y) { if(y > x) x = y; }
#define fi first
#define se second 
constexpr int N = 2e5 + 10; 
#define MOD 998244353
int n, m; 
int f[N]; 
int a[N]; 
int p[N]; 
bool flag[N]; 
LL ans; 
void dfs(int x) {
	if(x > n) {
		int cnt = 0; 
		fer(i, 1, n) {
			if(!f[i] || cnt >= a[p[i]]) {
				++ cnt; 
			}
		}
		if(n - cnt >= m) {
			(++ ans) %= MOD; 
		}
		return ; 
	}
	fer(v, 1, n) {
		if(flag[v]) continue; 
		flag[v] = 1; 
		p[x] = v; 
		dfs(x + 1); 
		flag[v] = 0; 
	}
}
signed main() {
	// freopen("employ4.in", "r", stdin); 
	freopen("employ.in", "r", stdin); 
	freopen("employ.out", "w", stdout); 
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0); 
	cin >> n >> m; 
	fer(i, 1, n) {
		char c; cin >> c; 
		f[i] = c == '1'; 
	}
	fer(i, 1, n) cin >> a[i]; 
	sort(a + 1, a + n + 1); 
	if(m == n) {
		bool flag = 1; 
		fer(i, 1, n) {
			if(!f[i] || !a[i]) {
				flag = 0; 
			}
		}
		ans = 1; 
		fer(i, 1, n) ans = ans * i % MOD; 
		cout << ans * flag << endl; 
	} else if(n <= 10) {
		dfs(1); 
		cout << ans << endl; 
	} else if(m == 1) {
		ans = 1; 
		fer(i, 1, n) ans = ans * i % MOD; 
		cout << ans << endl; 
	} else {
		bool flag = 1; 
		fer(i, 1, n) if(!f[i]) flag = 0; 
		
	}
	
	return 0; 
}