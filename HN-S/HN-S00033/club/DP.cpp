#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[100005][3],dp[2][100005][3][2];
signed main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
//	int T;
//	cin>>T;
//	while(T--){
//		cin>>n;
//		for(int i=1;i<=n;i++)cin>>a[i][0]>>a[i][1]>>a[i][2];
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n/2;j++){//0
//				for(int k=1;k<=n/2;k++){//1
//					int l=n-j-k;//2
//					int t=max(dp[(i-1)%2][j][0][0],dp[(i-1)%2][j][0][1]);
//					dp[i%2][j][0][0]=t;
//					t=max(dp[(i-1)%2][j-1][0][0],dp[(i-1)%2][j-1][0][1]);
//					dp[i%2][j][0][1]=t+a[i][0];
//					//0
//					t=max(dp[(i-1)%2][j][1][0],dp[(i-1)%2][j][1][1]);
//					dp[i%2][j][1][0]=t;
//					t=max(dp[(i-1)%2][j-1][1][0],dp[(i-1)%2][j-1][1][1]);
//					dp[i%2][j][1][1]=t+a[i][1];
//					//1
//					t=max(dp[(i-1)%2][j][2][0],dp[(i-1)%2][j][2][1]);
//					dp[i%2][j][2][0]=t;
//					t=max(dp[(i-1)%2][j-1][2][0],dp[(i-1)%2][j-1][2][1]);
//					dp[i%2][j][2][1]=t+a[i][2];
//					//2
//				}
//			}
//		}
//		int maxn=0;
//		for(int i=1;i<=n/2;i++){
//			for(int j=1;j<=n/2;j++){
//				int k=n-i-j;
//				if(dp[(n-1)%2][j][1][1]>dp[(n-1)%2][k][2][1]){
//					maxn=max(maxn,dp[n%2][i][0][1]+dp[(n-1)%2][j][1][1]+dp[n%2][k][2][0]);
//				}
//				else{
//					maxn=max(maxn,dp[n%2][i][0][1]+dp[n%2][j][1][0]+dp[(n-1)%2][k][2][1]);
//				}
//				if(dp[(n-1)%2][i][0][1]>dp[(n-1)%2][k][2][1]){
//					maxn=max(maxn,dp[(n-1)%2][i][0][1]+dp[n%2][j][1][1]+dp[n%2][k][2][0]);
//				}
//				else{
//					maxn=max(maxn,dp[n%2][i][0][1]+dp[n%2][j][1][1]+dp[(n-1)%2][k][2][1]);
//				}
//				if(dp[(n-1)%2][j][1][1]>dp[(n-1)%2][i][0][1]){
//					maxn=max(maxn,dp[n%2][i][0][1]+dp[(n-1)%2][j][1][1]+dp[n%2][k][2][1]);
//				}
//				else{
//					maxn=max(maxn,dp[(n-1)%2][i][0][1]+dp[n%2][j][1][0]+dp[n%2][k][2][1]);
//				}
//			}
//		}
//		cout<<maxn<<"\n";
//		memset(dp,0,sizeof(dp));
//	}
	map<int,int>mp;
	mp[1]=2;
	return 0;
}

