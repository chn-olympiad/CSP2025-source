#include<bits/stdc++.h>
using namespace std ;
#define REP(i , a , b) for(int i = int(a) ; i <= int(b) ; ++i)
#define rep(i , a , b) for(int i = int(a) ; i >= int(b) ; --i)
using ll = long long ;
using PII = array<int , 2> ; // {贡献，编号} 
const int N = 1e5+10 ;
struct num{
	int a , b , c ;
}d[4][N] , x[N] ;
void solve(){
	int n , p1 = 0 , p2 = 0 , p3 = 0 ; cin >> n ;
	ll ans = 0 ;
	REP(i , 1 , n){
		int a , b , c , maxn = 0 ; cin >> a >> b >> c ;
		maxn = max(max(a , b) , c) ;
		if(a == maxn) d[1][++p1] = {a , b , c} ;
		else if(b == maxn) d[2][++p2] = {b , a , c} ;
		else if(c == maxn) d[3][++p3] = {c , a , b} ;
		ans += maxn ;
	}	
	int p = -1 , maxn = 0 ; maxn = max(max(p1 , p2) , p3) ;
	if(maxn <= n/2) cout << ans << "\n" ; // 无超过n/2 
	else{
		if(p1 == maxn) p = 1 ;
		else if(p2 == maxn) p = 2 ;
		else if(p3 == maxn) p = 3 ;
		REP(i , 1 , maxn) x[i] = d[p][i] ; // 处理超过n/2的组 
		
		multiset<PII> r1 , r2 ;
		REP(i , 1 , maxn) r1.insert(PII{x[i].b-x[i].a , i}) , r2.insert(PII{x[i].c-x[i].a , i}) ;
		while(r1.size() > n/2){ // 每次找最大贡献的交换 
			PII m1 = *rbegin(r1) , m2 = *rbegin(r2) ;
			int id , w = max(m1[0] , m2[0]) ;
			if(m1[0] < m2[0]) id = m2[1] ;
			else id = m1[1] ;  
			ans += w ;
			auto it1 = r1.lower_bound(PII{x[id].b-x[id].a , id}) , it2 = r2.lower_bound(PII{x[id].c-x[id].a , id}) ;
			r1.erase(it1) , r2.erase(it2) ;
		}
		cout << ans << "\n" ;
	}
}
int main(){
	freopen("club.in" , "r" , stdin) ;
	freopen("club.out" , "w" , stdout) ;
    ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) ;
	int T ; cin >> T ;
	while(T--) solve() ;
    return 0 ;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
