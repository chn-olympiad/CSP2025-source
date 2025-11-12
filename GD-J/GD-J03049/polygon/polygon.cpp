#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using ll = long long;

#define fi first
#define se second

const int N = 5005;
const ll mod = 998244353;

int n, a[N], dp[N][N], s[N];

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n;
    for(int i=1; i<=n; ++i){
    	cin >> a[i];
	}
	if(n <= 20) { // 40 pts
		ll ans = 0;
		for(int s = 0; s < (1 << n); ++ s){
			int sum = 0, mx = 0;
			for(int i=1; i<=n; ++i){
				if(s & (1 << (i-1))){
					sum += a[i];
					mx = max(mx, a[i]);
				}
			}
			if(sum > 2 * mx) ++ ans;
		}
		return cout << ans % mod << '\n', 0;
	}
	for(int j=1; j<=3; ++j){
		if(a[j] * 2 > a[1] + a[2] + a[3]) dp[3][j] = 1;
	}
	for(int i=4; i<=n; ++i){ // 这个估计做不了特殊性质（？ 
		for(int j=1; j<=i; ++j){
			for(int k=1; k<=i; ++k){
				if(a[k] > a[j]) continue;
				dp[i][j] = (dp[i][j] + dp[i-1][k]) % mod;
			}
		}
	}
	ll ans = 0;
	for(int i=1; i<=n; ++i){
		ans = (ans + dp[n][i]) % mod; // dp 表示前 i 个棒，以 j 为最大值的方法数 
	}
	return cout << ans, 0;
}
// 背包！? 但是没时间了，270 遗憾离场。能否 1=？？？ 
//【】，失 CSP-J 300，CSP-S 何以战？？？ 
