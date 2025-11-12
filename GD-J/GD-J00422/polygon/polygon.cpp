#include <bits/stdc++.h>
using namespace std ;
long long n , a [ 10005 ] , sum [ 10005 ] , ans ;
void dfs ( int pos , int zt , int maxa , int suma , int dpth , int need ) {
	if ( pos > n ) return ;
	if ( need < dpth ) return ;
	//cout << pos << ' ' << zt << ' ' << maxa << ' ' << suma << ' ' << dpth << ' ' << need << endl ;
	if ( zt == 0 ) {
		dfs ( pos + 1 , 0 , maxa , suma , dpth , need ) ;
		dfs ( pos + 1 , 1 , a [ pos + 1 ] , suma + a [ pos + 1 ] , dpth + 1 , need ) ;
	} else {
		if ( dpth == need ) {
			if ( suma > 2 * maxa ) ans++ ;
			return ;
		}
		dfs ( pos + 1 , 0 , maxa , suma , dpth , need ) ;
		dfs ( pos + 1 , 1 , a [ pos + 1 ] , suma + a [ pos + 1 ] , dpth + 1 , need ) ;
	}
	
}
int main ( ) {
	freopen ( "polygon.in" , "r" , stdin ) ;
	freopen ( "polygon.out" , "w" , stdout ) ;
	cin >> n ;
	for ( int i = 1 ; i <= n ; i++ ) cin >> a [ i ] ;
	sort ( a + 1 , a + n + 1 ) ;
	for ( int i = 1 ; i <= n ; i++ ) sum [ i ] = sum [ i - 1 ] + a [ i ] ;
	for ( int i = 3 ; i <= n ; i++ ) dfs ( 0 , 0 , 0 , 0 , 0 , i ) ;
	ans %= 998244353 ;
	cout << ans ;
}
