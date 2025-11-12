#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

const int mod = 988244353 ;
const int maxn = 5e2 + 1 ;
std::string s ;
int n, m ;
int t[maxn], c[maxn] ;
int mul[maxn] ;
int tot[maxn] ;
int C[maxn][maxn] ;

signed main() {
	freopen("employ.in", "r", stdin) ;
	freopen("employ.out", "w", stdout) ;
	scanf("%d%d", &n, &m) ;
	std::cin >> s;
	C[0][0] = 1 ;
	for(int i=1 ; i<=n ; i++) {
		C[0][i] = 1 ;
		for(int j=1 ; j<=i ; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod ;
	}
//	std::cout << s ;
	for(int i=1 ; i<=n ; i++) t[i] = s[i - 1] - '0' + t[i - 1] ;
	for(int i=1 ; i<=n ; i++) ++ tot[t[i]] ;
	mul[0] = 1 ;
	for(int i=1 ; i<=n ; i++) mul[i] = mul[i - 1] * i % mod ;
//	printf("%d\n", t[n]) ;
	for(int i=1 ; i<=n ; i++) scanf("%d", &c[i]) ;
	std::sort(c + 1, c + n + 1) ;
	ll ans = 0 ;
	for(int i=m ; i<=t[n] ; i++) {
		int r = n ; ll cnt = 1 ;
		for(int k=i ; k>=1 ; k--) {
			int l = std::lower_bound(c + 1, c + n + 1, k) - c;
//			printf("%d ", l) ;
			cnt = cnt * C[r - l + 1 - (i - k)][tot[k]] % mod ;
		}
		cnt = cnt * mul[n - i] % mod ;
		ans = (ans + cnt) % mod ;
	}
	printf("%lld", ans) ;
	return 0 ;
}
