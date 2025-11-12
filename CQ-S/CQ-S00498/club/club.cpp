#include<bits/stdc++.h>
using namespace std;
int n,stu[100005][3],vis[100005],ans=0,dp[100005][3];
void dfs(int now,int sum){
	if(now==n){
		ans=max(ans,sum);
		return;
	}
	for(int i=0;i<3;i++){
		if(vis[i+1]){
			vis[i+1]--;
			dfs(now+1,sum+stu[now+1][i]);
			vis[i+1]++; 
		}
	} 
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>stu[i][0]>>stu[i][1]>>stu[i][2];
			vis[i]=n/2;
		}
		if(n<=10){//小L能心算的范围 
			dfs(0,0);
			cout<<ans<<"\n";
			ans=0;
		} 
		else{//乐子做法 
			memset(dp,0,sizeof(dp));
			dp[1][0]=stu[1][0];
			dp[1][1]=stu[1][1];
			dp[1][2]=stu[1][2];
			for(int i=2;i<=n;i++){
				dp[i][0]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]))+stu[i][0];
				dp[i][1]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]))+stu[i][1];
				dp[i][2]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]))+stu[i][2];
			}
			cout<<max(dp[n][0],max(dp[n][1],dp[n][2]))<<"\n";
		}
	}
	
	return 0;
}
