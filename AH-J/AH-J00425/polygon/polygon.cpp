#include<bits/stdc++.h>
using namespace std;
long long a[5010],dp[5010],ans=0;
const long long mod=998244353;
long long ksm(long long n,int m){
	long long ans=1;
	while(m){
		if(m&1) ans=ans*n%mod;
		n*=n;
		n%=mod;
		m/=2;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	dp[0]=1;
	for(int i=1;i<=n;i++){
		if(i>=3){
			long long cnt=ksm(2,i-1)-1;
			for(int j=1;j<=a[i];j++){
				cnt-=dp[j];
				cnt%=mod;
			}
			ans=(ans+cnt+mod)%mod;
		}
		for(int j=5000;j>=a[i];j--){
			dp[j]+=dp[j-a[i]];
			dp[j]%=mod;
		}
	}
	cout<<ans;
	return 0;
}
