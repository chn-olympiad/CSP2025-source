#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,a[505],dp[(1<<20)+5][21],ans;
char c[505];
const int mod=998244353;
signed main(){
	freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<n;i++){
		c[i]=getchar();
		while(!(c[i]=='0'||c[i]=='1')) c[i]=getchar();
	}
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	dp[0][0]=1;
	for(int i=0;i<(1<<n);i++){
		int cnt=0;
		for(int j=0;j<n;j++)
			if((i>>j)&1)
				cnt++;
		for(int j=0;j<=cnt;j++){
			for(int k=0;k<n;k++){
				if((i>>k)&1) continue;
				if(c[cnt]=='1') 
					dp[i|(1<<k)][j+((cnt-j)<a[k])]=(dp[i|(1<<k)][j+((cnt-j)<a[k])]+dp[i][j])%mod;
				else 
					dp[i|(1<<k)][j]=(dp[i|(1<<k)][j]+dp[i][j])%mod;
 			}
		}
	}
	for(int i=m;i<=n;i++) ans=(ans+dp[(1<<n)-1][i])%mod;
	return printf("%lld\n",ans),0;
}
