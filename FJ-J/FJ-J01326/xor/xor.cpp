#include<bits/stdc++.h>
using namespace std ;
const int N = 500001 ;
int n , k1 , a [ N ] , sum , s [ 1001 ] [ 1001 ] , f [ 1001 ] [ 1001 ] , l [ N ] , p ;
int s1 [ N ] ;
int main ()
{
	freopen ( "xor.in" , "r" , stdin ) ;
	freopen ( "xor.out" , "w" , stdout ) ;
	cin >> n >> k1 ;
	for ( int i = 1 ; i <= n ; i++ )
	cin >> a [ i ] ;
	if ( n <= 1000 )
	{
		for ( int i = 1 ; i <= n ; i++ )
		{
			for ( int j = 0 ; j <= n - i + 1 ; j++ )
			{
				s [ i ] [ i + j ] = s [ i ] [ i + j - 1 ] ^ a [ i + j ] ;
				if ( s [ i ] [ i + j ] == k1 )
				f [ i ] [ i + j ] = 1 ; 
			}
		}
		for ( int i = 1 ; i <= n ; i++ )
		{
			for ( int j = i ; j <= n ; j++ )
			{
				for ( int k = 1 ; k <= j - i ; k++ )
				{
					f [ i ] [ j ] = max ( f [ i ] [ j ] , f [ i ] [ j - k ] + f [ j - k + 1 ] [ j ] ) ;
				}
			}
		}
		cout << f [ 1 ] [ n ] << endl ;
	}
	else
	{
		for ( int i = 1 ; i <= n ; i++ )
		{
			if ( a [ i ] == k1 )
			{
				s1 [ i ] = 0 ;
				sum++ ; 
			}
			else
			{
				s1 [ i ] = s1 [ i - 1 ] ^ a [ i ] ; 
				if ( s1 [ i ] == k1 )
				{
					sum++ ;
					s1 [ i ] = 0 ;
				}
			 } 
		}
		cout << sum << endl ;
	}
	return 0 ;
	}

