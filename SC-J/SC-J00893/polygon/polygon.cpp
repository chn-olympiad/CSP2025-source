#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=998244353;
int n,a[5010],sdp[5010][10010];
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	sdp[0][0]=1;
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int k=0;k<=2*a[n]+1;k++)
			sdp[i][min(2*a[n]+1,k+a[i])]=(sdp[i][min(2*a[n]+1,k+a[i])]+sdp[i-1][k])%mod;
		for(int k=2*a[i]+1;k<=2*a[n]+1;k++) ans=(ans+sdp[i][k])%mod;
		for(int k=0;k<=2*a[n]+1;k++) sdp[i][k]=(sdp[i][k]+sdp[i-1][k])%mod;
	} 
	cout<<ans<<"\n";
	return 0;
}