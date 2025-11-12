#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ri register int
#define inl inline
#define rep(i,l,r) for(ri i = l; i <= r; i ++)
#define per(i,r,l) for(ri i = r; i >= l; i --)
#define N 5005
#define mod 998244353
int n;
int a[N], ans, s, f[N], g[N];
inl int ksm(int a, int b){
	int res = 1;
	while(b){
		if(b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1; 
	}
	return res;
}
inl void dfs(int id, int sum, int mx, int cnt){
	if(id == n + 1){
		if(sum > 2 * mx && cnt >= 3) ans ++, ans %= mod;
		return ;
	}
	if(n - id + 1 + cnt < 3) return ;
	dfs(id + 1, sum + a[id], max(mx, a[id]), cnt + 1);
	dfs(id + 1, sum, mx, cnt);
}
inl int C(int n, int m){
	return f[n] * g[m] % mod * g[n - m] % mod;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	rep(i, 1, n) cin >> a[i], s += a[i];
	if(s == n){
		f[0] = 1;
		rep(i, 1, n){
			f[i] = f[i - 1] * i % mod;
		}
		g[n] = ksm(f[n], mod - 2) % mod;
		per(i, n - 1, 0){
			g[i] = (i + 1) * g[i + 1] % mod;
		}
		rep(i, 3, n){
			ans = (ans + C(n, i)) % mod;
		}
		cout << ans % mod;
	}
	else{
		ans = 0;
		dfs(1, 0, 0, 0);
		cout << ans % mod;
	}
	return 0;
}

