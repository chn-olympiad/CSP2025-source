# include <bits/stdc++.h>
# define int long long 
# define pb push_back
using namespace std ; 
constexpr int N = 1e5 + 5 , M = 1e6 + 5 ; 
int a[12][N] , cnt , s[N] , cv , n , m , c[N] , k , ans = 1e18 ;
struct node { int u , v , w ; } g[3 * M] , G[3 * M] ; 
static inline int find ( int x ) { return s[x] == x ? x : s[x] = find ( s[x] ) ; }
static inline void merge ( int x , int y ) {
	int fx = find ( x ) , fy = find ( y ) ; 
	if ( fx == fy ) return ; 
	s[fy] = fx ; return ; 
}
vector < node > org ; 
static inline int kruskal ( bool op ) { 
	int res = 0 , aaa = 0 ; 
	iota ( s + 1 , s + N , 1 ) ; 
	sort ( G + 1 , G + cnt + 1 , [&] ( node a , node b ) { return a.w < b.w ; } ) ;  
	for ( int i = 1 ; i <= cnt ; ++ i ) {
		if ( find ( G[i].u ) == find ( G[i].v ) ) continue ; 
		merge ( G[i].u , G[i].v ) , res += G[i].w ;
		if ( op == 0 ) {
			org.pb ( G[i] ) ;
		} 
		if ( ++ aaa == n + cv - 1 ) break ; 
	}
	return res ; 
}
static inline void solve ( int s ) {
	vector < int > chos ; int sz = 0 ; 
	for ( int j = 0 ; j < k ; ++ j ) if ( s >> j & 1 ) 
	chos.pb ( j ) , sz += c[j] ; 
	cnt = 0 , cv = 0 ;
	for ( int i = 1 ; i <= (int)org.size() ; ++ i ) G[++cnt] = org[i - 1] ; 
	for ( auto x : chos ) {
		++ cv ; 
		for ( int j = 1 ; j <= n ; ++ j )
		G[++cnt] = { n + cv , j , a[x][j] } ;
	}
	int vv = kruskal ( 1 ) + sz ; 
	ans = min ( ans , vv ) ; 
}
signed main () {
	ios::sync_with_stdio ( false ) , cin.tie ( 0 ) , cout.tie ( 0 ) ;
	freopen ( "road.in" , "r" , stdin ) , freopen ( "road.out" , "w" , stdout ) ; 
	cin >> n >> m >> k ; 
	for ( int i = 1 ; i <= m ; ++ i ) cin >> g[i].u >> g[i].v >> g[i].w ; 
	bool flag = 1 ; 
	for ( int i = 0 ; i < k ; ++ i ) {
		cin >> c[i] ;
		int mn = 1e18 ; 
		for ( int j = 1 ; j <= n ; ++ j )
			cin >> a[i][j] , mn = min ( mn , a[i][j] ) ; 
	}
	for ( int i = 1 ; i <= m ; ++ i ) G[++cnt] = g[i] ; 
	ans = min ( ans , kruskal ( 0 ) ) ; cnt = 0 ; 
	for ( int i = 1 ; i <= (int)org.size() ; ++ i ) G[++cnt] = org[i - 1] ; 
	for ( int s = 0 ; s < ( 1 << k ) ; ++ s ) solve ( s ) ; 
	return cout << ans << '\n' , 0 ;
}
// 阿斯蒂芬个后胶开裂