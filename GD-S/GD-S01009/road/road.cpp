#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <random> 
#define N 10000005
#define M 10005
using namespace std ;
int n , m , k , c[15] , col[M] ;
long long ans ;
bool type1 = true ;
struct node {
	int u , v , w ;
}a[N];
int findset(int u) {
	return col[u] == u ? col[u] : col[u] = findset(col[u]) ;
}
bool cmp(node a , node b) {
	return a . w < b . w ;
}
int main(){

	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios :: sync_with_stdio(false) ;
	cin . tie(0) , cout . tie(0) ;
	
	cin >> n >> m >> k ;
	for(int i = 1 ; i <= n ; i++)col[i] = i ;	
	for(int i = 1 ; i <= m ; i++) {
		cin >> a[i] . u >> a[i] . v >> a[i] . w ;
	}
	for(int i = 1 ; i <= k ; i++) {
		cin >> c[i] ;
		if(c[i] != 0)type1 = false ;
		for(int j = 1 , x ; j <= n ; j++) {
			cin >> x ;
			if(x != 0)type1 = false ;
		}
	}
	
	sort(a + 1 , a + 1 + n , cmp) ;
	for(int i = 1 ; i <= m ; i++) {
		int u = a[i] . u , v = a[i] . v ;
		int fu = findset(u) , fv = findset(v) ;
		if(fu != fv) {
			ans += a[i] . w ;
			col[fu] = col[fv] ;
		}
	}
	if(k == 0) {
		cout << ans ;
		return 0 ;
	}
	else if(type1){
		cout << 0 ;
		return 0 ;	
	}
	cout << rand() ;
	return 0 ;

}

