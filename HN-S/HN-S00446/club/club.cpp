#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--){
		int n,a[100009][3],dp[50][50][50],ans=0;
		memset(dp,0,sizeof(dp));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		for(int i=1;i<=n;i++){
			for(int j=n/2;j>=1;j--){
				for(int k=n/2;k>=1;k--){
					for(int l=n/2;l>=1;l--){
						if(i) dp[j][k][l]=max(dp[j][k][l],dp[j-1][k][l]+a[i][0]);
						if(j) dp[j][k][l]=max(dp[j][k][l],dp[j][k-1][l]+a[i][1]);
						if(k) dp[j][k][l]=max(dp[j][k][l],dp[j][k][l-1]+a[i][2]);
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n/2;j++){
				for(int k=1;k<=n/2;k++){
					ans=max(ans,dp[i][j][k]);
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

