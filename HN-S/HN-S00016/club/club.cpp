#include <bits/stdc++.h>
#define int long long
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned int;

namespace solve {
	
	const int N = 1e5 + 10;
	
	struct P {
		int id;
		std::array<std::array<int, 2>, 3> dep;
	};
	
	P val[N];
	int n, cnt[4], from, sum;
	
	
	int getMax( int id, int ex ) {
		int max = -0x3f3f3f3f;
		for( auto ik : { 0, 1, 2 } ) {
			if ( ik == ex )
				continue ;
			max = std::max( max, val[id].dep[ik][0] );
		}
		return max;
	}
	
	struct K {
		int id, val, k;
		bool operator < ( const K& i ) const {
			return ( i.val - getMax( i.id, k ) ) < this->val- getMax( id, k );
		}
	}; 
	
	std::priority_queue<K> get[4];
	
	bool cmp( std::array<int, 2> a, std::array<int, 2> b ) {
		return a[0] > b[0];
	};
	
	
	
	int insertD( int from, int to, P w ) {
//		std::cout << to <<'\n';
		if ( get[to].size() < ( n / 2 ) ) {
//			std::cout << w.id << ' ' << to << ' ' << w.dep[to][0] << '\n'; 
			return w.dep[to][0];
		}
		else {
			int max = -0x3f3f3f3f;
			for ( auto j : { 0, 1, 2 } ) {
				if ( j == from || j == to )
					continue;
				max = std::max( max, insertD( to, j, val[get[to].top().id] ) );
			}
//			std::cout << max << '\n';
			return max - get[to].top().val + w.dep[to][0];
		}
	}
	

	void insert( int from, int to, P w ) {
		if ( get[to].size() < ( n / 2 ) ) {
			get[to].push( { w.id, w.dep[to][0], to } );
			return ;
		}
		else {
			int max = -0x3f3f3f3f, pos = 0;
			for ( auto j : { 0, 1, 2 } ) {
				if ( j == from || j == to )
					continue;
				max = std::max( max, insertD(to, j, val[get[to].top().id]) );
			}
			for ( auto j : { 0, 1, 2 } ) {
				if ( j == from || j == to )
					continue;
				if ( max == insertD(to, j, val[get[to].top().id])) {
					pos = j;
					break ;
				}
			}
			insert( to, pos, val[get[to].top().id] );
			get[to].pop();
		}
	}
	
	void solve() {
		
		sum = 0;
		memset( val, 0, sizeof val );
		memset( cnt, 0, sizeof cnt );
		
		for ( auto j : { 0, 1, 2 } ) {
				while( get[j].size() )
					get[j].pop();
			}
		std::cin >> n;
		for ( int i = 1; i <= n; i++ ) {
			for ( auto j : { 0, 1, 2 } ) {
				std::cin >> val[i].dep[j][0];
				val[i].dep[j][1] = j;
			}
			val[i].id = i;
		}
		
		for ( int i = 0; i <= 2; i++ )
			while ( get[i].size() ) get[i].pop();
		
		for ( int i = 1; i <= n; i++ ) {
			int max = -0x3f3f3f3f, pos = -1;
			for ( auto j : { 0, 1, 2 } ) {
				max = std::max( max, insertD(j, j, val[i]));
			}
//			if ( i== 2 ) std::cout << max << '\n';
			for ( auto j : { 0, 1, 2 } ) {
				if ( max == insertD( j, j, val[i] ) ) {
					pos = j;
					break ;
				}
			}
			std::cout << pos << '\n';
			sum += insertD( pos, pos, val[i] );
			insert( pos, pos, val[i] );
//			std::cout << insertD( pos, pos, val[i] ) << '\n';
			
		}
		
		std::cout << sum << '\n';
	}
	
} 

signed main() {
	freopen( "club.in", "r", stdin );
	freopen( "club.out", "w", stdout );
	
	std::ios::sync_with_stdio( 0 );
	std::cin.tie( 0 ), std::cout.tie( 0 );
	
	int T; std::cin >> T;
	while ( T-- ) 
		solve::solve();
}


