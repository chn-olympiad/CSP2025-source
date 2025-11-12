#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int dp[N][N];
int a[N];
int sum[N];

int main() {
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	int n,kk;
	cin >> n >> kk;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	for(int i = 1; i <= n; i++){
		sum[i] = (sum[i-1] ^ a[i]);
	}
	
	for(int l = 1; l <= n; l++){
		for(int j = 1; j+l-1 <= n; j++){
			
			if(l == 1){
				if(dp[j][j] == kk){
					dp[j][j] = 1;
				}
				continue;
			}
			
			for(int k = j; k < j+l-1; k++){
				
				if((sum[k] ^ sum[j-1]) == kk){
					dp[j][k] = max(dp[j][k],1);
				}
				if((sum[j+l-1] ^ sum[k]) == kk){
					dp[k+1][j+l-1] = max(dp[k+1][j+l-1],1);
				}
				if((sum[j+l-1] ^ sum[j-1]) == kk){
					dp[j][j+l-1] = max(dp[j][j+l-1],1);
				}
				
				dp[j][j+l-1] = max(dp[j][k]+dp[k+1][j+l-1],dp[j][j+l-1]);
			}
		}	
	}
	cout << dp[1][n];
	
	return 0;
}

