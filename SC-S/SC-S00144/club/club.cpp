#include<iostream>
#include<cstring>
using namespace std;
const int N=100;
int a[N],b[N],c[N],v[N],dp[N][N][N][N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
		}
		memset(dp,0,sizeof dp);
		for(int i=1;i<=n;i++){
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=n/2;k++){
					for(int l=0;l<=n/2;l++){
//					printf("%d%d%d%d:%d ",i,j,k,l,dp[i][j][k][l]);
						if(l-1>=0)dp[i][j][k][l]=max(dp[i][j][k][l],dp[i-1][j][k][l-1]+c[i]);
//					printf("%d ",dp[i][j][k][l]);
						if(k-1>=0)dp[i][j][k][l]=max(dp[i][j][k][l],dp[i-1][j][k-1][l]+b[i]);
//					printf("%d ",dp[i][j][k][l]);
						if(j-1>=0)dp[i][j][k][l]=max(dp[i][j][k][l],dp[i-1][j-1][k][l]+a[i]);
						else if(l-1<0&&k-1<0&&j-1<0)dp[i][j][k][l]=dp[i-1][j][k][l];
//					printf("%d\n",dp[i][j][k][l]);
					}
				}
			}
		}
		printf("%d\n",dp[n][n/2][n/2][n/2]);
	}
	
	return 0;
}