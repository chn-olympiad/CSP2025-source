#include <bits/stdc++.h>
using namespace std;
int a[n],dp[n],sum[n];
const int mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out",'w',stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	for(int i=3;i=n;i++){
		if(sum[i]>2*a[i]) dp[i]=max(dp[i]%mod,((dp[i-1]%mod)+1%mod)%mod);
	}
	cout<<dp[n]%mod;
	return 0;
}