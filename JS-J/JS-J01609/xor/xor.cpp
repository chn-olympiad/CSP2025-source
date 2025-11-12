#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5;
int n,k,a[N + 5],sum[N + 5],dp[N + 5];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		sum[i] = sum[i - 1] ^ a[i];
	}
	int last = 0;
	for(int i = 1;i <= n;i++){
		dp[i] = dp[i - 1];
		for(int j = i;j > last;j--){
			if((int)(sum[i] ^ sum[j - 1]) == k){
				dp[i] = max(dp[i],dp[j - 1] + 1);
				last = j;
				continue;
			}
		}
	}
	cout << dp[n] << "\n";
	return 0;
}
