#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int w[1000005];
int dp[10010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&w[i]);
	}
	sort(w+1,w+n+1);
	dp[0]=1;
	for(int i=1;i<=2;i++){
		int t=dp[10005];
		for(int j=10001-w[i]+1;j<=10001;j++){
			dp[10005]+=dp[j];
			dp[10005]%=mod;
		}
		dp[10005]+=t;
		dp[10005]%=mod;
		for(int j=10001;j>=w[i];j--){
			dp[j]+=dp[j-w[i]];
			dp[j]%=mod;
		}
		//for(int j=1;j<=10005;j++){
		//	if(dp[j]!=0)cout<<j<<" "<<dp[j]<<"\n";
		//}
	}
	int ans=0;
	for(int i=3;i<=n;i++){
		for(int j=w[i]+1;j<=10005;j++){
			ans+=dp[j];
			ans%=mod;
		}
		int t=dp[10005];
		for(int j=10001-w[i]+1;j<=10001;j++){
			dp[10005]+=dp[j];
			dp[10005]%=mod;
		}
		dp[10005]+=t;
		dp[10005]%=mod;
		for(int j=10001;j>=w[i];j--){
			dp[j]+=dp[j-w[i]];
			dp[j]%=mod;
		}
		//for(int j=1;j<=10005;j++){
		//	if(dp[j]!=0)cout<<j<<" "<<dp[j]<<"\n";
		//}
	}
	cout<<ans;
	return 0;
}
