#include <bits/stdc++.h>
using namespace std ;
int n , m , a [ 100005 ] , seat [ 105 ] [ 105 ] , cnt_seat , r , r_i , r_j ;
bool cmp ( int a , int b ) { return a > b ; }
int main ( ) {
	freopen ( "seat.in" , "r" , stdin ) ;
	freopen ( "seat.out" , "w" , stdout ) ;
	cin >> n >> m ;
	for ( int i = 1 ; i <= n * m ; i++ ) cin >> a [ i ] ;
	r = a [ 1 ] ;
	sort ( a + 1 , a + n * m + 1 , cmp ) ;
	//for ( int i = 1 ; i <= n * m ; i++ ) cout << a [ i ] << ' ' ;
	for ( int i = 1 ; i <= m ; i++ ) {
		if ( i % 2 == 1 ) {
			for ( int j = 1 ; j <= n ; j++ ) {
				cnt_seat++ ;
				seat [ i ] [ j ] = a [ cnt_seat ] ; 
			}
		} else {
			for ( int j = n ; j >= 1 ; j-- ) {
				cnt_seat++ ;
				seat [ i ] [ j ] = a [ cnt_seat ] ; 
			}
		}
	}
	for ( int i = 1 ; i <= m ; i++ ) for ( int j = 1 ; j <= n ; j++ ) if ( seat [ i ] [ j ] == r ) r_i = i , r_j = j ;
	cout << r_i << ' ' << r_j ; 	
}
