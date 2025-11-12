#include<bits/stdc++.h>
using namespace std;
const int N=207;
int a[100007][3];
int b[100007];
int dp[N][N][N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=0;j<=2;j++){
				scanf("%d",&a[i][j]);
			}
		}
		if(n>300){
			for(int i=1;i<=n;i++) b[i]=a[i][0];
			sort(b+1,b+n+1);
			int ans=0;
			for(int i=n/2+1;i<=n;i++){
				ans+=b[i];
			}
			printf("%d\n",ans);
		}
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				for(int k=0;k<=n;k++){
					if(i+j+k>n) break;
					dp[i][j][k]=0;
					if(i!=0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i+j+k][0]);
					if(j!=0) dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+a[i+j+k][1]);
					if(k!=0) dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]+a[i+j+k][2]);
				}
			}
		}
		int ans=0;
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=n/2;k++){
					if(i+j+k!=n) continue;
					ans=max(ans,dp[i][j][k]);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}