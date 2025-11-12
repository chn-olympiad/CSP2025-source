#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10 ;
int t , n , a[5][maxn] , dp[110][110][110] , ans ;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	cin >> t ;
	while ( t-- ){
        memset(dp,0,sizeof(dp));
        ans = 0 ;
		cin >> n ;
		for ( int i = 1 ; i <= n ; i++ ){
			for ( int j = 1 ; j < 4 ; j++ ){
			       cin >> a[j][i] ;
			}
	 	}
		if ( n > 200 ){
			sort ( a[1] + 1 , a[1] + n + 1 ) ;
			for ( int i = n ; i > n / 2 ; i-- ){
				ans+=a[1][i];
			}
		}else{
			for ( int i = 1 ; i <= n ; i++ ){
				for ( int j = min ( i , n / 2 ) ; j >= 0 ; j-- ){
					for ( int k = min ( i - j , n / 2 ) ; k >= 0 ; k-- ){
						int l = i - j - k ;
						if ( l > n / 2 ) continue;
						if ( j ) dp[j][k][l] = max ( dp[j][k][l] , dp[j-1][k][l] + a[1][i] ) ;
						if ( k ) dp[j][k][l] = max ( dp[j][k][l] , dp[j][k-1][l] + a[2][i] ) ;
						if ( l ) dp[j][k][l] = max ( dp[j][k][l] , dp[j][k][l-1] + a[3][i] ) ;
						if ( i == n ){
                            ans = max ( ans , dp[j][k][l] ) ;
						}
					}
				}
			}
		}
		cout << ans << endl ;
	}
	return 0 ;
}
