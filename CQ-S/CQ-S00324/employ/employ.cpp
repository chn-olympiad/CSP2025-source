#include <bits/stdc++.h>
//#define int long long
#define lowbit(x) ((x) & -(x))
#define PII pair < int , int >
#define x first
#define y second
using namespace std ;
int n , m , f[20] , c[20] , ans = 0 ; 
string s ; 
vector < int > p ; 
void dfs(int x){
	if(x == n + 1){
		int cnt = 0 , sum = 0 ; 
		for(int j = 0 ; j < n ; j++){
			int i = p[j] ; 
			if(s[j] == '0') cnt++ ; 
			else{
				if(cnt >= c[i]) cnt++ ; 
				else sum++ ; 
			}
		}
		ans += sum >= m ; 
		return ; 
	}
	for(int i = 1 ; i <= n ; i++) if(!f[i]){
		f[i] = 1 ; p.push_back(i) ; 
		dfs(x + 1) ; 
		f[i] = 0 ; p.pop_back() ; 
	}
}
signed main(){
	freopen("employ.in" , "r" , stdin) ;
	freopen("employ.out" , "w" , stdout) ;
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ; cout.tie(0) ;
	cin >> n >> m >> s ; 
	for(int i = 1 ; i <= n ; i++) cin >> c[i] ; 
	dfs(1) ; 
	cout << ans ; 
	return 0 ;
}
/*
设dp_i_j表示当前人为i，前面有j个人丢了 
*/

