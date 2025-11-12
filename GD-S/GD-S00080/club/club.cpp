#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n;
int dp[2][110][110][110]; 
struct node{
	int a,b,c;
}s[510];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		memset(dp,0,sizeof dp);
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
		dp[0][1][0][0]=s[1].a;
		dp[0][0][1][0]=s[1].b;
		dp[0][0][0][1]=s[1].c;
		for(int i=2;i<=n;i++){
			for(int j=0;j<=i&&j<=n/2;j++){
				for(int k=0;k<=i-j&&k<=n/2;k++){
					for(int l=0;l<=i-j-k&&l<=n/2;l++){
						if(j) dp[(i-1)%2][j][k][l]=max(dp[(i-1)%2][j][k][l],dp[i%2][j-1][k][l]+s[i].a);
						if(k) dp[(i-1)%2][j][k][l]=max(dp[(i-1)%2][j][k][l],dp[i%2][j][k-1][l]+s[i].b);
						if(l) dp[(i-1)%2][j][k][l]=max(dp[(i-1)%2][j][k][l],dp[i%2][j][k][l-1]+s[i].c);
					}
				}
			}
		}
		int ans=0;
		for(int i=0;i<=n/2;i++)
			for(int j=0;j<=n/2;j++)
				ans=max(ans,dp[(n-1)%2][i][j][n-i-j]);
		printf("%d\n",ans);
	}
	return 0;
}
