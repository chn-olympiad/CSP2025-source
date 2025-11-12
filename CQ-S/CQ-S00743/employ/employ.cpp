#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,a[505],b[505],dp[2][505][505],sum[505],inv[505],g[505];
int c[505],inc[505];
int C(int n,int m){
	return c[n]*inc[n-m]%mod*inc[m]%mod;
}
void upd(int &x,int y){
	x=(x+y)%mod;
}
namespace Sol1{
	int dp[1<<18][19];
	int pcnt[1<<18];
	void main(){
		dp[0][0]=1;
		for(int i=0;i<(1<<n);i++)pcnt[i]=__builtin_popcountll(i);
		for(int s=0;s<(1<<n);s++){
			int p=pcnt[s]+1;
			for(int r=0;r<p;r++){
				for(int i=1;i<=n;i++){
					if(!(s>>(i-1)&1)){
						if(a[p]){
							if(b[i]>=p-r)upd(dp[s|(1<<i-1)][r+1],dp[s][r]);
							else upd(dp[s|(1<<i-1)][r],dp[s][r]);
						}
						else upd(dp[s|(1<<i-1)][r],dp[s][r]);
					}
				}
			}
		}
		int ans=0;
		for(int i=m;i<=n;i++)upd(ans,dp[(1<<n)-1][i]);
		printf("%lld",ans);
		exit(0);
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	int SS=0;
	for(int i=1;i<=n;i++)scanf("%1lld",&a[i]),SS+=a[i];
	for(int i=1;i<=n;i++)scanf("%lld",&b[i]),sum[b[i]]++;
	for(int i=n;i>=1;i--)sum[i]+=sum[i+1];
	if(SS==n){
		int res=1;
		for(int i=1;i<=n;i++)res=res*i%mod;
		printf("%lld",res);
		return 0;
	}
	if(m>SS){
		puts("0");
		return 0;
	}
	inv[1]=1;
	for(int i=2;i<=n;i++)inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	c[0]=inc[0]=1;
	for(int i=1;i<=n;i++)c[i]=c[i-1]*i%mod,inc[i]=inc[i-1]*inv[i]%mod;
	if(n<=18)Sol1::main();
	if(m==1){
		int res=1,ct=0;
		for(int i=0;i<=n;i++)sum[i]=0;
		for(int i=1;i<=n;i++)sum[b[i]]++;
		for(int i=1;i<=n;i++)sum[i]+=sum[i-1];
		for(int i=1;i<=n;i++){
			if(a[i]){
				if(sum[i]-ct>=0)res=res*(sum[i-1]-ct)%mod;
				else res=0;
				ct++;
			}
		}
		res=res*c[n-SS]%mod;
		printf("%lld",res);
		return 0;
	}
	for(int i=0;i<=n;i++)dp[n&1][i][0]=1;
	for(int i=n;i>=1;i--){
		for(int j=0;j<=n;j++)for(int k=0;k<=n;k++)dp[(i-1)&1][j][k]=0;
		for(int j=0;j<=n;j++){
			for(int k=0;k<=n;k++){
				if(a[i]){
					if(j)upd(dp[(i-1)&1][j-1][k],dp[i&1][j][k]);
					if(sum[j+1]-k>=0)upd(dp[(i-1)&1][j][k+1],dp[i&1][j][k]*(sum[j+1]-k)%mod);
				}
				else{
					if(j)upd(dp[(i-1)&1][j-1][k],dp[i&1][j][k]);
				}
			}
		}
	}
	for(int i=0;i<=n;i++)dp[0][0][i]=dp[0][0][i]*c[n-i]%mod;
	for(int i=0;i<=n;i++){
		for(int j=i;j<=n;j++){
			g[i]=(g[i]+((j-i)%2?-1:1)*C(j,i)%mod*dp[0][0][j]%mod+mod)%mod;
		}
	}
	int ans=0;
	for(int i=m;i<=n;i++)ans=(ans+g[i])%mod;
	printf("%lld\n",ans);
	return 0;
}
