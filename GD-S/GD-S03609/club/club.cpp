#include<cstdio>
#include<iostream>
#include<cstring>
#define ll long long
using namespace std;
ll t,n,a[100005][5],dp[205][205][205],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		memset(dp,0,sizeof(dp));
		ans=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				for(int l=0;l<=n/2;l++){
					if(l+j+i>n)break;
					if(i)dp[i][j][l]=max(dp[i][j][l],dp[i-1][j][l]+a[i+j+l][1]);
					if(j)dp[i][j][l]=max(dp[i][j][l],dp[i][j-1][l]+a[i+j+l][2]);
					if(l)dp[i][j][l]=max(dp[i][j][l],dp[i][j][l-1]+a[i+j+l][3]); 
					ans=max(ans,dp[i][j][l]);
				}
			}
		}
		
		printf("%lld\n",ans);
	}
	return 0;
}
