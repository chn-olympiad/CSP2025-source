#include <bits/stdc++.h>

#ifndef CRT
#define endl '\n'
#endif

using namespace std ;

typedef long long ll ;
typedef unsigned long long ull ;
typedef long double ld ;

const ll N = 505 , mod = 998244353 ;

ll n , m , c [N] ;

string s ;

ll frc [N] ;

void init ()
{
	frc [0] = 1 ;
	for ( ll i = 1 ; i <= 500 ; i ++ )
	{
		frc [i] = frc [i - 1] * i % mod ;
	}
}

namespace CR200J
{
	void main ()
	{
		sort ( c + 1 , c + 1 + n ) ;
		map <ll,ll> cnt ;
		for ( ll i = 1 ; i <= n ; i ++ )
		{
			cnt [c [i]] ++ ;
		}
		ll ans = 0 ;
		do
		{
			ll now = 0 ;
			for ( ll i = 1 , j = 0 ; i <= n ; i ++ )
			{
				if ( j >= c [i] || s [i] == '0' )
				{
					j ++ ;
					continue ;
				}
				now ++ ;
			}
			ans += ( now >= m ) ;
		} while ( next_permutation ( c + 1 , c + 1 + n ) ) ;
		for ( auto x : cnt )
		{
			ans = ans * frc [x.second] % mod ;
		}
		cout << ans << endl ;
	}
}

signed main ()
{
//#if not defined ( CRCC ).
	freopen ( "employ.in" , "r" , stdin ) ;
	freopen ( "employ.out" , "w" , stdout ) ;
//#endif 
	ios::sync_with_stdio ( 0 ) ;
	cin.tie ( 0 ) ;
	cout.tie ( 0 ) ;
	cin >> n >> m >> s ;
	init () ;
	s.insert ( 0 , " " ) ;
	bool flagA = 1 ;
	for ( ll i = 1 ; i <= n ; i ++ )
	{
		flagA &= s [i] == '1' ;
	}
	for ( ll i = 1 ; i <= n ; i ++ )
	{
		cin >> c [i] ;
	}
//	if ( flagA )
//	{
////		cout << frc [n] % mod << endl ;
//		sort ( c + 1 , c + 1 + n , greater <ll> () ) ;
//		ll cnt_not0 = 0 ;
//		for ( ll i = 1 ; i <= n ; i ++ )
//		{
//			if ( c [i] == 0 )
//			{
//				break ;
//			}
//			cnt_not0 ++ ;
//		}
//		ll first_min = 
//		exit ( 0 ) ;
//	}
	if ( m == n )
	{
		sort ( c + 1 , c + 1 + n ) ;
		ll now = 0 ;
		for ( ll i = 1 , j = 0 ; i <= n ; i ++ )
		{
			if ( c [i] == 0 || s [i] == '0' )
			{
				cout << 0 << endl ;
				exit ( 0 ) ;
			}
		}
		cout << frc [n] % mod << endl ;
	}
	if ( n <= 10 )
	{
		CR200J::main () ;
	}
	return 0 ;
}
