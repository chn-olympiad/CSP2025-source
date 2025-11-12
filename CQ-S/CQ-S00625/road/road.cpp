#include <bits/stdc++.h>

#ifndef CRT
#define endl '\n'
#endif

using namespace std ;

typedef long long ll ;
typedef unsigned long long ull ;
typedef long double ld ;

const ll N = 1e5 + 5 , M = 15 ;

ll n , m , k ;

ll a [M] [N] , c [M] ;

struct node
{
	ll u , v , w ; 
	node () {}
	node ( const ll & u , const ll & v , const ll & w ) : u ( u ) , v ( v ) , w ( w ) {}
	friend bool operator < ( const node & a , const node & b )
	{
		return a.w < b.w ;
	}
} ;

vector <node> edge , town [1 << M] ;

namespace CR200J
{
	ll fa [N] ;
	ll find ( ll u )
	{
		return ( fa [u] == u ) ? u : ( fa [u] = find ( fa [u] ) ) ;
	}
	void main ()
	{
		ll ans = 1e18 ;
		for ( ll i = 0 ; i < ( 1 << k ) ; i ++ )
		{
//			cerr << bitset <10> ( i ) << endl ;
//			vector <node> edge1 = edge , edge2 ;
			if ( i != 0 )
			{
				ll num1 = i - ( i & ( -i ) ) , num2 = i & ( -i ) ;
//				town [i] = town [num] ;
//				vector <node> tmp ;
//				cerr << num1 << " " << num2 << endl ;
				vector <node> tmp ;
				merge ( town [num1].begin () , town [num1].end () , 
					    town [num2].begin () , town [num2].end () , 
						back_insert_iterator <vector <node>> ( tmp ) ) ;
				town [i].swap ( tmp ) ;
			}
			ll now = 0 ;
			for ( ll j = 1 ; j <= k ; j ++ )
			{
				if ( ( i >> j - 1 ) & 1 )
				{
//					for ( ll k = 1 ; k <= n ; k ++ )
//					{
//						town [i].emplace_back ( n + j , k , a [j] [k] ) ;
//					}
//					edge2.clear () ;
//					merge ( edge1.begin () , edge1.end () , town [j].begin () , town [j].end () , back_insert_iterator <vector <node>> ( edge2 ) ,less <node> ()) ;
//					edge1 = edge2 ;
					now += c [j] ;
				}
			}
//			cerr << "***" << endl ;
//			for ( auto x : town [i] )
//			{
//				cerr << x.u << " " << x.v << " " << x.w << endl ;
//			}
//			sort ( edge1.begin () , edge1.end () ) ;
//			cerr << "CRT" << endl ;
			iota ( fa + 1 , fa + 1 + n + k , 1 ) ;
			for ( auto x : town [i] )
			{
				ll u = x.u , v = x.v , w = x.w ;
				ll fau = find ( u ) , fav = find ( v ) ;
				if ( fau == fav )
				{
					continue ;
				}
				fa [fau] = fav ;
				now += w ;
			}
			ans = min ( ans , now ) ;
		}
		cout << ans << endl ;
	}
}

namespace CRH5G
{
	ll fa [N] ;
	ll find ( ll u )
	{
		return ( fa [u] == u ) ? u : ( fa [u] = find ( fa [u] ) ) ;
	}
	void main ()
	{
		for ( ll i = 1 ; i <= k ; i ++ )
		{
			for ( ll j = 1 ; j <= n ; j ++ )
			{
				edge.emplace_back ( i + n , j , a [i] [j] ) ;
			}
		}
		sort ( edge.begin () , edge.end () ) ;
		iota ( fa + 1 , fa + 1 + n + k , 1 ) ;
		ll ans = 0 ;
		for ( auto x : edge )
		{
			ll u = x.u , v = x.v , w = x.w ;
			ll fau = find ( u ) , fav = find ( v ) ;
			if ( fau == fav )
			{
				continue ;
			}
			fa [fau] = fav ;
			ans += w ;
		}
		cout << ans << endl ;
	}
}

signed main ()
{
//#if not defined ( CRCC )
	freopen ( "road.in" , "r" , stdin ) ;
	freopen ( "road.out" , "w" , stdout ) ;
//#endif 
	ios::sync_with_stdio ( 0 ) ;
	cin.tie ( 0 ) ;
	cout.tie ( 0 ) ;
	cin >> n >> m >> k ;
	for ( ll i = 1 ; i <= m ; i ++ )
	{
		ll u ,v , w ;
		cin >> u >> v >> w ;
		edge.emplace_back ( u , v , w ) ; 
	}
	sort ( edge.begin () , edge.end () ) ;
	town [0] = edge ;
	bool flagA = 1 ;
	for ( ll i = 1 ; i <= k ; i ++ )
	{
		cin >> c [i] ;
		flagA &= c [i] == 0 ;
		for ( ll j = 1 ; j <= n ; j ++ )
		{
			cin >> a [i] [j] ;
			town [1 << i - 1].emplace_back ( n + i , j , a [i] [j] ) ;
		}
		sort ( town [1 << i - 1].begin () , town [1 << i - 1].end () ) ;
	}
//	cerr << k << endl ;
	if ( flagA )
	{
		CRH5G::main () ;
		exit ( 0 ) ;
	}
	if ( k <= 5 )
	{
		CR200J::main () ;
	}
//	else
//	{
//		cerr << "CRT" << endl ;
//	}
	return 0 ;
}
