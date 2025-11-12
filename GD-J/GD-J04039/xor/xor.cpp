#include <bits/stdc++.h>
using namespace std;
long long dp[1000000];
long long a[1000000];
long long sum[1000000];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	long long n;
	cin >> n;
	long long k;
	cin >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		sum[i] = sum[i - 1] ^ a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = i;j >= 1;j--){
			if(!((sum[i] ^ sum[j - 1]) == k)){
				continue;
			}
			dp[i] = max(dp[i], dp[j - 1] + 1);
			break;
		}	
		dp[i] = max(dp[i], dp[i - 1]);
	}
	cout << dp[n] << endl;
	return 0; 
}
