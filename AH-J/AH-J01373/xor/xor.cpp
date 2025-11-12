#include<bits/stdc++.h>
using namespace std;
long long dp[500005],a[500005],k;
int n;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %lld",&n,&k);
	for(int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++) {
		if(a[i] == k) {
			dp[i]=dp[i-1]+1;
			continue;
		}
		else dp[i]=dp[i-1];
		for(int j=i-1;j>0 && dp[i] == dp[j-1];j--) {
			a[j]=a[j]^a[i];
			if(a[j] == k) {
				dp[i]++;
				break;
			}
		}
	}
	cout<<dp[n]<<endl;
	
}
