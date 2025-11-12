#include<bits/stdc++.h>
using namespace std;
#define maxa 6000
const long long mod=998244353;
int n;
long long a[6001];
long long sum[6001];
long long dp[6001][maxa+1];
long long sdp[6001][maxa+1];
long long pow(long long a,long long b,long long m){
	long long res=1;
	while(b){
		if(b&1) (res*=a)%=m;
		(a*=a)%=m;
		b>>=1;
	}
	return res;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	sort(a+1,a+n+1);
	sum[0]=0;
	for(int i=1;i<=n;i++) sum[i]=(sum[i-1]+a[i])%mod;
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=maxa;j++)
			if(j<a[i]) dp[i][j]=dp[i-1][j];
			else dp[i][j]=(dp[i-1][j]+dp[i-1][j-a[i]])%mod;
		sdp[i][0]=dp[i][0];
		for(int j=1;j<=maxa;j++) sdp[i][j]=(sdp[i][j-1]+dp[i][j])%mod;
	}
	long long ans=0;
	for(int i=3;i<=n;i++) (ans+=pow(2,i-1,mod)-sdp[i-1][a[i]])%=mod;
	printf("%lld",ans);
	return 0;
}
