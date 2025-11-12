#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
const int mod = 998244353 ;
int n , a [ 5001 ] , m , f [ 5001 ] [ 5001 ] , maxn , s [ 5001 ] , l ;
ll sum ;
ll c ( int x , int y )
{
	ll k = 1 , p = 1 ;
	for ( int r = x ; r >= x - y +1 ; r-- )
	k *= r ;
	for ( int r = 1 ; r <= y ; r++ )
	p *= r ;
	return k / p ;	
}
int main ()
{
	freopen ( "polygon.in" , "r" , stdin ) ;
	freopen ( "polygon.out" , "w" , stdout ) ;
	cin >> n ;
	for ( int i = 1 ; i <= n ; i++ )
	{
		cin >> a [ i ] ;
//		maxn = max ( maxn , a [ i ] ) ;
		s [ i ] = s [ i - 1 ] + a [ i ] ;
	}
	m = 3 ;
	sort ( a + 1 , a + n + 1 ) ;
	if ( a [ n ] == 1 ) 
		for ( int i = 3 ; i <= n ; i++ )
		{
			sum += c ( n , i ) % mod ;
			sum %= mod ; 
		}
		else
		if ( n == 3 )
		{
			if ( a [ 1 ] + a [ 2 ] > a [ 3 ])
			sum = 1 ;
		}
		cout << sum << endl ;	
	return 0 ;
	}

