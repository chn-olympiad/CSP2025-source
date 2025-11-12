//GZ-S00379 贵阳市南明区华麟学校 胡屹轩 
#include<bits/stdc++.h>
using namespace std;
int T;
int a[100000+10][10];
int dp[100000+10][10];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int cnt[10]={0};
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)dp[i][j]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)cin>>a[i][j];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(cnt[j]<=n/2){
					if(dp[i][j-1]<dp[i-1][3]+a[i][j]){
						dp[i][j]=dp[i-1][3]+a[i][j];
						cnt[j]++;
					}
					else{
						dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
					}
				}
				else{
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				}
			}
		}
		cout<<dp[n][3]<<endl;
	}
	return 0;
}
