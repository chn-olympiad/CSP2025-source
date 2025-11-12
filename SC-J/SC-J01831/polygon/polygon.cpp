#include<bits/stdc++.h>
using namespace std;
const long long N=5005,mod=998244353;
long long n,a[N],maxx,pow_[N],ans;
long long dp[N][N];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	pow_[0]=1;
	cin>>n;
	for(int i=1;i<=n;i++)pow_[i]=pow_[i-1]*2%mod;
	for(int i=1;i<=n;i++)cin>>a[i],maxx=max(maxx,a[i]);
	sort(a+1,a+n+1); 
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=maxx;j++){
			if(j<a[i])dp[i][j]=dp[i-1][j];
			else dp[i][j]=(dp[i-1][j]+dp[i-1][j-a[i]])%mod;
		}
	for(int i=3;i<=n;i++){
		long long ansx=0;
		for(int j=0;j<=a[i];j++)ansx=(ansx+dp[i-1][j])%mod;
		ans+=(pow_[i-1]-ansx+mod)%mod;
		ans%=mod; 
	}
	cout<<ans;
	return 0;
}