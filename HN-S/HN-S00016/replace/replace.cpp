#include <bits/stdc++.h>
using namespace std;

namespace solve {
	
	const int N = 2e5 + 10;
	
	std::vector<std::array<std::string, 2>> list;
	
	int posl[N], posr[N], posb[N], len;
	
	int n, q;
	bool f;
	
	void solve2() {
		std::string x, y;
		std::cin >> x >> y;
		int bPos;
		for ( int i = 0; i < x.size(); i++ ) {
			if ( x[i] == 'b' )
				bPos = i;
		} 
		for ( int i = 0; i < y.size(); i++ ) {
			if ( y[i] == 'b' ) {
				if ( i < bPos ) {
					std::cout << posr[bPos - i] << '\n';
				}
				else {
					std::cout << posl[i - bPos] << '\n';
				}
				return ;
			}
		}
	}
	
	void solve1() {
		int ans = 0;
		std::string x, y;
		std::cin >> x >> y;
//		std::cout <<'x' <<'\n';
		for ( int i = 0; i < x.size(); i++ ) {
			for ( int j = 0; j < list.size(); j++ ) {
				if ( x.size() - i < list[j][0].size() )
					continue ;
//				std::cout << x.substr( i, list[j][0].size() ) <<'\n';
				if ( x.substr( i, list[j][0].size() ) != list[j][0] )
					continue ;
				
				if ( ( i + list[j][0].size() >= x.size() ) ) {
					if ( x.substr( 0, i ) + list[j][1] == y )
						ans++; 	
				}
				else if ( x.substr( 0, i ) + list[j][1] + x.substr( i + list[j][0].size(), ( x.size() - i - list[j][0].size() )) == y )
					ans++;
			}
		}
		std::cout << ans << '\n';
	}
	
	void solve() {
		std::cin >> n >> q;
		for ( int i = 1; i <= n; i++ ) {
			std::string x, y;
			std::cin >> x >> y;
			len = std::max( x.size(), 1ull * len );
			if ( f ) {
				int posA = 0;
				for ( int j = 0; j < x.size(); j++ ) {
					if ( x[j] != 'a' && x[j] != 'b' ) {
						f = 0;
						break ;
					}
					if ( x[j] == 'a' ) {
						posA = j;
						break ;
					}
				}
				for ( int j = 0; j < x.size(); j++ ) {
					if ( y[j] != 'a' && y[j] != 'b' ) {
						f = 0;
						break ;
					}
					if ( y[j] == 'a' ) {
						if ( j < posA )
							posr[posA - j]++;
						else
							posl[j - posA]++;
						if ( j == posA )
							posr[0]++;
						break ;
					}
				}
			}
			list.push_back( { x, y } );
		}
		for ( int i = len - 1; i >= 0; i-- ) {
			posl[i] += posl[i + 1];
			posr[i] += posr[i + 1];
		}
		if ( f ) {
			for ( int i = 1; i <= q; i++ )
				solve2();
		}
		else for ( int i = 1; i <= q; i++ ) solve1();
	}
	
}

signed main() {
	freopen( "replace.in", "r", stdin );
	freopen( "replace.out", "w", stdout );
	solve::solve();
}

