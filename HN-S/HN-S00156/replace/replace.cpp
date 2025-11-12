# include <bits/stdc++.h>
# define ull unsigned long long 
# define pb push_back
using namespace std ;
constexpr int N = 2e5 + 5 ;  
map < pair < int , int  > , int > mp ; 
int n , q ; 
string s[N][2] ; 
constexpr ull base = 13 ; 
ull pw[N] , hat1[N] , hat2[N] ; 
ull ght1 ( int l , int r ) { return hat1[r] - hat1[l - 1] * pw[r - l + 1] ; }
ull ght2 ( int l , int r ) { return hat2[r] - hat2[l - 1] * pw[r - l + 1] ; }
static inline void solve () {
	string t1 , t2 ; 
	cin >> t1 >> t2 ; 
	int ans = 0 ; 
	int m = (int) t1.size() ; 
	t1 = ' ' + t1 , t2 = ' ' + t2 ;
	if ( t1.size() != t2.size() ) return cout << "0\n" , void () ; 
	vector < int > diff ; 
	for ( int i = 1 ; i <= m ; ++ i ) 
		if ( t1[i] != t2[i] ) diff.pb ( i ) ;
	int l = diff[0] , r = diff[(int)diff.size() - 1] ; 
	for ( int i = 1 ; i <= m ; ++ i ) 
		hat1[i] = hat1[i - 1] * base + (ull) ( t1[i] - 'a' + 1 ) , 
		hat2[i] = hat2[i - 1] * base + (ull) ( t2[i] - 'a' + 1 ) ;
	for ( int i = l ; i >= 1 ; -- i ) for ( int j = r ; j <= m ; ++ j ) 
	ans += mp[ make_pair ( ght1 ( i , j ) , ght2 ( i , j ) ) ] ; 
	return cout << ans << '\n' , void () ; 
}
signed main () {
	ios::sync_with_stdio ( false ) , cin.tie ( 0 ) , cout.tie ( 0 ) ; 
	freopen ( "replace.in" , "r" , stdin ) ; 
	freopen ( "replace.out" , "w" , stdout ) ;
	pw[0] = 1 ; 
	for ( int i = 1 ; i < N ; ++ i ) pw[i] = pw[i - 1] * base ; 
	cin >> n >> q ; 
	for ( int i = 1 ; i <= n ; ++ i ) {
		cin >> s[i][0] >> s[i][1] ;
		ull hs0 = 0 , hs1 = 0 ; 
		for ( int j = 0 ; j < (int) s[i][0].size() ; ++ j ) 
			hs0 = hs0 * base + (ull) ( s[i][0][j] - 'a' + 1 ) ; 
		for ( int j = 0 ; j < (int) s[i][1].size() ; ++ j ) 
			hs1 = hs1 * base + (ull) ( s[i][1][j] - 'a' + 1 ) ; 
		mp[ make_pair ( hs0 , hs1 ) ] ++ ; 
	}
	while ( q-- ) solve () ; 
	return 0 ;
}