#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],dp[500005],sum[500005];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		sum[i]=(sum[i-1]^a[i]);
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j=0;j<i;j++){
			if((sum[i]^sum[j])==k){
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
	}
	cout << dp[n];
	return 0;
}
