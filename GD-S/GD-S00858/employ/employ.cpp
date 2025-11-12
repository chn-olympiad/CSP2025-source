#include <bits/stdc++.h>
#define ll long long
#define rep(t,l,r) for(int t=l;t<=r;t++)
#define per(t,l,r) for(int t=r;t>=l;t--)

using namespace std;
const int N=18,M=(1<<N)+10,mod=998244353;
int n,m,s[510],c[510],dp[M][N],f[510][510];

signed main() {
	freopen("employ.in","r",stdin); 
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m; rep(i,1,n) {char t; cin>>t; s[i]=t-'0';}
	rep(i,1,n) cin>>c[i];
	if(n>18&&n==m) {
		bool ok=true;
		rep(i,1,n) ok&=(s[i]==1);
		rep(i,1,n) ok&=(c[i]>=1);
		int ans; if(ok==1) ans=1; else ans=0;
		rep(i,1,n) ans=1ll*ans*i%mod;
		cout<<ans<<"\n";
		return 0;
	}
	dp[0][0]=1;
	rep(S,0,(1<<n)-1) rep(i,0,__builtin_popcount(S)) {
		int ct=max(0,__builtin_popcount(S)-i);
		rep(j,0,n-1) if(!((S>>j)&1)) {
			if(c[j+1]>ct&&s[__builtin_popcount(S)+1]==1) dp[S|(1<<j)][i+1]=(0ll+dp[S|(1<<j)][i+1]+dp[S][i])%mod;
			else dp[S|(1<<j)][i]=(0ll+dp[S|(1<<j)][i]+dp[S][i])%mod;
		}
	}
	int ans=0;
	rep(i,m,n) ans=(0ll+ans+dp[(1<<n)-1][i])%mod;
	cout<<ans<<"\n";
	return 0;
}
