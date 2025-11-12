#include<bits/stdc++.h>
using namespace std ;
int d [ 10005 ] , anss [ 10005 ] , y [ 11 ] ;
bool vis [ 10005 ] , q [ 10005 ] , b [ 11 ] ;
int n , m , k , f , p , u , v , w , c ;
long long ans ;
void solve1 ( ) {
	int sum [ 10005 ] [ 10005 ] ;
	for ( int i = 1 ; i <= m ; i ++ ) {
		sum [ u ] [ v ] = w + 1 ;
		sum [ v ] [ u ] = w + 1 ;
	}
	vis [ 1 ] = true ;
	for ( int i = 2 ; i <= n ; i ++ ) {
		d [ i ] = sum [ 1 ] [ i ] ;
		if ( d [ i ] == 0 ) {
			d [ i ] = INT_MAX ;
		}
	}
	for ( int t = 1 ; t < n ; t ++ ) {
		f = INT_MAX ;
		for ( int i = 2 ; i <= n ; i ++ ) {
			if ( vis [ i ] == false ) {
				if ( d [ i ] < f && d [ i ] != 0 ) {
					f = d [ i ] ;
					p = i ;
				}
			}
		}
		vis [ p ] = true ;
		ans += f ;
		for ( int i = 1 ; i <= n ; i ++ ) {
			if ( sum [ p ] [ i ] != 0 ) {
				d [ i ] = min ( d [ i ] , sum [ p ] [ i ] ) ;
			}
		}
	}
	ans -= n ;
	ans += 1 ;
	printf ( "%lld" , ans ) ;
	return ;
}
void solve2 ( ) {
	int sum [ 1005 ] [ 1005 ] ;
	for ( int i = 1 ; i <= m ; i ++ ) {
		scanf ( "%d%d%d" , &u , &v , &w ) ;
		sum [ u ] [ v ] = w + 1 ;
		sum [ v ] [ u ] = w + 1 ;
	}
	for ( int i = 1 ; i <= k ; i ++ ) {
		scanf ( "%d" , &anss [ i ] ) ;
		for ( int j = 1 ; j <= n ; j ++ ) {
			scanf ( "%d" , &c ) ;
			sum [ n + i ] [ j ] = anss [ i ] + c + 1 ;
			sum [ j ] [ n + i ] = anss [ i ] + c + 1 ;
		}
	}
	vis [ 1 ] = true ;
	for ( int i = 2 ; i <= n ; i ++ ) {
		d [ i ] = sum [ 1 ] [ i ] ;
		if ( d [ i ] == 0 ) {
			d [ i ] = INT_MAX ;
		}
	}
	for ( int i = n + 1 ; i <= n + k ; i ++ ) {
		d [ i ] = sum [ 1 ] [ i ] ;
		if ( d [ i ] == 0 ) {
			d [ i ] = INT_MAX ;
		}
		y [ i - n ] = 1 ;
	}
	for ( int t = 1 ; t < n + k ; t ++ ) {
		f = INT_MAX ;
		for ( int i = 2 ; i <= n + k ; i ++ ) {
			if ( vis [ i ] == false && d [ i ] < f && d [ i ] != 0 ) {
				f = d [ i ] ;
				p = i ;
			}
		}
		if ( q [ p ] > 0 ) {
			b [ q [ p ] ] = true ;
		}
		vis [ p ] = true ;
		if ( p > n ) {
			for ( int i = 1 ; i <= n ; i ++ ) {
				sum [ p ] [ i ] -= anss [ p - n ] ;
				sum [ i ] [ p ] -= anss [ p - n ] ;
			}
			ans += f ;
			for ( int i = 1 ; i <= n ; i ++ ) {
				if ( sum [ p ] [ i ] != 0 && sum [ p ] [ i ] < d [ i ] ) {
					d [ i ] = sum [ p ] [ i ] ;
					q [ i ] = p - n ;
				}
			}
		}
		else {
			ans += f ;
			for ( int i = 1 ; i <= n ; i ++ ) {
				if ( sum [ p ] [ i ] != 0 && sum [ p ] [ i ] < d [ i ] ) {
					d [ i ] = sum [ p ] [ i ] ;
					q [ i ] = 0 ;
				}
			}
			for ( int i = n + 1 ; i <= n + k ; i ++ ) {
				if ( sum [ p ] [ i ] != 0 && sum [ p ] [ i ] < d [ i ] ) {
					d [ i ] = sum [ p ] [ i ] ;
					y [ i ] = p ;
				}
			}
		}
	}
	ans -= ( ( n + k ) - 1 ) ;
	int num = 0 ;
	for ( int i = 1 ; i <= k ; i ++ ) {
		if ( b [ i ] == false ) {
			num += anss [ i ] ;
			num += ( sum [ n + i ] [ y [ i ] ] - 1 ) ;
		}
	}
	ans -= num ;
	printf ( "%lld" , ans ) ;
	return ;
}
int main ( ) {
	freopen ( "road.in" , "r" , stdin ) ;
	freopen ( "road.out" , "w" , stdout ) ;
	cin >> n >> m >> k ;
	if ( k == 0 ) {
		solve1 ( ) ;
	}
	else {
		solve2 ( ) ;
	}
	return 0 ;
} 
