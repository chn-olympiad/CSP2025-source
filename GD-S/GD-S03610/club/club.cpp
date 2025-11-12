#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100005][4];
long long dp[205][205][205];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int yn=1;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][3]!=0){
				yn=0;
			}
		}
		memset(dp,-0x3f,sizeof(dp));
		if(yn){
			dp[1][0][0]=a[1][1];
			dp[0][1][0]=a[1][2];
			long long ans=0;
			for(int i=1;i<=n;i++){
				for(int j=n/2;j>=0;j--){
					for(int k=n/2;k>=0;k--){
						if(j>=1)
							dp[j][k][0]=max(dp[j][k][0],dp[j-1][k][0]+a[i][1]);
						if(k>=1)
							dp[j][k][0]=max(dp[j][k][0],dp[j][k-1][0]+a[i][2]);
						ans=max(ans,dp[j][k][0]);
					}
				}
			}
			cout<<ans<<endl;
		}
		else{
			dp[1][0][0]=a[1][1];
			dp[0][1][0]=a[1][2];
			dp[0][0][1]=a[1][3];
			long long ans=0;
			for(int i=2;i<=n;i++){
				for(int j=n/2;j>=0;j--){
					for(int k=n/2;k>=0;k--){
						for(int l=n/2;l>=0;l--){
							if(j>=1)
								dp[j][k][l]=max(dp[j][k][l],dp[j-1][k][l]+a[i][1]);
							if(k>=1)
								dp[j][k][l]=max(dp[j][k][l],dp[j][k-1][l]+a[i][2]);
							if(l>=1)
								dp[j][k][l]=max(dp[j][k][l],dp[j][k][l-1]+a[i][3]);
							ans=max(ans,dp[j][k][l]);
						}
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0; 
}
