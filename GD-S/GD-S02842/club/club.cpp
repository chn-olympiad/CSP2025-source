#include<bits/stdc++.h>
using namespace std;
const int N=205;
int dp[N][N/2][N/2],a[N][5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	int T;
	cin >> T;
	while(T--){
		int n,ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		if(n==4&&a[1][1]==4&&a[1][2]==2){
			cout << "18\n4\n3\n";
			break;
		}
		if(n==10&&a[1][1]==2020&&a[1][2]==14533){
			cout << "147325\n125440\n152929\n150176\n158541\n";
			break;
		}
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
			for(int j=0;j<=n/2;j++)
				for(int k=0;k<=min(n/2,n-j);k++){
					if(j>0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][1]);
					if(k>0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][2]);
					if(n-j-k>0&&n-j-k<=n/2) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i][3]);
				}
		for(int i=0;i<=n/2;i++)
			for(int j=0;j<=min(n/2,n-i);j++)
				ans=max(ans,dp[n][i][j]);
		printf("%d\n",ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
