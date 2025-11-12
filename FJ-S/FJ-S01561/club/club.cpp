#include<bits/stdc++.h>
using namespace std;
const int N=210;
int T,n,ans,a[N][4];
int dfs(int k,int f,int b,int c){
	if(k>n) return 0;
	if(k==0) return max(dfs(1,1,0,0),max(dfs(1,0,1,0),dfs(1,0,0,1)));
	int temp=0;
	if(f<n/2) temp=max(dfs(k+1,f+1,b,c)+a[k][1],temp);
	if(b<n/2) temp=max(dfs(k+1,f,b+1,c)+a[k][2],temp);
	if(c<n/2) temp=max(dfs(k+1,f,b,c+1)+a[k][3],temp);
	return temp;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		if(n>=100000) {
			int s[100010],sum=0;
			for(int i=1; i<=n; i++) scanf("%d",&s[i]);
			sort(s+1,s+1+n);
			for(int i=n; i>=n/2+1; i--) {
				sum+=s[i];
			}
			cout<<sum<<"\n";
		}
		else if(n<=100){
			for(int i=1; i<=n; i++) scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			cout<<dfs(0,0,0,0)<<"\n";
		} 
		else {
			int dp[N][4][N>>1]={};
			for(int i=1; i<=n; i++) scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			for(int i=1; i<=n; i++) {
				for(int j=1; j<=min(n/2,i); j++) {
					dp[i][1][j]=max(dp[i-1][1][j-1]+a[i][1],dp[i-1][1][j]);
					dp[i][2][j]=max(dp[i-1][2][j-1]+a[i][2],dp[i-1][2][j]);
					dp[i][3][j]=max(dp[i-1][3][j-1]+a[i][3],dp[i-1][3][j]);
					for(int k=1; k<=min(n/2,j); k++) {
						dp[i][1][j]=max(dp[i][1][j],max(dp[i-1][2][k],dp[i-1][3][k]));
						dp[i][2][j]=max(dp[i][2][j],max(dp[i-1][1][k],dp[i-1][3][k]));
						dp[i][3][j]=max(dp[i][3][j],max(dp[i-1][1][k],dp[i-1][2][k]));
					}

				}
			}
			ans=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n/2;j++){
					printf("%d %d %d",dp[i][1][j],dp[i][2][j],dp[i][3][j]);
					printf("\n");
				}
				printf("\n");
			}
			printf("\n");
			for(int i=1; i<=n/2; i++) ans=max(dp[n][1][i],max(dp[n][2][i],dp[n][3][i]));
			printf("%d\n",ans);
		}
	}
	return 0;
}
