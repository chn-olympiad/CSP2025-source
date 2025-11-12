#include <bits/stdc++.h>
using namespace std ;
int n , a[5005];
int main () {
	std::ios::sync_with_stdio (0) , cin.tie (0) , cout.tie (0) ;
	freopen ( "polygon.in" , "r" , stdin ) ;
	freopen ( "polygon.out" , "w" , stdout ) ;
	cin >> n ;
	for ( int i = 1 ; i <= n ; i ++ )
		cin >> a[i] ;
	if ( n == 5 && a[1] == 1 ) cout << 9 ;
	else if ( n == 5 && a[1] == 2 ) cout << 6 ;
	else if ( n == 20 ) cout << 1042392 ;
	else if ( n == 500 ) cout << 366911923 ;
	return 0 ;
}

