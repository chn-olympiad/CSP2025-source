#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5005],dp[5005],ans;
const int mod=998244353;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	dp[0]=1;
	for(int i=1;i<=n;i++){
		int num=0;
		for(int j=a[i]+1;j<=5001;j++) num=(num+dp[j])%mod;
		ans=(ans+num)%mod;
		for(int j=5001;j>5001-a[i];j--) dp[5001]=(dp[5001]+dp[j])%mod;
		for(int j=5001;j>=a[i];j--) dp[j]=(dp[j]+dp[j-a[i]])%mod;
	}
	cout<<ans%mod;
	return 0;
}
