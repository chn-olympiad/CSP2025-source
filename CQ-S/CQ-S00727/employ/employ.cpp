#include<bits/stdc++.h>
using namespace std;
#define MAXN 500
const int mod=998244353;
long long qpow(long long a,long long b){
	long long ret=1;
	while(b){
		if(b%2) ret=ret*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return ret;
}

long long fac[MAXN+5],inv[MAXN+5];
void init(){
	fac[0]=inv[0]=1;
	for(int i=1;i<=MAXN;i++) fac[i]=fac[i-1]*i%mod;
	inv[MAXN]=qpow(fac[MAXN],mod-2);
	for(int i=MAXN-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%mod;
}
long long C(long long x,long long y){
	if(x<0||y<0||x<y) return 0;
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
long long dp[MAXN+5][MAXN+5];
int n,m,cnt[MAXN+5],sum[MAXN+5],a[MAXN+5];
string s;
int main(){
	freopen("employ2.in","r",stdin);
	//freopen(".out","w",stdout);
	init();
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(s[i-1]=='1') sum[i]=sum[i-1];
		else sum[i]=sum[i-1]+1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]>sum[j]) cnt[i]=j-sum[j];
			else if(a[i]==sum[j]&&s[j-1]=='0') cnt[i]=j-sum[j];
			else break;
		}
	}
	for(int i=1;i<=n;i++) cout<<cnt[i]<<' ';
	cout<<endl;
	int now=1;
	long long ans=0;
	for(int i=m;i<=n;i++){
		for(int j=1;j<=n;j++) 
			for(int k=1;k<=n;k++) dp[j][k]=0;
		dp[0][0]=1;
		for(int j=1;j<=n;j++){
			for(int k=0;k<=i;k++){
				dp[j][k]=dp[j-1][k];
				if(k) dp[j][k]=(dp[j][k]+dp[j-1][k-1]*max(0,cnt[j]-k+1))%mod;
			}
		}
		cout<<dp[n][i]<<' '<<fac[n-i]<<' '<<now<<endl;
		ans=(ans+dp[n][i]*fac[n-i]*now%mod)%mod;
		now=-now;
	}
	printf("%lld\n",ans);
} 
