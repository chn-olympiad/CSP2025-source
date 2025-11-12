#include<bits/stdc++.h>
using namespace std ;
const int N = 1e6 + 7 ;
char str[N] ; 
int t[15] ;
signed main() {
	freopen( "number.in" , "r" , stdin ) ;
	freopen( "number.out" , "w" , stdout ) ;
	ios::sync_with_stdio(0) ;
	cin.tie(0) ;
	cout.tie(0) ;
	cin >> str + 1 ;
	for ( int i = 1 ; str[i] != 0 ; i ++ ) {
		if ( str[i] >= '0' and str[i] <= '9' ) {
			t[ str[i] - '0' ] ++ ;
		}
	}for ( int i = 9 ; i >= 0 ; i -- ) {
		while ( t[i] ) {
			cout << i ;
			t[i] -- ;
		}
	}
	return 0 ;
}
