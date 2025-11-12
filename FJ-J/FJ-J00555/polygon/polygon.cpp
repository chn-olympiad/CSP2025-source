#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,k,a[5001],dp[5000001][5],qz[5001],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		qz[i]=qz[i-1]+a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=qz[i];j>=a[i];j--){
			dp[j][1]+=dp[j-a[i]][0];
			if(j>2*a[i]) dp[j][2]=(dp[j][2]+dp[j-a[i]][1]+dp[j-a[i]][2]+dp[j-a[i]][3])%mod;
			else dp[j][3]=(dp[j][3]+dp[j-a[i]][1]+dp[j-a[i]][2]+dp[j-a[i]][3])%mod;
		}
		dp[a[i]][0]++;
	}
	for(int j=1;j<=qz[n];j++){
		ans=(ans+dp[j][2])%mod;
	}
	cout<<ans;
	return 0;
}
