#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+10,MOD=998244353;
ll n,f[N][N],a[N],dp[N];//f[i][j]第i个到j的方案数，优化：5001是顶峰 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		if(i>=3){
			for(int j=5001;j>a[i];j--){
				dp[i]=(dp[i]+f[i-1][j])%MOD;
			}
		}
		for(int j=5001;j>=0;j--){
			f[i][min(5001ll,j+a[i])]=(f[i][min(5001ll,j+a[i])]+f[i-1][j])%MOD;
			f[i][j]=(f[i][j]+f[i-1][j])%MOD;
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans=(ans+dp[i])%MOD;
	}
	printf("%lld",ans);
	return 0;
}
