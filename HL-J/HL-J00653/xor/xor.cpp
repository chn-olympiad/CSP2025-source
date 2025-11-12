#include<cstdio>
#include<iostream>
using namespace std;
int a[500001];
int dp[1001][256][256][2];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(k==0){
		printf("%d\n",n>>1);
	}else if(k==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=a[i];
		}
		printf("%d\n",ans);
	}else{
		for(int i=1;i<=n;i++){
			for(int j=0;j<=255;j++){
				for(int k=0;k<=255;k++){
					if(a[i]==k){
						dp[i][j][k][0]=max(max(dp[i-1][j][j][0]+1,dp[i-1][j][0][1]),dp[i-1][j][k][0]);
						dp[i][j][k][1]=max(dp[i-1][j][j][0]+1,dp[i-1][j][0][1]);
					}else{
						dp[i][j][k][0]=max(dp[i-1][j][a[i]^k][1],dp[i-1][j][k][0]);
						dp[i][j][k][1]=dp[i-1][j][a[i]^k][1];
					}
				}
			}
		}
		printf("%d\n",dp[n][k][k][0]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
