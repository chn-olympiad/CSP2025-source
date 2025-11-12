#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],dp[5005],sum,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);dp[0]=1;
	for(int i=1;i<=n;i++){
		dp[5001]=(dp[5001]*2)%mod;
		if(i>1){
			int j=i-1;
			for(int k=5000;k>=0;k--){
				dp[min(k+a[j],5000+1)]+=dp[k];
				dp[min(k+a[j],5000+1)]%=mod;
			}	
		}
		for(int j=a[i]+1;j<=5001;j++) ans=(ans+dp[j])%mod;
	}
	cout<<ans;
	return 0;
}
