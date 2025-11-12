#include "bits/stdc++.h"
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

const int N = 2e5 + 25 ;
char ch[N] ;
std :: string s[N][3] ,a ,b ,c ;

int main () {
	freopen ("replace.in" ,"r" ,stdin) ;
	freopen ("replace.out" ,"w" ,stdout) ;
	int n ,q ; read (n ,q) ;
	f (i ,1 ,n ,1) std :: cin >> s[i][1] >> s[i][2] ;
	//std :: cerr << judge (s[1][1] ,s[2][1]) << '\n' ;
	
	while (q--) {
		std :: cin >> a >> b ; int len = a.size () ;
		int ans = 0 ;
		f (i ,1 ,n ,1) if (a == s[i][1] && b == s[i][2]) ans ++ ;
		f (i ,1 ,len - 1 ,1) {
			f (j ,1 ,n ,1) {
				int sz = s[j][1].size () ;
				if (len - i < sz) continue ;
				//c = a.substr (i ,len - i) ;
				c = "" ; f (k ,i ,i + sz - 1 ,1) c += a[k] ;
				if (c == s[j][1]) {
					//c = a.substr (0 ,i) + s[j][2] ;
					c = "" ; 
					f (k ,0 ,i - 1 ,1) c += a[k] ;
					f (k ,0 ,s[j][2].size () - 1 ,1) c += s[j][2][k] ;
					if (i + sz < len) f (k ,i + sz ,len - 1 ,1) c += a[k] ;
					//std :: cerr << i << ' ' << j << '\n' ;
					//f (k ,0 ,c.size () - 1 ,1) std :: cerr << c[k] << '\n' ; puts ("") ;
					if (b == c) ans ++ ;
				}
			}
		}
		f (j ,1 ,n ,1) {
			int sz = s[j][1].size () ;
			if (len <= sz) continue ;
			c = "" ;
			f (i ,0 ,sz - 1 ,1) c += a[i] ;
			if (c == s[j][1]) {
				//c = s[j][2] + a.substr (sz ,len - sz + 1) ;
				c = "" ;
				f (i ,0 ,s[j][2].size () - 1 ,1) c += s[j][2][i] ;
				f (i ,sz ,len - 1 ,1) c += a[i] ; 
				if (b == c) ans ++ ;
			}
		} std :: cout << ans << '\n' ;
	}
 	return 0 ;
}

/*
4 2
xabcx xadex
ab cd
bs de
aa bb
xabcx xadex
aaaa bbbb
*/
