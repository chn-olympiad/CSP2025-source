#include<bits/stdc++.h>
using namespace std ;
#define REP(i , a , b) for(int i = int(a) ; i <= int(b) ; ++i)
#define rep(i , a , b) for(int i = int(a) ; i >= int(b) ; --i)
const int N = 1e4+10 , M = 2e6 , K = 20 ;
using PII = array<int , 2> ;
using ll = long long ;
struct edge{
	int u , v , w ;
}e[M] ;
struct DSU{
	vector<int> fa ; int n ;
	DSU(int _n){n = _n , fa.resize(_n+1) ; iota(begin(fa) , end(fa) , 0) ;}
	int find(int u){return (fa[u] != u ? fa[u] = find(fa[u]) : u) ;}
	bool merge(int u , int v){
//		if((u = find(u)) != (v = find(v))) return fa[u] = v , true ;
//		else return false ;
		int fu = find(u) , fv = find(v) ;
		if(fu == fv) return false ;
		return fa[fu] = fv , true ;
	} 
};
bool add[K] ; ll Sum[K] ;
ll kru(int n , int m , int yu){
	DSU d(n) ; ll ans = 0 ; int cnt = 0 ;
	REP(i , 1 , m){
		int u = e[i].u , v = e[i].v , w = e[i].w ;
		if(d.merge(u , v)){
			ans += w , cnt++ ;
			if(u == 0) add[v-yu] = true ;
			if(u > yu) Sum[u-yu] += w ;
		} 
	}
//	cout << "--- " << n << " " << cnt << "\n" ;
	return ans ;
}

int c[K] , a[K][N] ;
int main(){
	freopen("road.in" , "r" , stdin) ;
	freopen("road.out" , "w" , stdout) ;
    ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) ;
	int n , m , k , SUM = 0 ; cin >> n >> m >> k ; SUM = m+n*k ;
	REP(i , 1 , m) cin >> e[i].u >> e[i].v >> e[i].w ;
	if(k == 0){
		sort(e+1 , e+1+m , [&](edge x , edge y){return x.w < y.w ;}) ;
		cout << kru(n , m , n) << "\n" ;
	}else{
		bool FA = true ; ll sum = 0 ;
		REP(i , 1 , k){
			cin >> c[i] , sum += c[i] ;
			if(c[i] != 0) FA = false ;
			REP(j , 1 , n) cin >> a[i][j] ;
		}
		if(FA){ // 13~14 3
			REP(i , 1 , k){
				REP(j , 1 , n) e[++m] = {i+n , j , a[i][j]} ;
			}
			sort(e+1 , e+1+m , [&](edge x , edge y){return x.w < y.w ;}) ;
			cout << kru(n+k , m , n) << "\n" ;
		}else{
			REP(i , 1 , k){
				e[++m] = {0 , i+n , c[i]} ;
				REP(j , 1 , n) e[++m] = {i+n , j , a[i][j]} ;
			}
			sort(e+1 , e+1+m , [&](edge x , edge y){return x.w < y.w ;}) ;
			ll ans = kru(n+k+1 , m , n) ;
			REP(i , 1 , k){
				if(!add[i]) ans -= Sum[i] ;
				else if(Sum[i] == 0) ans -= c[i] ;
			}
			cout << ans << "\n" ;
		}
	}
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

