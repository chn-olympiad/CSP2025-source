#include <bits/stdc++.h>

#ifndef CRT
#define endl '\n'
#endif

using namespace std ;

typedef long long ll ;
typedef unsigned long long ull ;
typedef long double ld ;

const ll N = 2e5 + 5 ;

ll n , q ;

string s [N] [2] ;

signed main ()
{
//#if not defined ( CRCC )
	freopen ( "replace.in" , "r" , stdin ) ;
	freopen ( "replace.out" , "w" , stdout ) ;
//#endif 
	ios::sync_with_stdio ( 0 ) ;
	cin.tie ( 0 ) ;
	cout.tie ( 0 ) ;
	cin >> n >> q ;
	for ( ll i = 1 ; i <= n ; i ++ )
	{
		cin >> s [i] [1] >> s [i] [2] ;
	}
	while ( q -- )
	{
		string t1 , t2 ;
		cin >> t1 >> t2 ;
		if ( t1.size () != t2.size () )
		{
			cout << 0 << endl ;
			continue ;
		}
		ll first , last ;
		for ( ll i = 0 ; i < t1.size () ; i ++ )
		{
			if ( t1 [i] != t2 [i] )
			{
				first = i ;
				break ;
			}
		}
		for ( ll i = t1.size () - 1 ; i >= 0 ; i -- )
		{
			if ( t1 [i] != t2 [i] )
			{
				last = i ;
				break ;
			}
		}
		ll ans = 0 ;
		for ( ll i = 1 ; i <= n ; i ++ )
		{
			if ( t1.size () < s [i] [1].size () )
			{
				continue ;
			}
			for ( ll j = max ( 0ll , first - ll ( s [i] [1].size () ) + 1 ) ; j <= min ( last , ll ( t1.size () ) - ll ( s [i] [1].size () ) + 1 ) ; j ++ )
			{
				if ( t1.substr ( 0 , j ) == t2.substr ( 0 , j ) && 
					 s [i] [1] == t1.substr ( j , s [i] [1].size () ) &&
					 s [i] [2] == t2.substr ( j , s [i] [1].size () ) && 
					 t1.substr ( j + s [i] [1].size () ) == t2.substr ( j + s [i] [1].size () ) )  
				{
					ans ++ ;
//					cerr << i << " " << j << endl ;
				}
			}
		}
		cerr << ans << endl ;
	}
	return 0 ;
}
