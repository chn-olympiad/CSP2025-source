//GZ-S00231 观山湖中学 李朋钊
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[205][4], dp[205][4][105];
ll res;
int vis[4];
int n;
void dfs(int i,ll sum){
	if(i>n) return res=max(res,sum),void();
	for(int j=1;j<=3;j++)if(vis[j]<n/2){
		vis[j]++;
		dfs(i+1, sum+a[i][j]);
		vis[j]--;
	}
}
void solve(){
	cin>>n;
	if(n<=10){
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		res=0;
		dfs(1, 0);
		cout<<res<<'\n';
		return ;
	}
	memset(dp,0,sizeof dp);
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		for(int j=1;j<=3;j++){
			for(int k=n/2;k>=1;k--){
				dp[i][j][k]=max(dp[i-1][j][k-1]+a[i][j],dp[i-1][j][k]);             
			}
		}
	}
	ll maxn=0;
	for(int i=1;i<=n/2;i++){
		for(int j=n/2;j>=1;j--){
			if(n-i-j<=n/2){
				maxn=max(dp[n][1][i]+dp[n][2][j]+dp[n][3][n-j-i],maxn);
			}
		}
	}
	cout<<maxn<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
