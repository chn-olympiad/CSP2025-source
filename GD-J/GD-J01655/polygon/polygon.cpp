#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long ksm(int x){
	long long p=2;
	long long ans=1;
	while(x){
		if(x%2){
			ans*=p;
			ans%=mod;
		}
		p*=p;
		p%=mod;
		x/=2;
	}
	return ans;
}
long long n;
long long ton[5005];
long long qian[5005];
long long ans=0;
long long maxn=0;
long long dp[5005];
long long a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ton[a[i]]++;
		maxn=max(maxn,a[i]);
	}
	sort(a+1,a+n+1);
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=maxn-a[i];j>=0;j--){
			dp[j+a[i]]+=dp[j];
		}
	}
	for(int i=1;i<=maxn;i++){
		qian[i]=ton[i]+qian[i-1];
	}
	for(int i=1;i<=maxn;i++){
		dp[i]-=ton[i];
	}
	ans=ksm(n);
	ans=(ans+mod*n-n-1-(n*(n-1)/2))%mod;
	for(int he=2;he<=maxn;he++){
		ans=(ans+mod*mod-dp[he]*(n-qian[he-1]))%mod;
	}
	cout<<ans;
	return 0;
}
