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

const int N = 500 ;
int n ,m ,c[N] ,p[N] ; char s[N] ;

int main () {
	freopen ("employ.in" ,"r" ,stdin) ;
	freopen ("employ.out" ,"w" ,stdout) ;
	read (n ,m) ; f (i ,1 ,n ,1) std :: cin >> s[i] ;
	f (i ,1 ,n ,1) read (c[i]) ;
	f (i ,1 ,n ,1) p[i] = i ;
	int ans = 0 ;
	do {
		int cnt = 0 ,tot = 0 ;
		f (i ,1 ,n ,1) {
			if (cnt >= c[p[i]]) { cnt ++ ; continue ;}
			else if (s[i] == '0') { cnt ++ ; continue ;}
			tot ++ ;
		} if (tot >= m) ans ++ ;
	} while (std :: next_permutation (p + 1 ,p + n + 1)) ;
	std :: cout << ans << '\n' ;
	return 0 ;
}
