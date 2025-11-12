#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int inf=INT_MAX;
int t,n,ans;
int a[N][3],dp[N][3];
void _init(){
	memset(a,0,sizeof(a));
	memset(dp,0,sizeof(dp));
	ans=0; mx=0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		_init();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++){
				scanf("%d",&a[i][j]);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++){
				dp[i][j]=-inf;
				for(int k=0;k<3;k++){
					dp[i][j]=max(dp[i-1][k]+a[i][k],dp[i][j]);
				}
			}
		}
		for(int i=0;i<3;i++)
			ans=max(ans,dp[n][i]);
		printf("%lld\n",ans);
	}
	return 0;
}
