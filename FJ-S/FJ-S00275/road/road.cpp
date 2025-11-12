#include <bits/stdc++.h>
using namespace std;
int dp[10020][10010];
int n,m,k,x,y,q1;
long long sum,sum1,sum2;
int zx(int qqqq){
	int minn=2000000000;
	for(int i=1;i<=n;i++){
		if(dp[i][qqqq]<minn&&dp[i][qqqq]!=0){
			minn=dp[i][qqqq];
		}
	}
	return minn;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		scanf("%d %d %d",&x,&y,&q1);
		dp[x][y]=q1;
		dp[y][x]=q1;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&q1);
		dp[0][n+i]=q1;
		for(int j=1;j<=n;j++){
			scanf("%d",&q1);
			dp[n+i][j]=q1;
		}
	}
	for(int i=1;i<=n;i++){
		dp[0][i]=zx(i);
		sum+=dp[0][i];
	}
	for(int i=1;i<=k;i++){
		sum2=dp[0][n+i];
		for(int j=1;j<=n;j++){
			//dp[n+i][j]=min(dp[0][i],dp[n+i][j]);
			sum2+=min(dp[0][j],dp[n+i][j]);
			//cout<<sum2<<" ";
		}
		sum1=sum2;
		if(sum1<sum){
			sum=sum1;
		}
		if(i!=1){
		sum2=dp[0][n+i]+dp[0][n+i-1];
		for(int j=1;j<=n;j++){
			//dp[n+i][j]=min(dp[n+i-1][i],dp[n+i][j]);
			sum2+=min(dp[n+i-1][i],dp[n+i][j]);
		}
		if(sum2<sum){
			sum=sum2;
			for(int j=1;j<=n;j++) dp[n+i][j]=min(dp[n+i-1][j],dp[n+i][j]);
			dp[0][n+i]=dp[0][n+i]+dp[0][n+i-1];
		}
		else{
			for(int j=1;j<=n;j++) dp[n+i][j]=min(dp[0][j],dp[n+i][j]);
		}
		if(sum1>sum&&sum2>sum){
			for(int j=1;j<=n;j++) dp[n+i][j]=dp[n+i-1][j];
			dp[0][n+i]=dp[0][n+i-1];
		}
		}
		else{
			for(int j=1;j<=n;j++) dp[n+i][j]=min(dp[0][j],dp[n+i][j]);
			if(sum1>sum&&sum2>sum){
			for(int j=1;j<=n;j++) dp[n+i][j]=dp[0][j];
			dp[0][n+i]=dp[0][n+i-1];
		}
		}
		
	}
	/*
	for(int i=0;i<=6;i++){
		cout<<endl;
		for(int j=0;j<=6;j++){
		cout<<dp[i][j]<<" ";
	}
	}
	*/
	cout<<sum;
	return 0;
}