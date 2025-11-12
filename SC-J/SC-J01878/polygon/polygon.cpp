#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[5005],dp[5005][5005],ans;
const ll mod=998244353;
ll slowpow(ll a,ll b){
	ll ans=1,di=a,zh=b;
	while(zh!=0){
		if(zh%2==1) ans*=di;
		ans%=mod;
		di=di*di%mod;
		zh>>=1;
	}
	return ans%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dp[0][0]=1;
	for(ll i=1;i<=n;i++) dp[i][0]=1;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=a[n];j++){
			dp[i][j]=dp[i-1][j]+dp[i-1][j-a[i]];
			dp[i][j]%=mod;
		}
	}
	for(ll i=2;i<=n;i++){
		ll sum=0;
		for(ll j=a[i];j>=0;j--){
			sum+=dp[i-1][j];
			sum%=mod;
		}
		ans+=(slowpow(2,i-1)-sum);
		ans%=mod;
	}
	cout<<ans;
	return 0;
}