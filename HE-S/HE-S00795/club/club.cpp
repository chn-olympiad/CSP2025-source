#include<bits/stdc++.h>
using namespace std;
int n,t;
int a[10002][5];
int num[100002];
int dp[10002][5001];
int mm[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;

	while(t--){
		int ans=0;

		cin>>n;

		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n/2;j++){
				dp[i][j]=0;
			}
		}
		for(int i=2;i<=i;i++){
			for(int j=1;j<=n/2;j++){
				for(int k=1;k<=3;k++){
					dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]+a[i][k]);
				}

			}
		}
		cout<<dp[n][n/2];
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
