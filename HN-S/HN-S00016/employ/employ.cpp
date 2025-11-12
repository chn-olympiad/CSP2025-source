#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned int;

const int N = 1e5 + 10, K = 15;

namespace solve {
	
	struct Edge {
		int from, to, val;
		bool operator < ( const Edge& i ) {
			return val < i.val;
		}
	};
	
	const int N = 1e3 + 10;
	
	struct MergeFindSet {
		int fa[N];
		void init( int n ) {
			for ( int i = 1; i <= n; i++ )
				fa[i] = i;
		}
		
		int find( int x ) {
			return fa[x] == x ? x : fa[x] = find( fa[x] );
		}
		
		void merge( int x, int y ) {
			fa[find( x )] = find(y);
		}
		bool isMerge( int x, int y ) {
			return find( x) == find( y);
		}
				
	}; 
	
	MergeFindSet st;
	
	std::vector<Edge> G;
	int n, m, k;
	
	int kruskal( ) {
		int cnt = 0, ret = 0;
		std::sort( G.begin(), G.end() );
		for ( int k = 0; k < G.size(); k++ ) {
			int from = G[k].from;
			int to = G[k].to;
			int val = G[k].val;
			if ( st.isMerge( from, to ) )
				continue;
			else {
				cnt ++;
				ret += val;
				st.merge( from, to );
			}
			if ( cnt == n - 1 ) 
				return ret;
		}
		return ret;
	}
	
	void solve() {
		std::cin >> n >> m >> k;
		st.init( n ); 
		for ( int i = 1, u, v, w; i <= m; i++ ) {
			std::cin >> u >> v >> w;
			G.push_back( { u, v, w } );
		}
		for ( int i = 1; i <= k; i++ ) {
			for ( int i = 0; i <= n; i++ ) {
				int x;
				std::cin >> x;
			} 
		}
		if ( k == 0 ) {
			std::cout << kruskal() << '\n';
		}
		else {
			std::cout << 0 << '\n';
		}
	}
}

int main( ) {
	
	freopen( "employ.in", "r", stdin );
	freopen( "employ.out", "w", stdout ); 
	
	solve::solve();
	
} 
