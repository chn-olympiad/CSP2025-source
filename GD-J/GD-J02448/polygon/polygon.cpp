#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 10005, mod = 998244353;
ll n, a[N], cnt[N], f[5003][N], jiec[N], inv[N], ans;//f[i][j]:最长使用了长度i的小木棍拼出长度j的方案数 
ll lfp(ll a, ll b){
	long long res = 1;
	while(b){
		if (b & 1){
			res = res * a % mod; 
		}
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}
void init(){
	jiec[0] = 1;
	for (int i = 1; i <= N - 3; ++i){
		jiec[i] = (jiec[i - 1] * i % mod);
		inv[i] = lfp(jiec[i], (ll)998244351);
	}
} 
ll Cnm(ll u, ll v){//测过了 
	if (v == 0 || v == u){
		return 1;
	} 
	int res = jiec[u];
	res = res * inv[v] % mod;
	res = res * inv[u - v] % mod;
	return res % mod;
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);	
	init();
	cin >> n;
	ll max_len = 0, sum = 0;
	for (int i = 1; i <= n; ++i){
		cin >> a[i];
		max_len = max(max_len, a[i]);
		sum += a[i];
		++cnt[a[i]];
	}
	sort(a + 1, a + n + 1);
	if (n == 3){
		if ((a[1] + a[2] > a[3]) && (a[1] + a[3] > a[2]) && (a[2] + a[3] > a[1])){
			cout << 1;
		}
		else{
			cout << 0;
		}
		return 0;
	}
	f[0][0] = 1;
	for (int i = 1; i <= max_len; ++i){//枚举最长小木棍长度 
		for (int j = 0; j <= max_len * 2; ++j){
			for (int k = 0; i * k <= j && k <= cnt[i]; ++k){
				f[i][j] += f[i - 1][j - i * k] * Cnm(cnt[i], k);
				f[i][j] %= mod;
			}
			if (j > i * 2 && cnt[i] > 0){
				ans = (ans + f[i][j] - f[i - 1][j] + mod) % mod;
			}
		}
		int j = max_len * 2 + 1;
		for (int k = 0; k <= cnt[i]; ++k){//用k根长度为i的木头 
			for (int l = j - i * k; l <= j; ++l){
				f[i][j] = (f[i][j] + f[i - 1][l] * Cnm(cnt[i], k)) % mod;
			}
		}
		ans = (ans + f[i][j] - f[i - 1][j] + mod) % mod;
	}
	cout << ans;
	return 0;
}
 
