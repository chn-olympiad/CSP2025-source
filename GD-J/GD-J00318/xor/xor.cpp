#include<bits/stdc++.h>
using namespace std;
int a[500005];
int dp[500005][2];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for(int i = 1;i <= n;i++) cin >> a[i];
	int num = -1;
	for(int i = 1;i <= n;i++){
		dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
		if(num == -1){
			dp[i][1] = dp[i][0];
			num = a[i];
			if(num == k){
				dp[i][1]++,num = -1;
			}
			continue;
		}
		int x = num ^ a[i];
		if(x == k){
			dp[i][1] = dp[i-1][1] + 1,num = -1;
		}else{
			num = x,dp[i][1] = dp[i-1][1];
		}
	}
	cout << max(dp[n][0],dp[n][1]);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
