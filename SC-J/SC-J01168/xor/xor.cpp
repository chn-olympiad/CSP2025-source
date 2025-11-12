#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, k;
int a[500005];
int dp[5000005][2];
signed main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	int sum = 0;
	for(int i = 1;i <= n;i ++){
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		if(dp[i - 1][0] >= dp[i - 1][1]){
			dp[i][1] = dp[i - 1][0];
			if((sum ^ a[i]) == k){
				dp[i][1] ++;
				sum = 0;
			} else{
				sum ^= a[i];
			}
		} else{
			dp[i][1] = dp[i - 1][1];
			if((sum ^ a[i]) == k){
				dp[i][1] ++;
				sum = 0;
			} else{
				sum ^= a[i];
			}
		}
	}
//	for(int i = 1;i <= n;i ++){
//		cout << dp[i][0] << endl;
//	}
//	cout << endl;
//	for(int i = 1;i <= n;i ++){
//		cout << dp[i][1] << endl;
//	}
	cout << max(dp[n][0], dp[n][1]);
}
/*
4 2
2 1 0 3

4 3
2 1 0 3

4 0
2 1 0 3

10 0
1 1 1 1 1 1 1 1 1 1

10 1
1 0 0 1 1 1 0 0 1 1
*/