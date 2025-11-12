#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e2+7;
const ll M=1e2+7;
const ll mod=998244353;
void in(ll &num){
	ll k=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		k=10*k+c-'0';
		c=getchar();
	}
	num=k*f;
}
ll n,k,dp[N][N*M],sum[N*M];
bool flag=1;
ll a[N*10];
ll allsum[N],ans;
ll inv[N*10],jc[N*10];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	in(n);
	for(ll i=1;i<=n;i++){
		in(a[i]);
		if(a[i]!=1){
			flag=0;
		}
		allsum[i]=(allsum[i-1]+a[i])%mod;
	}
	if(flag){
		jc[0]=jc[1]=inv[0]=inv[1]=1;
		for(ll i=2;i<=n;i++){
			jc[i]=jc[i-1]*i%mod;
			inv[i]=(mod-mod/i)*inv[mod%i]%mod;
		}
		for(ll i=2;i<=n;i++){
			inv[i]=inv[i]*inv[i-1]%mod;
		}
		for(ll i=3;i<=n;i++){
			ans=(ans+jc[n]*inv[i]%mod*inv[n-i])%mod;
		}
		printf("%lld",ans);
		return 0;
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		dp[i][a[i]]=1;
		dp[i][0]=1;
		for(ll j=a[i]+1;j<=min(2*a[i],allsum[i]);j++){
			dp[i][j]=sum[j-a[i]];
		}
		for(ll j=2*a[i]+1;j<=allsum[i];j++){
			dp[i][j]=sum[j-a[i]];
			if(i>=3){
				ans+=dp[i][j];
				ans%=mod;
			}
		}
		for(ll j=allsum[i];j>=0;j--){
			sum[j]=(sum[j]+dp[i][j])%mod;
		}
	}
	printf("%lld",ans);
	return 0;
}

