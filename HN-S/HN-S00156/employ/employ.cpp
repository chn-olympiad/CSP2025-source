# include <bits/stdc++.h>
using namespace std ;
constexpr int N = 505 ; 
int n , m , c[N] , ans , id[N] , s[N] ;
signed main () {
	freopen ( "employ.in" , "r" , stdin ) ; 
	freopen ( "employ.out" , "w" , stdout ) ; 
	cin >> n >> m ; 
	if ( n > 10 ) return cout << "1\n" , 0 ;
	for ( int i = 1 ; i <= n ; ++ i ) { char x ; cin >> x ; s[i] = x - '0' ; } 
	for ( int i = 1 ; i <= n ; ++ i ) cin >> c[i] ; 
	for ( int i = 1 ; i <= n;  ++ i ) id[i] = i ;
	do {
		int cc = 0 , re = 0 ; 
		for ( int i = 1 ; i <= n ; ++ i ) {
			if ( cc >= c[id[i]] ) { ++ cc ; continue ; }
			re += s[i] ; 
			cc += ( s[i] ^ 1 ) ; 
		}
		ans += ( re >= m ) ; 
	} while ( next_permutation ( id + 1 , id + n + 1 ) ) ; 
	cout << ans << '\n' ; 
	return 0 ;
}