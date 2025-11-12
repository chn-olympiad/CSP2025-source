#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3 +5;
const int mod=998244353;
ll a[N],dp[N][N],n,ans;
ll fpow(ll b){
	ll a=2,ans=1;
	while(b){
		if(b&1)ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans;
}
ll dfs(ll i,ll j){
	if(i==0)return 0;
	if(dp[i][j]!=-1)return dp[i][j];
	if(a[i]>j)dp[i][j]=fpow(i-1)+dfs(i-1,j);
	else dp[i][j]=(dfs(i-1,j-a[i])+dfs(i-1,j))%mod;
	return dp[i][j];
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	memset(dp,-1,sizeof(dp));
	for(int i=3;i<=n;i++){
		ans=(ans+dfs(i-1,a[i]))%mod;
	}
	cout<<ans;
	return 0;
}
/*
11:00补豪，调不出来了 qwq 
11:10 666快速幂忘写b>>=1了qwq 
11:30 AK!!!!!!!!!





*/
