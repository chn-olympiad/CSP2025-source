#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5005],dp[10005],maxx,f[5005],ans;
const int mod=998244353;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	f[0]=1;
	for(int i=1;i<=n;i++){
		f[i]=(f[i-1]*2ll)%mod;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	maxx*=2;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(i>2)ans=(ans+f[i-1]-1ll-dp[a[i]]+mod)%mod;
		for(int j=maxx;j>=a[i];j--){
			dp[j]=(dp[j]+dp[j-a[i]]+1ll)%mod;
		}
	}
	cout<<ans;
	return 0;
}
