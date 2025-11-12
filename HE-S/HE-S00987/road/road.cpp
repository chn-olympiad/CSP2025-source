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

const int N = 1e4 + 25 ,M = 1e6 + 25 ;
int n ,m ,k ,a[20][N] ,c[20] ,fa[N] ;
struct edge { 
	int u ,v ,w ;
	bool operator < (const edge &cmp) const { return w < cmp.w ;}
} e[M << 1] ;
std :: vector < edge > q1 ,q2 ;

inline int find (int x) { return x == fa[x] ? x : fa[x] = find (fa[x]) ;}

signed main () {
	freopen ("road.in" ,"r" ,stdin) ;
	freopen ("road.out" ,"w" ,stdout) ;
	read (n ,m ,k) ;
	f (i ,1 ,m ,1) {
		int u ,v ,w ; read (u ,v ,w) ;
		e[i] = (edge) { u ,v ,w} ;
		q1.emplace_back (e[i]) ;
	} f (i ,1 ,k ,1) {
		read (c[i]) ;
		f (j ,1 ,n ,1) read (a[i][j]) ;
	}
	
	std :: sort (q1.begin () ,q1.end ()) ;
	//int tot = 0 ;
	int ans = LONG_LONG_MAX ;
	f (s ,0 ,(1 << k) - 1 ,1) {
		q2.clear () ;
		int res = 0 ;
		f (i ,1 ,k ,1) {
			if (s & (1 << i - 1)) {
				res += c[i] ; fa[i + n] = i + n ;
				f (j ,1 ,n ,1) 
					q2.emplace_back ((edge) {j ,i + n ,a[i][j]}) ;//,tot ++ ;
			}
		} f (i ,1 ,n ,1) fa[i] = i ;
		int cnt = n + __builtin_popcount (s) ,now = 0 ;
		std :: sort (q2.begin () ,q2.end ()) ;
		int j = 0 ,sz = static_cast < int > (q2.size ()) ;
		f (i ,0 ,static_cast < int > (q1.size ()) - 1 ,1) {
			//tot ++ ;
			for (; j < sz && q2[j].w <= q1[i].w ; j++) {
				edge cur = q2[j] ;
				int u = cur.u ,v = cur.v ,w = cur.w ;
				u = find (u) ,v = find (v) ;
				if (u == v) continue ;
				fa[u] = v ,res += w ;
				if (++now == cnt - 1) break ;
			} if (now == cnt - 1) break ;
			edge cur = q1[i] ;
			int u = cur.u ,v = cur.v ,w = cur.w ;
			u = find (u) ,v = find (v) ;
			if (u == v) continue ;
			fa[u] = v ,res += w ;
			if (++now == cnt - 1) break ;
		} ans = std :: min (ans ,res) ;
	} 
	//std :: cerr << tot << '\n' ;
	std :: cout << ans << '\n' ;
	return 0 ;
}
