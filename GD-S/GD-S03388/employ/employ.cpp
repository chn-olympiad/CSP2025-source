#include<bits/stdc++.h>
using namespace std ;
#define REP(i , a , b) for(int i = int(a) ; i <= int(b) ; ++i)
#define rep(i , a , b) for(int i = int(a) ; i >= int(b) ; --i)
const int N = 5e2+10 ;
int c[N] ;
int main(){
	freopen("employ.in" , "r" , stdin) ;
	freopen("employ.out" , "w" , stdout) ;
    ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) ;
	int n , m ; cin >> n >> m ;
	bool FA = true ; string s ; cin >> s ;
	REP(i , 0 , n-1){
		if(s[i] == '0') FA = false ;
	} 
	REP(i , 1 , n) cin >> c[i] ;
	
	if(n <= 10){ // 
		int ans = 0 ;
		vector<int> a(n) ; iota(begin(a) , end(a) , 1) ;
		do{
			int sum = 0 , cnt = 0 ; // 已经录用和没有录用
			REP(i , 0 , n-1){
				int p = a[i] ;
				if(s[i] == '0' || cnt >= c[p]) cnt++ ;
				else sum++ ;
			} 
			if(sum >= m) ans++ ;
			
		}while(next_permutation(begin(a) , end(a))) ;
		cout << ans << "\n" ;
	}
    return 0 ;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
