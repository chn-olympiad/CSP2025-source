#include <bits/stdc++.h>
using namespace std ; 
const int N = 1e5 +10 ; 
const int M = 100+10 ; 
int a1[N] , a2[N] , a3[N] ; 
int dp[M][M][M] ;
int main(){
	freopen("club.in" , "r",stdin) ; 
	freopen("club.out" , "w",stdout) ;
	int t ; 
	cin >>t ;
	while(t--){ 
		memset(a1,0,sizeof(a1))  ;
		memset(a2,0,sizeof(a2))  ;
		memset(a3,0,sizeof(a3))  ;
		memset(dp,-0x3f,sizeof(dp))  ;
		int n ; 
		int ans =0 ; 
		cin >> n ;
		int maxn = n/2 ; 
		for(int i = 1 ; i <= n ; i++){
			cin >> a1[i] >> a2[i] >> a3[i] ; 
		}
		dp[0][0][0] = 0;
		for(int i = 1; i<= n ;i++){
			for(int j = 0; j<= min(i , maxn) ; j++){
				for(int k = 0 ; k<= min(i-j , maxn) ; k++){
					int a = j ,b = k , c = i-j-k ; 
					if(c<=maxn && c>=0){
						dp[a][b][c] = max(dp[max(0,a-1)][b][c] + a1[i],max(dp[a][max(0,b-1)][c] + a2[i], dp[a][b][max(0,c-1)] + a3[i])); 
//						 if(t==2)cout <<a<<" "<<b<<" "<<c<<" " <<dp[a][b][c] <<endl;;
						if(i==n){
							ans = max(dp[a][b][c] , ans) ; 
						}
					}
				}
			}
		} 
		cout << ans <<endl ;
	}
	
	
	return 0;
}
