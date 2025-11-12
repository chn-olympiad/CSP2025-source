#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100005][4];
long long dp[100005][4];
int cnt[100005][4][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		}
		for(int i=1;i<=n;i++){
			dp[i][1]=dp[i][2]=dp[i][3]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(dp[i-1][1]>=dp[i-1][2]&&dp[i-1][1]>=dp[i-1][3]){
					if(cnt[i-1][1][j]==n/2){
						if(dp[i-1][2]>=dp[i-1][3]){
							dp[i][j]=dp[i-1][2]+a[i][j];
							for(int p=1;p<=3;p++){
								cnt[i][j][p]=cnt[i-1][2][p];
							}
							cnt[i][j][j]++;
						}else{
							dp[i][j]=dp[i-1][3]+a[i][j];
							for(int p=1;p<=3;p++){
								cnt[i][j][p]=cnt[i-1][3][p];
							}
							cnt[i][j][j]++;
						}
					}else{
						dp[i][j]=dp[i-1][1]+a[i][j];
						for(int p=1;p<=3;p++){
							cnt[i][j][p]=cnt[i-1][1][p];
						}
						cnt[i][j][j]++;
					}
				}else if(dp[i-1][2]>=dp[i-1][1]&&dp[i-1][2]>=dp[i-1][3]){
					if(cnt[i-1][2][j]==n/2){
						if(dp[i-1][1]>=dp[i-1][3]){
							dp[i][j]=dp[i-1][1]+a[i][j];
							for(int p=1;p<=3;p++){
								cnt[i][j][p]=cnt[i-1][1][p];
							}
							cnt[i][j][j]++;
						}else{
							dp[i][j]=dp[i-1][3]+a[i][j];
							for(int p=1;p<=3;p++){
								cnt[i][j][p]=cnt[i-1][3][p];
							}
							cnt[i][j][j]++;
						}
					}else{
						dp[i][j]=dp[i-1][2]+a[i][j];
						for(int p=1;p<=3;p++){
							cnt[i][j][p]=cnt[i-1][2][p];
						}
						cnt[i][j][j]++;
					}
				}else{
					if(cnt[i-1][3][j]==n/2){
						if(dp[i-1][1]>=dp[i-1][2]){
							dp[i][j]=dp[i-1][1]+a[i][j];
							for(int p=1;p<=3;p++){
								cnt[i][j][p]=cnt[i-1][1][p];
							}
							cnt[i][j][j]++;
						}else{
							dp[i][j]=dp[i-1][2]+a[i][j];
							for(int p=1;p<=3;p++){
								cnt[i][j][p]=cnt[i-1][2][p];
							}
							cnt[i][j][j]++;
						}
					}else{
						dp[i][j]=dp[i-1][3]+a[i][j];
						for(int p=1;p<=3;p++){
							cnt[i][j][p]=cnt[i-1][3][p];
						}
						cnt[i][j][j]++;
					}
				}
			}
		}
		printf("%lld\n",max(dp[n][1],max(dp[n][2],dp[n][3])));
	}
	return 0;
}