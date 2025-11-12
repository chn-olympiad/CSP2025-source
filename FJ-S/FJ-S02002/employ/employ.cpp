#include<bits/stdc++.h>
using namespace std ;
int m , n , ans , t ;
long long sum ;
char a [ 100005 ] ;
const int mod = 998244353 ;
int main ( ) {
	freopen ( "employ.in" , "r" , stdin ) ;
	freopen ( "employ.out" , "w" , stdout ) ;
	cin >> n >> m ;
	cin >> a ;
	for ( int i = 0 ; i < strlen ( a ) ; i ++ ) {
		if ( a [ i ] == '1' ) {
			ans ++ ;
		}
	}
	for ( int i = 1 ; i <= n ; i ++ ) {
		cin >> t ;
		if ( t == 0 ) {
			ans -- ;
		}
	}
	if ( ans < m ) {
		cout << 0 ;
		return 0 ;
	}
	else {
		sum = 1 ;
		for ( int i = 1 ; i <= ans ; i ++ ) {
			sum *= ( i % mod ) ;
			sum %= mod ;
		}
	}
	cout << sum ;
	return 0 ;
}
