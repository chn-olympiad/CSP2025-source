#include<bits/stdc++.h>
using namespace std;
int a[500010] , f[500010] , dp[500010][2] , maxn[500010];

int main(){
	freopen("xor.in" , "r" , stdin);
	freopen("xor.out" , "w" , stdout);
	int n , k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		int sum = 0;
		for(int j = i; j >= 1; j--){
			sum ^= a[j];
			if(sum == k){
				f[i] = j;
				break;
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		dp[i][0] = maxn[i - 1];
		if(f[i]) dp[i][1] = maxn[f[i] - 1] + 1;
		maxn[i] = max(maxn[i - 1] , max(dp[i][0] , dp[i][1]));
		ans = max(ans , max(dp[i][0] , dp[i][1]));
	}
	cout << ans;
	return 0;
}