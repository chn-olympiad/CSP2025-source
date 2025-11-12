#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=505,MOD=998244353;
string s;int n,m,c[MAXN];
ll fac[MAXN],dp[MAXN][MAXN],tdp[MAXN][MAXN];
// previous i days, j baned, k limit use smaller one
// i was rolled
inline void add(ll &x,ll y){x=(x+y)%MOD;}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;s=" "+s;
	for(int i=1;i<=n;i++){
		int x;cin>>x;c[x]++;
	}
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%MOD;
	for(int i=1;i<=n;i++) c[i]+=c[i-1];
	dp[0][0]=1;
	for(int i=0;i<n;i++){
		// transfer to day #i
		memset(tdp,0,sizeof(tdp));
		for(int j=0;j<=i;j++) for(int k=0;k<=i;k++) if(dp[j][k]){
//			cerr<<"dp["<<j<<"]["<<k<<"] : "<<dp[j][k]<<endl;
			if(s[i+1]=='0') {add(tdp[j+1][k],dp[j][k]);continue;}
			// choose
			add(tdp[j][k],dp[j][k]);
			add(tdp[j][k+1],-(c[j]-k)*dp[j][k]); 
			add(tdp[j+1][k+1],(c[j]-k)*dp[j][k]);
		}
		memcpy(dp,tdp,sizeof(tdp));
	}
	ll ans=0;
	for(int i=0;i<=n-m;i++) for(int j=0;j<=n;j++) add(ans,dp[i][j]*fac[n-j]);
	cout<<(ans%MOD+MOD)%MOD<<'\n';
}

