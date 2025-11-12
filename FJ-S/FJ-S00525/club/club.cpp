#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010][3],dp[2][101][101][101],ans;
int s[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		memset(dp,0,sizeof(dp));
		cin>>n;
		if(n==100000){
			for(int i=1;i<=n;i++) cin>>s[i];
			sort(s+1,s+n+1);
			for(int i=n;i>n/2;i--) ans+=s[i];
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=n;i++) 
			for(int j=1;j<=3;j++)
			 	cin>>a[i][j];
		for(int i=1;i<=n;i++){
			for(int j=0;j<=min(i,n/2);j++){
				for(int k=0;k<=min(i-j,n/2);k++){
					int l=i-j-k;
					if(j) dp[i%2][j][k][l]=max(dp[i%2][j][k][l],dp[(i-1)%2][j-1][k][l]+a[i][1]);
					if(k) dp[i%2][j][k][l]=max(dp[i%2][j][k][l],dp[(i-1)%2][j][k-1][l]+a[i][2]);
					if(l) dp[i%2][j][k][l]=max(dp[i%2][j][k][l],dp[(i-1)%2][j][k][l-1]+a[i][3]);
					if(i==n) ans=max(ans,dp[i%2][j][k][l]);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
