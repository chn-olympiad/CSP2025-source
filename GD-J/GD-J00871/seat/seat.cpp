#include <bits/stdc++.h>
using namespace std ;
int n , m , a[105] , mc = 1 ;
int main () {
	std::ios::sync_with_stdio (0) , cin.tie (0) , cout.tie (0) ;
	freopen ( "seat.in" , "r" , stdin ) ;
	freopen ( "seat.out" , "w" , stdout ) ; 
	cin >> n >> m ;
	for ( int i = 1 ; i <= n * m ; i ++ )
		cin >> a[i] ;
	for ( int i = 2 ; i <= n * m ; i ++ )
		if ( a[i] > a[1] ) mc ++ ;
	int x = mc / n ;
	if ( mc % n != 0 ) x ++ ;
	int y = mc % ( 2 * n ) ;
	if ( y < n && y == 0 ) y ++ ;
	else if ( y > n ) y = 2 * n - y + 1 ;
	cout << x << " " << y ;
	return 0 ;
}
