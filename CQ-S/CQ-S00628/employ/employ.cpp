#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
ll dp[25][300005];
int n,m,c[25];
char s[25];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n>=20){
		ll ans=1;
		for(int i=n;i>=n-m;i++) ans=(ans*i)%mod;
		printf("%lld\n",ans);
		return 0;
	} 
	for(int i=1;i<=n;i++){
		scanf("%c",&s[i]);
		if(s[i]!='0'&&s[i]!='1') i--;
	}
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	dp[0][0]=1;
	for(int i=0;i<n;i++){
		for(int j=1;j<(1<<n);j++){
			int x=j,sum=0;
			while(x) sum+=(x&1),x>>=1;
			for(int k=0;k<n;k++){
				if(j&(1<<k)){
					if(s[sum]=='0') dp[i+1][j]=(dp[i+1][j]+dp[i][j^(1<<k)])%mod;
					else if(c[k+1]>i) dp[i][j]=(dp[i][j]+dp[i][j^(1<<k)])%mod;
					else dp[i+1][j]=(dp[i+1][j]+dp[i][j^(1<<k)])%mod;
				}
			}
		}
	}
	ll ans=0;
	for(int i=0;i<=n-m;i++) ans=(ans+dp[i][(1<<n)-1])%mod;
	printf("%lld\n",ans);
	return 0;
}

