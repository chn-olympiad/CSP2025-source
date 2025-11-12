#include<bits/stdc++.h>
using namespace std;
#define N 200001
int t;
int n;
int a[N][3];
long long dp[602][301][301];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		dp[1][1][0]=a[1][0];
		dp[1][0][1]=a[1][1];
		dp[1][0][0]=a[1][2];
		for(int i=2;i<=n;i++){
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=n/2;k++){
					dp[i][j][k]=0;
					if(j>0){
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][0]);
					}
					if(k>0){
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][1]);
					}
					dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i][2]);
				}
			}
		}
		long long res=0;
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				if(n-i-j>n/2) continue;
				res=max(res,dp[n][i][j]);
			}
		}
		cout<<res<<'\n';
	}
	return 0;
} 
