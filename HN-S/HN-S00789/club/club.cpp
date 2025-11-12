#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,a[100005][5],dp[35][35][35][35];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<=min(i,n/2);j++){
				for(int k=0;k<=min(i,n/2);k++){
					for(int q=0;q<=min(i,n/2);q++){
						dp[i][j][k][q]=dp[i-1][j][k][q];
						if(j>0){
							dp[i][j][k][q]=max(dp[i][j][k][q],dp[i-1][j-1][k][q]+a[i][1]);
						}
						if(k>0){
							dp[i][j][k][q]=max(dp[i][j][k][q],dp[i-1][j][k-1][q]+a[i][2]);
						}
						if(q>0){
							dp[i][j][k][q]=max(dp[i][j][k][q],dp[i-1][j][k][q-1]+a[i][3]);
						}
					}
				}
			}
		}
		int ans=0;
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=n/2;k++){
					ans=max(ans,dp[n][i][j][k]);
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
