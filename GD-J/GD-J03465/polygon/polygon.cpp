#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,a[5005],sum[5005];
long long ans=0,dp[5005*5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	dp[a[1]]=1;
	for(int i=2;i<=n;i++){
		if(i>=3){
			for(int j=a[i]+1;j<=sum[i-1];j++){
				ans=(ans+dp[j])%mod;
			}
		}
		for(int j=sum[i];j>=a[i];j--){
			dp[j]=(dp[j]+dp[j-a[i]])%mod;
		}
		dp[a[i]]=(dp[a[i]]+1)%mod;
	}
	cout<<ans<<endl;
	return 0;
}

