#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,dp[501][501][501],a[1000005],b[1000005],c[1000005],ans;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int flag=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=n/2;k++){
					if(i+j+k>n)break;
					if((i==0&&j==0)||(i==0&&k==0)||(j==0&&k==0)){
						if(i!=0)dp[i][j][k]=dp[i-1][j][k]+a[i];
						else if(j!=0)dp[i][j][k]=dp[i][j-1][k]+b[j];
						else dp[i][j][k]=dp[i][j][k-1]+c[k];
					}
					else if(i==0||j==0||k==0){
						if(i==0)dp[i][j][k]=max(dp[i][j-1][k]+b[i+j+k],dp[i][j][k-1]+c[i+j+k]);
						else if(j==0)dp[i][j][k]=max(dp[i-1][j][k]+a[i+j+k],dp[i][j][k-1]+c[i+j+k]);
						else dp[i][j][k]=max(dp[i][j-1][k]+b[i+j+k],dp[i-1][j][k]+a[i+j+k]);
					}
					else dp[i][j][k]=max(max(dp[i-1][j][k]+a[i+j+k],dp[i][j-1][k]+b[i+j+k]),dp[i][j][k-1]+c[i+j+k]);
//					cout<<dp[i][j][k]<<" "<<i<<" "<<j<<" "<<k<<endl;
					ans=max(ans,dp[i][j][k]);
				}
			} 
		}
		cout<<ans<<endl;
		ans=0;
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=n/2;k++){
					dp[i][j][k]=0;
				}
			}
		}
	}	
	return 0;
} 
