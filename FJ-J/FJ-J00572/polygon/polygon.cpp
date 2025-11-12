#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e3+5,mod=998244353;
int n,a[maxn],dp[maxn][maxn],cnt,ans; 
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	dp[0][0]=1;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=a[i]+1;j<=5000;j++) ans+=dp[i-1][j],ans%=mod;
		ans+=cnt,ans%=mod;
		cnt*=2,cnt%=mod;
		for(int j=0;j<=5000;j++){
			dp[i][j]+=dp[i-1][j],dp[i][j]%=mod;
			if(j+a[i]>5000) cnt+=dp[i-1][j],cnt%=mod;
			else dp[i][j+a[i]]+=dp[i-1][j],dp[i][j+a[i]]%=mod;
		}
	}
	cout<<ans;
} 
//最后的告别了，说我把初恋交给了OI也不为过吧… 
