#include <iostream>
#include <cstring>
using namespace std;
int T,n,dp[105][105][105],a[205][3];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--&&cin>>n){
		memset(dp,0,sizeof(dp));
		int ans=-0x7fffffff;
		for(int i=1;i<=n;i++)cin>>a[i][0]>>a[i][1]>>a[i][2];
		dp[1][0][0]=a[1][0],dp[0][1][0]=a[1][1],dp[0][0][1]=a[1][2];
		for(int i=0;(i<<1)<=n;i++){
			for(int j=0;i+j<=n&&(j<<1)<=n;j++){
				for(int k=0;i+j+k<=n&&(k<<1)<=n;k++){
					int pos=i+j+k;
					if(i)dp[i][j][k]=max(dp[i-1][j][k]+a[pos][0],dp[i][j][k]);
					if(j)dp[i][j][k]=max(dp[i][j-1][k]+a[pos][1],dp[i][j][k]);
					if(k)dp[i][j][k]=max(dp[i][j][k-1]+a[pos][2],dp[i][j][k]);
					if(pos==n)ans=max(dp[i][j][k],ans);
				}
			}
		}
		cout<<ans<<'\n';
	}
}
