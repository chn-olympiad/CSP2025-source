#include <bits/stdc++.h>
using namespace std;
const int Max=5e3+5;
const long long Mod=998244353;
int n,a[Max],sum;
long long ans;
long long dp[Max*2];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool f=1; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=0;
	}
	if(f==1){
		long long k=n;
		k=(k*(n-1))%Mod;
		k=(k*(n-2))%Mod;
		k=(k/6)%Mod;
		cout<<k;
		return 0;
	}
	sort(a+1,a+1+n);
	dp[0]=1,dp[a[1]]++,dp[a[2]]++,dp[a[1]+a[2]]++;
	sum=a[1]+a[2];
	for(int i=3;i<n;i++){
		for(int j=a[i]+1;j<=sum;j++){
			ans=(ans+dp[j])%Mod;
		}
		for(int u=sum;u>=0;u--){
			dp[u+a[i]]=(dp[u+a[i]]+dp[u])%Mod;
		}
		sum+=a[i];
	}
	for(int i=a[n]+1;i<=sum;i++){
		ans=(ans+dp[i])%Mod;
	}
	cout<<ans;
	return 0;
}
