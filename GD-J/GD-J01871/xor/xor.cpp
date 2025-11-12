#include <bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int a[maxn],dp[maxn],sum[maxn];

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >>  k;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		sum[i]=sum[i-1]^a[i];
	}
	dp[0]=0;
	for(int i=1;i<=n;i++) {
		dp[i]=dp[i-1];
		for(int j=i-1;j>=0;j--) {
			if((sum[i]^sum[j])==k) dp[i]=max(dp[i],dp[j]+1);
		}
		
	}
	cout << dp[n] << "\n";
	return 0;
}
