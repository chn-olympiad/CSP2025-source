#include<bits/stdc++.h>
using namespace std ;
int t , n , a_step , b_step , c_step , k ;
long long sum ;
bool s ;
struct node {
	int dis , ans ;
} Node [ 100005 ] ;
int p [ 100005 ] ;
bool cmp ( int x , int y ) {
	return x < y ;
}
void solve ( ) {
	cin >> n ;
	a_step = 0 ;
	b_step = 0 ;
	c_step = 0 ;
	sum = 0 ;
	k = 0 ;
	s = false ;
	for ( int i = 1 ; i <= n ; i ++ ) {
		int a , b , c ;
		scanf ( "%d%d%d" , &a , &b , &c ) ;
		if ( a >= b && a >= c ) {
			sum += a ;
			Node [ i ].dis = ( a - max ( b , c ) ) ;
			Node [ i ].ans = 1 ;
			a_step ++ ;
		}
		else if ( b >= a && b >= c ) {
			sum += b ;
			Node [ i ].dis = ( b - max ( a , c ) ) ;
			Node [ i ].ans = 2 ;
			b_step ++ ;
		}
		else if ( c >= a && c >= b ) {
			sum += c ;
			Node [ i ].dis = ( c - max ( a , b ) ) ;
			Node [ i ].ans = 3 ;
			c_step ++ ;
		}
	}
	if ( a_step > n / 2 ) {
		s = true ;
		for ( int i = 1 ; i <= n ; i ++ ) {
			if ( Node [ i ].ans == 1 ) {
				k ++ ;
				p [ k ] = Node [ i ].dis ;
			}
		}
	}
	else if ( b_step > n / 2 ) {
		s = true ;
		for ( int i = 1 ; i <= n ; i ++ ) {
			if ( Node [ i ].ans == 2 ) {
				k ++ ;
				p [ k ] = Node [ i ].dis ;
			}
		}
	}
	else if ( c_step > n / 2 ) {
		s = true ;
		for ( int i = 1 ; i <= n ; i ++ ) {
			if ( Node [ i ].ans == 3 ) {
				k ++ ;
				p [ k ] = Node [ i ].dis ;
			}
		}
	}
	if ( s == true ) {
		sort ( p + 1 , p + k + 1 , cmp ) ;
		for ( int i = 1 ; i <= k - n / 2 ; i ++ ) {
			sum -= p [ i ] ;
		}
	}
	cout << sum << endl ;
	return ;
}
int main ( ) {
	freopen ( "club.in" , "r" , stdin ) ;
	freopen ( "club.out" , "w" , stdout ) ;
	scanf ( "%d" , &t ) ;
	while ( t -- ) {
		solve ( ) ;
	}
	return 0 ;
}
