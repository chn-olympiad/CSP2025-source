#include <bits/stdc++.h>
using namespace std ;
const int Maxn = (1e3) + 10 ;
long long dp [Maxn][Maxn] ;
long long Data[Maxn] ;
int cnt = 0 ;
int main () {
	
	freopen("xor.in","r",stdin) ;
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0) ;
	cin.tie(0) ;
	cout.tie(0) ; 
	long long n , k ;
	cin >> n >> k ;
	
	for ( int i = 1 ; i<= n ; i++ ) 
		cin >> Data[i] ;
	
//	if(k == 0 ) {
//
//		for ( int i = 1 ; i <= Data[i] ; i++ ) {
//			if(Data[i] == k) {
//				cnt++ ;
//			}
//		}	
//		cout << cnt ;
//	}	
	for ( int i = 1 ; i <= n ; i++ ) {
		for ( int j = 1 ; j <= i ; j++) {
			long long tmp = 0 ;
			for (int p = i-j+1 ; p <= i ; p++)
				tmp ^= Data[p] ;
			if (tmp == k) {
				dp[i][j] = max(max(dp[i-1][j],dp[i][j-1]),dp[i-j][j]+1) ;	
			} else {
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]) ;
			} 
			
		}
		for ( int j = i+1 ; j <= n ; j++ ) {
			dp[i][j] = dp[i][j-1] ;
		} 
	}
	cout << dp[n][n] ;
	return 0 ;
}
