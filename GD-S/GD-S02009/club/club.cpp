#include<iostream>
#include<cstring>
using namespace std;
int t,n;
int dp[204][204][204];//已判断i人，其中j人加入1组，l人加入2组 
int a1[204],a2[204],a3[204];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	
	while(t--){
		int ans=0;
		cin>>n;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
		}
		dp[1][1][0]=a1[1];
		dp[1][0][1]=a2[1];
		dp[1][0][0]=a3[1];
		for(int i=2;i<=n;i++){
			for(int j=0;j<=n/2;j++){
				for(int k=0;j+k<=i&&k<=n/2;k++){
					if(i-j-k>n/2)continue;
					if(j!=0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a1[i]);
					if(k!=0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a2[i]);
					if(i-j-k!=0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a3[i]);
					ans=max(ans,dp[i][j][k]);
				}
			}
		} 
		cout<<ans<<endl;
	}
	
	return 0;
} 
