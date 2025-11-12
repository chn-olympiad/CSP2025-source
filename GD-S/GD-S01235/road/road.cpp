#include <bits/stdc++.h>
using namespace std ;
struct ac {
	int v , s ;
};
vector <ac> v[10005] ;
int n , m , k ;
vector <ac> tree[10005] ;
bool f [10005];
int sum ;
//cout char 
void dfs ( int x , int fa ) {
//	sort (v[x].begin() , v[x].end() , cmp ) ;
	int minn = 100000000 ;
	int id = -1 ;
	f[x] = 1 ;
	for ( int i = 0 ; i < v[x].size() ; i ++ ) {
		if ( f[v[x][i].v] == 0 && v[x][i].s < minn ) {
			minn = v[x][i].s ;
			id = i ;
		}
	}
//	f[x] = 
	if ( id == -1 ) {
		return ;
	}
//	if ( v[x][id].kn != -1 && kf[v[x][id].kn] == 0 ) {
//		kf[v[x][id].kn] = 1 ;
//		sum += ka[v[x][id].kn] ;
//	}
	tree[x].push_back ({v[x][id].v , v[x][id].s}) ;
	sum += v[x][id].s ;
//	cout << "sum=" << sum << "\n" ; 
	dfs ( v[x][id].v , x) ;
	
}

int main () {
	freopen ("road.in" , "r" , stdin) ;
	freopen ("road.out" , "w" , stdout) ;
	
	ios::sync_with_stdio(false) ;
	cin.tie(0) , cout.tie(0) ;
	
	cin >> n >> m >> k ;
	
	for ( int i = 0 ; i < m ; i ++ ) {
		int u , v1 , w ;
		cin >> u >> v1 >> w ;
		
		v[u].push_back ({v1 , w }) ;
		v[v1].push_back ({u , w }) ;
	} 
	
	for ( int i = 0 ; i < k ; i ++ ) {
		int a , b[10005] ;
		cin >> a ;
//		ka[i] = a ;
		for ( int i = 0 ; i < n ; i ++ ) {
			cin >> b[i] ;
		}
		
		for ( int i = 1 ; i < n ; i ++ ) {
			for ( int j = 0 ; j < i ; j ++ ) {
				v[i].push_back ({j , (i + j) }) ;
				v[j].push_back ({i , (i + j) }) ;
			}
		}
	}
	
	
	dfs ( 0 , -1 ) ;
	
//	for ( int i = 0 ; i < n ; i ++ ) {
//		for ( int j = 0 ; j < tree[i].size() ; j ++ ) {
////			cout << i << " " << tree[i][j] << "\n" ;
//			cout << i << " "   ;
//			cout << tree[i][j].v << endl ; 
//		}
//	} 
	
	cout << sum ;
	
	return 0 ;
}
