#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e3+5,mod=998244353;
ll n,a[N],r,dp[N],ch=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],r=max(r,a[i]);
	sort(a+1,a+1+n);
	ll ans=0;
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=a[i]+1;j<=r;j++){
			ans=(ans+dp[j])%mod;
		}ans=(ans+ch)%mod;
		ch=ch*2%mod;
		for(int j=r;j>=0;j--){
			if(j+a[i]>r){
				ch=(ch+dp[j])%mod;
				continue;
			}
			dp[j+a[i]]=(dp[j+a[i]]+dp[j])%mod;
		}
	}cout<<ans;
	return 0;
}