#include <bits/stdc++.h>
using namespace std ;
string s ;
int num_line [ 1000005 ] ;
int n ;
int main ( ) {
	freopen ( "number.in" , "r" , stdin ) ;
	freopen ( "number.out" , "w" , stdout ) ;
	cin >> s ;
	for ( int i = 0 ; i < s.length ( ) ; i++ ) if ( s [ i ] >= '0' && s [ i ] <= '9' ) {
		num_line [ n ] = s [ i ] - '0' ;
		n++ ;
	} 
	sort ( num_line , num_line + n ) ;
	for ( int i = n - 1 ; i >= 0 ; i-- ) cout << num_line [ i ] ;
} 
