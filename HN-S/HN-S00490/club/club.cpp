#include<bits/stdc++.h>
using namespace std;
long long n,s,dp[101000][4],a[101000][4],sum[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;
	cin>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		memset(sum,0,sizeof(sum));
		cin>>n;
		for(int i=1;i<=n;i++) {
	 	cin>>a[i][1]>>a[i][2]>>a[i][3];
	}
	for(int i=1;i<=3;i++) {
		dp[1][i]=a[1][i];
		cout<<a[1][i]<<" ";
	}cout<<"\n"; 
	for(int i=2;i<=n;i++){
		for(int j=1;j<=3;j++){
			if(i>n/2){
				if(j==1){
				dp[i][j]=max(dp[i][j-1],max(dp[i-1][j+1]+a[i][j],dp[i-1][j+2]+a[i][j]));
			}
			else if(j==2){
				dp[i][j]=max(dp[i][j-1],max(dp[i-1][j-1]+a[i][j],dp[i-1][j+1]+a[i][j]));
			}
			else if(j==3){
			dp[i][j]=max(dp[i][j-1],max(dp[i-1][j-1]+a[i][j],dp[i-1][j-2]+a[i][j]));	
			}
		}
			else{
				if(j==1){
				dp[i][j]=max(dp[i][j-1],max(dp[i-1][j]+a[i][j],max(dp[i-1][j+1]+a[i][j],dp[i-1][j+2]+a[i][j])));
			}
			else if(j==2){
				dp[i][j]=max(dp[i][j-1],max(dp[i-1][j]+a[i][j],max(dp[i-1][j-1]+a[i][j],dp[i-1][j+1]+a[i][j])));
			}
			else if(j==3){
			dp[i][j]=max(dp[i][j-1],max(dp[i-1][j]+a[i][j],max(dp[i-1][j-1]+a[i][j],dp[i-1][j-2]+a[i][j])));	
			}
			}
			cout<<dp[i][j]<<" ";
		}cout<<"\n";
	}cout<<max(dp[n][1],max(dp[n][2],dp[n][3]))<<"\n";
}
	return 0;
}
