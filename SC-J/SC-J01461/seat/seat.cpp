# include <bits/stdc++.h>
using namespace std ;
typedef long long itn ;
itn n , m ;
itn a [ 10000 ] ;
itn s [ 10000 ] ;
itn wz ;
void solve ( ) {
	cin >> n >> m ;
	for ( itn i = 1 ; i <= n * m ; i ++ ) 
	{
		cin >> a [ i ] ;
		s [ i ] = a [ i ] ;
	}
	sort ( s + 1 , s + n*m + 1 , greater<itn>() ) ;
	for ( itn i = 1 ; i <= n*m ; i ++ ) 
	{
		if ( s [ i ] == a [ 1 ] ) 
		{
			wz = i ;
			break ;
		}
//		cout << s [ i ] << " " ;
	}
//	cout << wz << "\n" ;
	cout << ( wz - 1 ) / m + 1 << " " ;
	if ( ( ( wz - 1 ) / m ) & 1 ) 
	{
		cout << m - ( ( wz - 1 ) % m + 1 ) ;
	}
	else 
	{
		cout << ( wz - 1 ) % m + 1 ;
	}
	
}
int main ( ) {
	freopen ( "seat.in" , "r" , stdin ) ;
	freopen ( "seat.out" , "w" , stdout ) ;
	solve ( ) ; 
	return 0 ;
}