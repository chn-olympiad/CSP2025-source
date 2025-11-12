#include<cstdio>
#include<iostream>
using namespace std;
int dp[500005][3],lt[500005][3];
int n,k;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	int tx,ty;
	for(int i=1;i<=n;i=i+1)scanf("%d",&a[i]);
	dp[0][0]=0;
	dp[0][1]=0;
	dp[0][2]=-1;
	lt[0][1]=-1;
	lt[0][2]=-1;
	for(int i=1;i<=n;i=i+1){
		dp[i][0]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
		dp[i][1]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
		lt[i][1]=a[i];
		if(a[i]==k)dp[i][1]=dp[i][1]+1;
		if((lt[i-1][1]!=k)&&(lt[i-1][2]!=k)){
			dp[i][2]=max(dp[i-1][1],dp[i-1][2]);
			int tx=lt[i-1][1]^a[i];
			int ty=lt[i-1][2]^a[i];
			if(dp[i-1][1]>dp[i-1][2])lt[i][2]=tx;
			else if(dp[i-1][1]<dp[i-1][2])lt[i][2]=ty;
			else if(tx==k)lt[i][2]=tx;
			else lt[i][2]=ty;
		//other-dp
		}
		if(lt[i][2]==k)dp[i][2]=dp[i][2]+1;
		//printf("i=%d,a[i]=%d,now=%d,new=%d,aft=%d,lt1=%d,lt2=%d.\n",i,a[i],dp[i][0],dp[i][1],dp[i][2],lt[i][1],lt[i][2]);
	//do-all-dp
	}
	printf("%d\n",max(dp[n][0],max(dp[n][1],dp[n][2])));
	return 0;
//end-T3
//check-11:13-maybe-30
}
