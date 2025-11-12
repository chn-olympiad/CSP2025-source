#include <bits/stdc++.h>

using namespace std ;

#define ll long long 

const int N = 500010 ;

int n , k ;

int dp[N] ;

int s[N] ;

int a[N] ;


int tong[(1 << 21)] ;

void stdd () {
	int lst = 0 ;
	for (int i = 1 ; i <= n ; ++i) {
		dp[i] = max (dp[i] , lst) ;
		if (a[i] == k) dp[i] = max (dp[i] , dp[i - 1] + 1) ;
		if (tong[s[i] ^ k] != 0 || (s[i] ^ k) == 0)dp[i] = max (dp[i] , dp[tong[s[i] ^ k]] + 1) ;
		tong[s[i]] = i ;
//		printf ("%lld\n" , tong[s[]])
//		printf ("%lld\n" , dp[i]) ;
		lst = max (lst , dp[i]) ;
	}
	printf ("%d" , lst) ;
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
   freopen ("xor.in" , "r" , stdin) ;
   freopen ("xor.out" , "w" , stdout) ;
  
// 	cin >> n >> k ;
 	
 	n = read () , k = read () ;
	 
	 
	for (int i = 1 ; i <= n ; ++i) {
//		cin >> a[i] ;
		a[i] = read() ; 
		s[i] = s[i - 1] ^ a[i] ;
	} 
	
	
 stdd() ;
	
//	solve1() ;
	


  return 0 ;
}
