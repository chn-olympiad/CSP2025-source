#include<bits/stdc++.h>
using namespace std;
int n,a[210][4],dp[210][105][4],g[210][105],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		ans=0;
		memset(dp,0,sizeof(dp));
		memset(g,0,sizeof(g));
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for(int i = 1;i <= n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			g[i][1] = g[i][2] = g[i][3] = i;
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= 3;j++){
				for(int w = 1;w <= n/2;w++){
					if(i != 1){
						for(int k = 1;k <= 3;k++){
							if(k != j) dp[i][j][w] = max(dp[i-1][k][w],dp[i][j][w]);
						}
						if(w>g[i-1][j]){
							if(dp[i-1][j][w-g[i-1][j]]>dp[i][j][w]){
								dp[i][j][w] = dp[i-1][j][w-g[i-1][j]];
								g[i][j] = g[i-1][j]+1;
							}
						}
					}
					dp[i][j][w] += a[i][j];
					ans = max(dp[i][j][w],ans);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
