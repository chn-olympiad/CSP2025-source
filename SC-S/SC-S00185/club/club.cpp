#include<bits/stdc++.h>
using namespace std;

int a[100005][3],dp[3][50000];
int f[100005];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<3;i++)
			for(int j=0;j<=n/2;j++) dp[i][j]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		for(int i=1;i<=n;i++){
			for(int j=2;j>=0;j--){
				for(int k=n/2;k>=1;k--){
					if(dp[j][k-1]+a[i][j]>dp[j][k]){
						dp[j][k]=dp[j][k-1]+a[i][j];
						f[i]=j;
					}
				}
			}
		}
		int ans=-0x3f3f3f3f;
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				int k=n-i-j;
				if(k>n/2) break;
				ans=max(ans,dp[0][i]+dp[1][j]+dp[2][k]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}