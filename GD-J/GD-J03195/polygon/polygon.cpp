#include <bits/stdc++.h>
using namespace std ;
const int MOD = 998244353 ;
int n , a[5005] , s[5005] , ans ;
bool need[5005] , book[5005] ;
void dfs(int maxn , int maxs , int step , int cnt , int Nows) 
{
	if (step == maxs + 1) return ;
	if (step >= 3 && cnt > 2 * maxn) ans++ ;
	for(int i = Nows ; i <= maxs ; i++){
		if (book[i] == 0) {
			book[i] = 1 ;
			cnt += a[i] ;
			dfs(maxn , maxs , step + 1 , cnt , i) ;
			book[i] = 0 ;
			cnt -= a[i] ;
		}
	}
	return ;
}
int main()
{
	freopen("polygon.in" , "r" , stdin) ;
	freopen("polygon.out" , "w" , stdout) ;
	cin >> n ;
	memset(need , 1 , sizeof(need)) ;
	for(int i = 1 ; i <= n ; i++) cin >> a[i] ;
	for(int i = 1 ; i <= n ; i++){
		s[i] = s[i - 1] + a[i] ;
		if (s[i - 1] <= a[i] || i < 3) need[i] = 0 ;
	}
	for (int i = 3 ; i <= n ; i++) {
		
		if (need[i]) dfs(a[i] , i , 0 , 0 , 1) ;
	}	
	cout << ans % MOD ;
	return 0 ;
}
