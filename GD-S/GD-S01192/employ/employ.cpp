#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[510],dp[20][1<<18];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++)cin>>c[i];
	sort(c,c+n);
	if(n<=18){
		dp[0][0]=1;
		for(int i=0;i<(1<<n);i++){
			int cnt=__builtin_popcount(i);
			for(int j=0;j<=cnt;j++){
				for(int k=0;k<n;k++)if(!(i&(1<<k))){
					if(s[cnt]=='0'||c[k]<=cnt-j)dp[j][i|(1<<k)]=(dp[j][i|(1<<k)]+dp[j][i])%mod;
					else dp[j+1][i|(1<<k)]=(dp[j+1][i|(1<<k)]+dp[j][i])%mod;
				}
			}
		}
		int ans=0;
		for(int j=m;j<=n;j++)ans=(ans+dp[j][(1<<n)-1])%mod;
		cout<<ans;
	}
}
