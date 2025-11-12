# include <bits/stdc++.h>
using namespace std ;
typedef long long itn ;
//itn dp [ 1050 ] [ 1050 ] ;
itn n , k ;
itn a [ 500050 ] ;
itn ans ;
//void work1 ( ) {
//	for ( itn i = 1 ; i <= n ; i ++ ) 
//	{
//		dp [ i ] [ i ] = a [ i ] ;
//	}
//	for ( itn l = 1 ; l <= n - 1 ; l ++ ) 
//	{
//		for ( itn r = l + 1 ; r <= n ; r ++ ) 
//		{
//			dp [ l ] [ r ] = dp 
//		}
//	}
//}
void solve ( ) {
	cin >> n >> k ;
	for ( itn i = 1 ; i <= n ; i ++ ) 
	{
		cin >> a [ i ] ;
	}
	itn num = 0 ;
	itn wz = 1 ;
	for ( itn i = 1 ; i <= n ; i ++ ) 
	{
		num ^= a [ i ] ;
//		cout << num << " " ;
		if ( num >= k ) 
		{
			ans ++ ;
			num = 0 ;
			wz = i ;
		}
	}
	cout << ans ;
}
int main ( ) {
	freopen ( "xor.in" , "r" , stdin ) ;
	freopen ( "xor.out" , "w" , stdout ) ;
	solve ( ) ;
	return 0 ;
}