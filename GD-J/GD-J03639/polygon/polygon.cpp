#include<bits/stdc++.h>
#define mod 998244353
#define ll long long
using namespace std;
ll ans,ma,n,a[5010],dp[25000010],bj[25000010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(false);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++){
		for(ll j=ma;j>=0;j--){
			if(!dp[j]) continue;
			ma=max(ma,j+a[i]);
			dp[j+a[i]]=(dp[j+a[i]]+dp[j])%mod;
			if(j>a[i]) ans=(ans+dp[j]-bj[j])%mod;
		}
		dp[a[i]]++;
		ma=max(ma,a[i]);
		bj[a[i]]++;
	}
	cout<<ans;
	return 0;
}
