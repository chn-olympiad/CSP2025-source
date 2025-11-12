#include<bits/stdc++.h>
using namespace std ;
int  n , m , a [ 101 ] , l , ans , x , y ;
bool cmp ( int x , int y )
{
	return x > y ;
}
int main ()
{
	freopen ( "seat.in" , "r" , stdin ) ;
	freopen ( "seat.out" , "w" , stdout ) ;
	cin >> n >> m ;
	for ( int i = 1 ; i <= n * m ; i++ )
	cin >> a [ i ] ;
	l = a [ 1 ] ;
	sort ( a + 1 , a + n * m + 1 , cmp ) ; 
	for ( int i = 1 ; i <= n * m ; i++ )
	{
	//	cout << a [ i ] << endl ;
		if ( a [ i ] == l )
		ans = i ;
	}
	x =  ( ans - 1 ) / n + 1 ;
	if ( x % 2 == 1 )
	{
		if ( ans % n == 0 )
		y = n ;
		else 
		y = ans % n ;
	}
	else 
	y = n - ( ans - 1 ) % n ;
	cout << x << ' ' << y << endl ; 
	//cout << ans ; 
	return 0 ;
	}

