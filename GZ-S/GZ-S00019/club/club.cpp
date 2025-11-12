//GZ-S00019 遵义航天高级中学 伍钰星 
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int T,n;
const int N=100005;
int sum[4],vis[N],a[N][4],ans;
int dp[N][4];
int mid;
void dfs(int x,int y){
	for(int i=1;i<=3;i++){
		if(sum[i]<mid){
			sum[i]++;
			dp[x][i]=max(dp[x][i],a[x][i]+dp[x-1][y]);
			dfs(x+1,i);
			sum[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>T;
	while(T--){
		cin>>n;
		mid=n>>1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		for(int i=1;i<=3;i++){
			dfs(i,0);
		}
		cout<<max(dp[n][1],max(dp[n][2],dp[n][3]));
	}
	return 0;
}

