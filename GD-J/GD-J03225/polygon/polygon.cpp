#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+10,mod=998244353;
int a[N],sl[N],c[N][N],dp[N][N],sum[N],n,pl[N];//dp[i][j]表示前i个数中有多少种和大于j的方式 
int C(int x,int y){
	if(c[x][y])return c[x][y];
	if(x==0||x==y)return 1;
	return c[x][y]=(C(x-1,y)+C(x-1,y-1))%mod;
}
int su(int x){
	return (int)pow(2,x);
}
int dfs(int x,int y){
	if(y==0)return su(x)-1;
	if(y<0)return su(x);
	if(sum[x]<=y)return 0;
	if(dp[x][y]!=-1)return dp[x][y];
	dp[x][y]=0;
	for(int i=x;i>=1;i--){
		if(sum[i-1]<=y-a[i])break;
		dp[x][y]=(dp[x][y]+dfs(i-1,y-a[i]))%mod;
	}
	return dp[x][y];
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	memset(c,0,sizeof(c));memset(dp,-1,sizeof(dp));
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]),sum[i]=sum[i-1]+a[i];
	for(int i=0;i<sum[1];i++)dp[1][i]=1;
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=3;i<=n;i++)ans=(ans+dfs(i-1,a[i]))%mod;
	printf("%lld\n",ans);
	return 0;
} 
