#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=505,maxm=1e6,mod=1e18;
int n,m,c[maxn],d[maxn],dp[maxm][25],ans,f[maxm],fl;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>c[i],d[i]=s[i-1]-'0';
	for(int i=1;i<=n;i++)if(s[i-1]=='0')fl=1;
	if(!fl){
		ans=1;
		for(int i=1;i<=n;i++)ans=ans*i%mod;
		cout<<ans;
		return 0;
	}
	dp[0][0]=1;
	for(int i=0;i<(1<<n);i++){
		for(int k=0;k<n;k++){
			f[i]+=((i>>k)&1);
		}
	}
	for(int i=1;i<(1<<n);i++){
		for(int j=0;j<=i;j++){
			for(int k=0;k<n;k++){
				bool ffff=((i>>k)&1);
				if(ffff){
					if((s[f[i]-1]=='0')||((f[i]-1-j)>=c[k+1])){
						dp[i][j]=(dp[i][j]+dp[(i^(1<<k))][j])%mod;
					} if(j&&((f[i]-j)<c[k+1])&&(s[f[i]-1]=='1'))dp[i][j]=(dp[i][j]+dp[(i^(1<<k))][j-1])%mod;
				} 
			}				
		//	cout<<i<<' '<<j<<' '<<' '<<dp[i][j]<<'\n';

		}
	}
//	cout<<dp[5][1]<<'\n';
	for(int i=m;i<=n;i++)ans=(ans+dp[(1<<n)-1][i])%mod;
	cout<<ans;
}
