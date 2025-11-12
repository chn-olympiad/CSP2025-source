#include <bits/stdc++.h>

using namespace std ;

#define ll long long 

int n ;

const int N = 5010 ;
const int mod = 998244353 ;

int a[N] ;

ll tim = 0 ;
void solve1 () {	
	int res = 0 ;
	
	for (int i = (1 << n) - 1 ; i >= 0 ; --i) {
		ll sum = 0 , maxn = 0 ;
		int cnt = 0 ;
		for (int j = 1 ; j <= n ; ++j) {
			++tim ;
			if (((i >> (j - 1)) & 1)) {
				++cnt ;
				maxn = max (maxn , 1ll * a[j]) ;
				sum += a[j] ;
			} 
		}
		if (maxn * 2 < sum && cnt >= 3) {
			++res; 
			if (res >= mod) res %= mod ;
			++tim ;
		}
		if (tim >= 80000010) break ;
	}
	
	printf ("%lld\n" , res % mod) ;

}

ll C[N][N] ;

void init () {
	C[0][0] = 1 ;
	C[1][0] = C[1][1] = 1 ;
	for (int i = 2 ; i <= n ; ++i) {
		for (int j = 0 ; j <= i ; ++j) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod ;
		}
	}
}

void solve2 () {
	init () ; 
	ll ans = 0 ;
	for (int i = 3 ; i <= n ; ++i) {
		ans = (ans + C[n][i]) % mod ;	
	}
	printf ("%lld\n" , ans) ;
	return ;
}

int read () {
	char ch = getchar () ;
	int res = 0 ;
	int f = 1 ;
	if (ch == '-') {
		f = -1 ;
		ch = getchar () ;
	}
	while ((ch >= '0' && ch <= '9')){
		res = res * 10 + ch - '0' ;
		ch = getchar () ;
	}
	return res * f ;
}
int main () {
   freopen ("polygon.in" , "r" , stdin) ;
   freopen ("polygon.out" , "w" , stdout) ;
  
//  cin >> n; 
	n = read() ;
  
  int as = 0 ;
  
  for (int i = 1;  i <= n ; ++i) {
//  	cin >> a[i] ;
		a[i] = read() ;
  	as = max (as , a[i]) ;
  	++tim ;
  }
	
	if (as == 1) {
		solve2 () ;
		return 0 ; 
	}
	if (n <= 30){
		solve1 () ;
		return 0 ; 	
	}
	
	solve2() ;
	
  return 0 ;
}

// RP++