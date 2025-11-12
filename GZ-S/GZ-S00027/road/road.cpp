// GZ-S00027 贵阳中天中学 何棂宸
#include <bits/stdc++.h>
#define ll long long
using namespace std ;

const int M = 1e6+5 , N = 1e4+20 , mm = 1e9 ;
ll n , m , k , vil[25] , ct , fa[N] , ans , vb[25][N] ;
vector < int > ls[25] ;

struct lines {
	int u , v , w , bel , bk ;
} l[M];

bool cmp ( lines a , lines b ) {
	return a.w < b.w ;
}

int find ( int x ) {
	if ( fa[x] != x ) {
		return fa[x] = find(fa[x]) ;
	}
}

void merge ( int x , int y ) {
	int fx = find(x) , fy = find(y) ;
	if ( fx != fy ) {
		fa[fy] = fx ;
	}
}

bool func () {
	// avoid using wrong inform after updating
	bool flag = 0 ;
	for ( int i = 1 ; i <= ct ; i++ ) {
		if ( find(l[i].u) != find(l[i].v) && !l[i].bel && !l[i].bk ) {
			l[i].bk = 1 ;
			merge(l[i].u,l[i].v) ;
			ans += l[i].w ;
		} else if ( find(l[i].u) != find(l[i].v) && l[i].bel && !l[i].bk ) {
			l[i].bk = 1 ;
			for ( auto j : ls[l[i].bel] ) { // update
				l[j].w -= vil[l[j].bel] ;
			}
			merge(l[i].u,l[i].v) ;
			ans += l[i].w ;
			sort(l+1,l+1+ct,cmp) ;
			return 0 ;
		}
	}
	return 1 ;
}

int main() {
	freopen("road.in","r",stdin) ;
	freopen("road.out","w",stdout) ;
	cin >> n >> m >> k ;
	for ( int i = 1 ; i <= n ; i++ ) fa[i] = i ;
	for ( int i = 1 ; i <= m ; i++ ) {
		cin >> l[i].u >> l[i].v >> l[i].w ;
	}
	ct = m ;
	for ( int i = 1 ; i <= k ; i++ ) {
		cin >> vil[i] ;
		for ( int j = 1 ; j <= n ; j++ ) {
			cin >> vb[i][j] ;
		}
	}
	for ( int i = 1 ; i < n ; i++ ) {
		for ( int j = i+1 ; j <= n ; j++ ) {
			ct++ ;
			l[ct].u = i ;
			l[ct].v = j ;
			l[ct].w = mm ;
			int vlg = 1 ;
			for ( int p = 1 ; p <= k ; p++ ) {
				if ( l[ct].w > vil[p]+vb[p][i]+vb[p][j] ) {
					l[ct].w = vil[p]+vb[p][i]+vb[p][j] ;
					l[ct].bel = p ;
					vlg = p ;
				}
			}
			ls[vlg].push_back(ct) ;
		}
	}
	sort(l+1,l+1+ct,cmp) ;
	bool f = func() ;
	while ( !f ) f = func() ;
	cout << ans << endl ;
	return 0 ;
}
// Ren5Jie4Di4Ling5%
