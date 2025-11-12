#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n,a[5005];
int ans=0;
int dp[5000005];
int pw[5000005];
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	pw[0]=1;
	for(int i=1;i<=1000000;i++) pw[i]=pw[i-1]*2%mod;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	dp[0]=1;
	for(int i=1;i<=2;i++) {
		int sum=0;
		for(int j=a[n];j>=0;j--) {
			if(j<=a[i]) sum=(sum+dp[j])%mod;
			if(j>=a[i]) dp[j]=(dp[j]+dp[j-a[i]])%mod;
		}
	}
	for(int i=3;i<=n;i++) {
		int sum=0;
		for(int j=a[n];j>=0;j--) {
			if(j<=a[i]) sum=(sum+dp[j])%mod;
			if(j>=a[i]) dp[j]=(dp[j]+dp[j-a[i]])%mod;
		}
		sum%=mod;
		ans=((ans+pw[i-1]-sum+mod)%mod+mod)%mod;
	}
	cout<<ans;
	return 0;
}
