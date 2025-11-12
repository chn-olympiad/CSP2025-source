# include <bits/stdc++.h>
using namespace std ;typedef long long itn ;
itn n , a [ 5050 ] ;
itn s [ 5050 ] ;
itn ans ;
itn dp [ 5050 ] [ 5050 ] ;
const itn mod = 988244353 ;
itn wei_shu ( itn x ) {
	itn y = 0 ;
	while ( x ) 
	{
		x = x & ( x - 1 ) ;
		y ++ ;
	}
	return y ;
}

void solve ( ) {
	cin >> n ;
	for ( itn i = 1 ; i <= n ; i ++ ) 
	{
		cin >> a [ i ] ;
		s [ i ] = s [ i - 1 ] + a [ i ] ;
	}
	if ( n <= 23 ) 
	{
		for ( itn i = 1 ; i <= 1 << n ; i ++ ) 
		{
			itn wei = wei_shu ( i ) ;
			if ( wei >= 3 && wei <= n ) 
			{
//				cout << wei << " ? " << i << " : " ;
				itn sum = 0 , big = 0 ;
				for ( itn ii = 1 ; ii <= 23 ; ii ++ ) 
				{
					itn j = 1 << ( ii - 1 ) ;
//					cout << j << " " ;
					if ( ( j & i ) == j ) 
					{
						big = max ( big , a [ ii ] ) ;
//						cout << a [ ii ] << " " ;
						sum += a [ ii ] ;
					}
				}
//				cout << "||" << sum << " " << big ;
				if ( sum > big * 2 ) 
				{
					ans ++ ;
//					cout << "Yes" ;
				}
//				else 
//				{
////					cout << "No" ;
//				}
//				cout << "\n" ;
			}
		}
	}
//	else 
//	{
//		assert ( 0 ) ; //cry!
//	}
	cout << ans % mod ;
}
int main ( ) {
	freopen ( "polygon.in" , "r" , stdin ) ;
	freopen ( "polygon.out" , "w" , stdout ) ;
	solve ( ) ;
//	cout << wei_shu ( 17 ) ;
	return 0 ;
}
