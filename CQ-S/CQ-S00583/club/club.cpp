#include<bits/stdc++.h>
using namespace std;
int a[120000][4],dp[202][102][102],cqbz[120000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n/2;j++){
				for(int z=0;z<=n/2;z++){
					dp[i][j][z]=-2e6;
				}
			}
		}
		dp[0][0][0]=0;
		int tp=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			if(a[i][2]!=0||a[i][3]!=0){
				tp=1;
			}
		}
		if(tp==0){
			for(int i=1;i<=n;i++){
				cqbz[i]=a[i][1];
			}
			sort(cqbz+1,cqbz+1+n);
			int ans=0;
			for(int i=n;i>n/2;i--){
				ans+=cqbz[i];
			}
			cout<<ans<<endl;
		}
		else{
			for(int i=1;i<=n;i++){
				for(int j=0;j<=n/2;j++){
					for(int z=0;z<=n/2;z++){
						int k=i-j-z;
						if(j!=0)dp[i][j][z]=max(dp[i][j][z],dp[i-1][j-1][z]+a[i][1]);
						if(z!=0)dp[i][j][z]=max(dp[i][j][z],dp[i-1][j][z-1]+a[i][2]);
						if(k!=0&&k<=n/2)dp[i][j][z]=max(dp[i][j][z],dp[i-1][j][z]+a[i][3]);
					}
				}
			}
			int ans=0;
			for(int j=0;j<=n/2;j++){
				for(int z=0;z<=n/2;z++){
					ans=max(ans,dp[n][j][z]);
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
//T1 20min~1.7h T2 20min~2h T3 0.3h+ T4 0h+  
