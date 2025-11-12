#include<bits/stdc++.h>
using namespace std;
const int maxn=4e4+5;
int n,t,a[maxn][3],dp[maxn>>1][maxn>>1];
long long ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0;
		memset(dp,0,sizeof(dp));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		}
		for(int z=1;z<=n;z++){
			for(int i=min(z,n>>1);i>=0;i--){
				for(int j=min(z-i,n>>1);j>=0;j--){
					if((z-i-j)>(n>>1))	continue;
					int x=dp[i][j];
					if(i>0&&j>0){
						dp[i][j]=max(dp[i-1][j]+a[z][0],dp[i][j-1]+a[z][1]);
					}else if(i>0){
						dp[i][j]=dp[i-1][j]+a[z][0];
					}else if(j>0){
						dp[i][j]=dp[i][j-1]+a[z][1];
					}
					dp[i][j]=max(dp[i][j],x+a[z][2]);
					ans=max(ans,(long long)dp[i][j]);
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
