#include<bits/stdc++.h>
using namespace std;
int dp[205][105][105],T,n,a[205][5],ans;
void dfs(int x,int pa,int pb,int pc,int Max){
	ans=max(ans,Max);
	if(x==n+1) return ;
	/*if(dp[x][pa][pb]>=Max) return dp[x][pa][pb];
	else dp[x][pa][pb]=Max;*/
	if(pa<n/2){
		dfs(x+1,pa+1,pb,pc,Max+a[x][1]);
	}
	if(pb<n/2){
		dfs(x+1,pa,pb+1,pc,Max+a[x][2]);
	}
	if(pc<n/2){
		dfs(x+1,pa,pb,pc+1,Max+a[x][3]);
	}
//	cout<<x<<" "<<pa<<" "<<pb<<" "<<dp[x][pa][pb]<<"\n";
//	return dp[x][pa][pb];
}
int main(){
	ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
//		memset(dp,-1,sizeof(dp));
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		dfs(1,0,0,0,0);
//		cout<<dfs(1,0,0,0)<<"\n";
		cout<<ans<<"\n";
	}
	return 0;
}