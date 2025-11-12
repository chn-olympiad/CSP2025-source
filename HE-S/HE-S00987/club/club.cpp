#include "bits/stdc++.h"
#define int long long 
#define f(i ,m ,n ,x) for (int i = (m) ; i <= (n) ; i += (x))
#define f_(i ,m ,n ,x) for (int i = (m) ; i >= (n) ; i -= (x))

template < typename T > inline void read ( T &x ) {
	x = 0 ;
	bool flag (0) ; char ch = getchar () ;
	while (! isdigit (ch)) {
		flag = ch == '-' ;
		ch = getchar () ;
	} while (isdigit (ch)) {
		x = (x << 1) + (x << 3) + (ch ^ 48) ;
		ch = getchar () ;
	} flag ? x = - x : 0 ;
} template < typename T ,typename ...Args >
inline void read ( T &x ,Args &...tmp ) {
	read (x) ,read (tmp...) ;
}

const int N = 225 ;
int n ,a[N][5] ,dp[2][N >> 1][N >> 1][N >> 1] ;

signed main () {
	freopen ("club.in" ,"r" ,stdin) ;
	freopen ("club.out" ,"w" ,stdout) ;
	int t ; read (t) ; while (t --) {
		read (n) ; f (i ,1 ,n ,1) read (a[i][1] ,a[i][2] ,a[i][3]) ;
		if (n <= 200) {
			memset (dp ,0 ,sizeof dp) ;
			f (i ,1 ,n ,1) {
				int u = i & 1 ;
				f (j ,0 ,n >> 1 ,1) f (p ,0 ,n >> 1 ,1) f (q ,0 ,n >> 1 ,1) {
					dp[u][j][p][q] = 0 ;
					if (j) dp[u][j][p][q] = std :: max (dp[u][j][p][q] ,dp[u ^ 1][j - 1][p][q] + a[i][1]) ;
					if (p) dp[u][j][p][q] = std :: max (dp[u][j][p][q] ,dp[u ^ 1][j][p - 1][q] + a[i][2]) ;
					if (q) dp[u][j][p][q] = std :: max (dp[u][j][p][q] ,dp[u ^ 1][j][p][q - 1] + a[i][3]) ;
				}
			} int ans = 0 ;
			f (i ,0 ,n >> 1 ,1) f (j ,0 ,std :: min (n >> 1 ,n - i) ,1) f (k ,0 ,std :: min (n >> 1 ,n - i - j) ,1)
				if (i + j + k == n) ans = std :: max (ans ,dp[n & 1][i][j][k]) ;
			std :: cout << ans << '\n' ;
		} else {
			std :: priority_queue < int > q ;
			f (i ,1 ,n ,1) q.push (a[i][1]) ;
			int ans = 0 ;
			f (i ,1 ,n >> 1 ,1) ans += q.top () ,q.pop () ;
			std :: cout << ans << '\n' ;
		}
	}
	return 0 ;
}
