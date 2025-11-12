#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100005][4];
int dp[205][105][105][105];
int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){ 
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=0;i<=n;i++) for(int x=0;x<=n;x++) for(int y=0;y<=n;y++) for(int z=0;z<=n;z++) dp[i][x][y][z]=0;
		dp[1][1][0][0]=a[1][1],dp[1][0][1][0]=a[1][2],dp[1][0][0][1]=a[1][3];
		int ans=0;
		for(int i=2;i<=n;i++){
			int maxn=0;
			for(int x=0;x<i;x++) 
				for(int y=0;y<i-x+1;y++) {
					if(x<=n/2&&x>0) dp[i][x][y][i-x-y]=max(dp[i][x][y][i-x-y],dp[i-1][x-1][y][i-x-y]+a[i][1]);
					if(y<=n/2&&y>0) dp[i][x][y][i-x-y]=max(dp[i][x][y][i-x-y],dp[i-1][x][y-1][i-x-y]+a[i][2]);
					if(i-x-y<=n/2&&i-x-y>0) dp[i][x][y][i-x-y]=max(dp[i][x][y][i-x-y],dp[i-1][x][y][i-x-y-1]+a[i][3]);
				//dp[i][x][y][i-x-y]=max(max(dp[i-1][x][y][i-x-y-1]+a[i][3],dp[i-1][x-1][y][i-x-y]+a[i][1]),dp[i-1][x][y-1][i-x-y]+a[i][2]);
				//	maxn=max(maxn,dp[i][x][y][i-x-y]);
					if(i==n) ans=max(ans,dp[i][x][y][i-x-y]);
				}
			//cout<<maxn<<endl;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
