#include<bits/stdc++.h>
using namespace std;
int n,m,k,dp[1011][1011],dp2[1011][1011][2],ans[11],cnt;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int d,e,f;
		cin>>d>>e>>f;
		dp[d][e]=f;
		dp[e][d]=f;
	}
	for(int i=1;i<=k;i++){
		cin>>ans[i];
		for(int j=1;j<=n;j++){
			int e,f;
			cin>>f;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(dp[i][j]<=0) dp[i][j]=1e4;
			if(i==j) dp[i][j]=0;
		}
	}
	for(int e=1;e<=n;e++){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][e]+dp[e][j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			cnt+=dp[i][j];
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
