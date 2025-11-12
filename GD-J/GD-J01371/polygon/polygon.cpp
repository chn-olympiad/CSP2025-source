#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5005;
const ll mod=998244353;
ll n,ans=0;
ll a[N];
ll dp[N*2+10],dp2[N*2+10];
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(dp,0,sizeof(dp));
	memset(dp2,0,sizeof(dp2));
	dp2[0]=1;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) {
		ll k=0,s=0;
		memset(dp,0,sizeof(dp));
		for(int j=0; j<=10001; j++) {
			dp[j]=(dp[j]+dp2[j])%mod;
			k=min((ll)10001,j+a[i]);
			dp[k]=(dp[k]+dp2[j])%mod;
		}
		if(i>=3) {
			s=0;
			for(int j=2*a[i]+1; j<=10001; j++) {
				s=(s+(dp[j]-dp2[j]%mod)+mod)%mod;
			}
			ans=(ans+s)%mod;
		}
		memcpy(dp2,dp,sizeof(dp2));
	}
	cout<<ans<<endl;
	return 0;
}
