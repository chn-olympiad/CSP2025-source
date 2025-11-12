#include <bits/stdc++.h>
#define int long long
#define popcount __builtin_popcount
using namespace std;
const int N=505,mod=998244353;
int n,m,s[N],c[N],dp[(1<<18)+5][23],JC[N];
void solve1(){
	dp[0][0]=1;
	for(int st=0;st<1<<n;st++) for(int hv=0;hv<=n;hv++) if(dp[st][hv]){
		for(int k=0;k<n;k++) if(!(st>>k&1)) (dp[st|1<<k][hv+(s[popcount(st)+1]==0||hv>=c[k+1])]+=dp[st][hv])%=mod;
	}
	int ans=0;
	for(int gt=m;gt<=n;gt++) (ans+=dp[(1<<n)-1][n-gt])%=mod;
	cout<<(ans%mod+mod)%mod;
}
void solve3(){
	for(int i=1;i<=n;i++) if(c[i]==0||s[i]==0) return cout<<0,void();
	cout<<(JC[n]%mod+mod)%mod;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char _s;cin>>_s;
		s[i]=_s-'0';
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	JC[0]=1;
	for(int i=1;i<=n;i++) JC[i]=JC[i-1]*i%mod;
	
	if(n<=18) solve1();
	else solve3();
	return 0;
}