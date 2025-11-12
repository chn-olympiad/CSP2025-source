#include <iostream>

using namespace std;

typedef long long ll;
const ll mod = 998244353;
const int N = 507;
int n, m;
int c[N], cnt[N], use[N], a[N];
ll fac[N], inv[N], ans, dp[N][2];
string s;

ll C(int x, int y){
	return fac[x] * inv[y] % mod * inv[x-y] % mod;
}

ll qpow(ll x, ll y){
	ll res = 1;
	while(y){
		if(y&1) (res*=x)%=mod;
		y>>=1;
		(x*=x)%=mod;
	}
	return res;
}

void Dfs(int x){
	if(x == n + 1){
		int tmp = 0;
		for(int i = 1; i <= n; ++i){
			if(s[i-1] == '0' || tmp >= c[a[i]]) tmp++;
		}
		if(tmp <= n - m) ans++;
		return;
	}
	for(int i = 1; i <= n; ++i){
		if(use[i]) continue;
		use[i] = 1; a[x] = i;
		Dfs(x+1);
		use[i] = a[x] = 0;
	}
}

int main(){
	ios::sync_with_stdio(false);
	freopen("employ.in", "r", stdin); freopen("employ.out", "w", stdout);
	cin >> n >> m >> s; int opA = 1, opB = 1;
	for(int i = 1; i <= n; ++i) cin >> c[i], cnt[c[i]]++;
	for(int i = 0; i < s.size(); ++i) if(s[i] != '1') opA = 0;
	fac[0] = 1;
	for(int i = 1; i <= 500; ++i) fac[i] = fac[i-1] * i % mod;
	inv[500] = qpow(fac[500], mod - 2);
	for(int i = 499; i >= 0; --i) inv[i] = inv[i+1] * (i+1) % mod;
	if(n <= 10){
		Dfs(1);
		cout << ans << "\n";
		return 0;
	}
	if(m == 1){
		int now = 0, j = 0, tmp; ans = 1;
		for(int i = 1; i <= n; ++i){
			while(j < i) now += cnt[j], j++;
			if(s[i-1] == '0') tmp++;
			else (ans *= now) %= mod, now--;
		}
		(ans *= fac[tmp]) %= mod;
		cout << (fac[n] - ans + mod) % mod << "\n";
		return 0;
	}
	if(cnt[0] == 0 && opA) cout << fac[n] << "\n";
	else cout << "0\n";
	return 0;
}