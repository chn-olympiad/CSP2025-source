#include<bits/stdc++.h>
using namespace std;
int dp[5005];
const int mod=998244353;
int ans=0;
int n;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dp[0]=1;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=5001;j>a[i];j--){
			ans=(ans+dp[j])%mod;
		}
		dp[5001]=(dp[5001]+dp[5001])%mod;
		for(int j=5000;j>=a[i];j--){
			if(j+a[i]>=5001)dp[5001]=(dp[5001]+dp[j])%mod;
			dp[j]=(dp[j]+dp[j-a[i]])%mod;
		}
	}
	printf("%d\n",ans);
	return 0;
}
