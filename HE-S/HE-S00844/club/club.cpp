#include<bits/stdc++.h>
using namespace std;
int t,n;
long long dp[101][101][101],ans=0,xxxx,dp1[50010][50010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%ld",&t);
	for(;t>=1;t--){

		scanf("%ld",&n);
		if(n<=200){
			memset(dp,0,sizeof(dp));
			ans=0;
			for(int k=1,a,b,c;k<=n;k++){
				scanf("%d %d %d",&a,&b,&c);
				for(int i=0;i<=n/2&&i<=k;i++){
					for(int j=0;j<=n/2&&(i+j)<=k;j++){
						int l=k-i-j;
						if(l>n/2)continue;
						if(i!=0)dp[i][j][l]=max(dp[i][j][l],dp[i-1][j][l]+a);
						if(j!=0)dp[i][j][l]=max(dp[i][j][l],dp[i][j-1][l]+b);
						if(l!=0)dp[i][j][l]=max(dp[i][j][l],dp[i][j][l-1]+c);
						ans=max(ans,dp[i][j][l]);
						
					}
				}
			}
		}else{
			memset(dp1,0,sizeof(dp1));
			for(int k=1,a,b,c;k<=n;k++){
				scanf("%d %d %d",&a,&b,&c);
				for(int i=1;i<=k&&i<=n/2&&(n-i)<=n/2;i++){
					int j=(n-i);
					if(i!=0)dp1[i][j]=max(dp1[i][j],dp1[i-1][j]+a);
					if(j!=0)dp1[i][j]=max(dp1[i][j],dp1[i][j-1]+b);
					ans=max(ans,dp1[i][j]);
				}	
			}
		}
		cout<<ans<<endl;
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
