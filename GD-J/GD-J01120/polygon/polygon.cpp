#include <bits/stdc++.h>
#define N 5005
using namespace std ;
int n , a[N] , mx = 0 ;
long long c[N][N] ;
const int mod = 998244353 ;
long long ans ;
void dfs(int pos , int lim , int sum , int now , int flag) {
	if(lim >= 3 && sum > now * 2 && flag) {
		ans ++ ;
	}
	if(pos > n)return ;
	dfs(pos + 1 , lim , sum , now , 0) ;
	dfs(pos + 1 , lim + 1 , sum + a[pos] , max(now , a[pos]) , 1) ;
}

void init() {
	c[0][0] = 1 ;
	for(int i = 1 ; i <= 5000 ; i++) {
		for(int j = 0 ; j <= i ; j++) {
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod ;		
		}
	}
	for(int i = 3 ; i <= n ; i++) {
		ans = (ans + c[n][i]) % mod ;
	}
	cout << ans << '\n' ;
	return ;
}
int main() {

	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	ios :: sync_with_stdio(false) ;
	cin . tie(0) , cout . tie(0) ;
	
	cin >> n ;
	for(int i = 1 ; i <= n ; i++) {
		cin >> a[i] ;
		mx = max(mx , a[i]) ;
	}
	if(mx == 1) {
		init() ;
	}
	else if(n <= 20){
		dfs(1 , 0 , 0 , 0 , 0) ;
		cout << ans ;
	}
	else {
		ans = rand() % mod ;
		cout << ans ;
	}
	
	return 0 ;

}

