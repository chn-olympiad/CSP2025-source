//GZ-S00376 肖家诺 安顺市第一高级中学 
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int n , t , act=0 , ans=0 , a[100009][3] , dp[400][400][400];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0;
		scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++){
			scanf("%d",&a[i][j]);
		}
	}
	memset(dp,0,sizeof(dp));
	a[0][1]=a[0][2]=a[0][0]=0;
	for(int i=0;i<=n/2;i++)
		{
			for(int j=0;j<=n/2;j++)
			{
				for(int k=0;k<=n/2;k++)
				{
					act=i+j+k;
					if(act>n)break;
					if(i) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[act][0]);
					if(j) dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+a[act][1]);
					if(k) dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]+a[act][2]);
					ans=max(ans,dp[i][j][k]);
				}
			}
		 } 
	printf("%d\n",ans);	
	}
	return 0;
	
}
