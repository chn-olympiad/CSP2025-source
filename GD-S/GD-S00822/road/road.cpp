#include<bits/stdc++.h>

using namespace std ;

int n , m , k ;
int a[15][10005] ;

int ans ;
struct node {
	int a , b , w ;
} v[1000005] ;

bool cmp(node x , node y) {
	return x.w < y.w ;
}

int fa[10005] ;
int c[15] ;

int find(int x){
	if(fa[x] != x) return fa[x] = find(fa[x]) ;
	return fa[x] ; 
}
int cnt ;
bool vis[20005] ;



void solve() {
	sort(v + 1 , v + cnt + 1 , cmp) ;
	for(int i = 1 ; i <= cnt ; i ++){
		int x = find(v[i].a) ;
		int y = find(v[i].b) ;
		if(x != y){
			fa[x] = y ; 
			if( v[i].a > n ){
				if(vis[v[i].a]!=0){
					v[i].w -= c[v[i].a - n] ;
				}else{
					vis[v[i].a] = 1 ;
				}
			}
			//cout << v[i].a << " " << v[i].b << endl ; 
			ans += v[i].w ; 
		}
	}
}

signed main() {
	
	freopen("road.in","r",stdin) ;
	freopen("road.out","w",stdout) ; 
	
	scanf("%d%d%d" ,&n , &m , &k) ;
	for(int i = 1 ; i <= m ; i ++) {
		scanf("%d%d%d",&v[i].a , &v[i].b , &v[i].w) ;
	}
	for(int i = 1 ; i <= n ; i ++){
		fa[i] = i  ;
	}
	cnt = m ; 
	
	for(int i = 1 ; i <= k ; i ++){
		scanf("%d",&c[i]) ; 
		for(int j = 1 ; j <= n ; j ++){
			scanf("%d",&a[i][j]) ; 
			v[++cnt].a = i + n ;
			v[cnt].b = j ; 
			v[cnt].w = a[i][j] + c[i] ; 
		}
	}
	
	solve() ;

	printf("%d",ans) ; 

	return 0 ;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
