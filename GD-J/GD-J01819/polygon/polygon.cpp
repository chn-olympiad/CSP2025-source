#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005,mod=998244353;
int n,a[N],sum[N],dp[N][N*2];//前i个数，和为j 
int add(int x,int y){return (x+y+mod)%mod;}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
//	dp[0][0]=1;
	dp[1][a[1]]=1;
	dp[1][0]=1;
	for(int i=2;i<=n;i++){
		for(int j=0;j<=sum[i];j++){
			dp[i][j]=add(dp[i-1][j],(j>=a[i])?dp[i-1][j-a[i]]:0ll);
		}	
	}
	int ans=0;
	for(int i=3;i<=n;i++){
		for(int j=a[i]+1;j<=sum[i-1];j++) ans=add(ans,dp[i-1][j]);
	}
	cout<<ans;
	return 0;
}
