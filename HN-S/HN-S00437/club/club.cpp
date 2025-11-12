#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200+10;
int t,n,a[N][4],dp[N][N][N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;++i){
			for(int j=0;j<=n;++j){
				for(int k=0;k<=n;++k){
					dp[i][j][k]=0;
				}
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=3;++j){
				cin>>a[i][j];
			}
		}
		dp[1][1][0]=a[1][1];
		dp[1][0][1]=a[1][2];
		dp[1][0][0]=a[1][3];
		for(int i=2;i<=n;++i){
			for(int j=0;j<=n/2;++j){//1
				for(int k=0;k<=n/2;++k){//2
					if(j+k>i) continue;
					if(j) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][1]);
					if(k) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][2]);
					if(i-j-k>0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i][3]);
				}
			}
		}
		int ans=0;
		for(int j=0;j<=n/2;++j){
			for(int k=0;k<=n/2;++k){
				if(n-j-k<=n/2)ans=max(ans,dp[n][j][k]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

