#include<bits/stdc++.h>
using namespace std;
long long a[100005][3],dp[100005][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--){
		long long n;cin>>n;
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		for(int i=1;i<=n;i++){
			for(int j=n;j>=1;j--){
				if(j<=n/2){
					dp[j][0]=max(dp[j-1][0],max(dp[j-1][1],dp[j-1][2]))+a[i][0];
					dp[j][1]=max(dp[j-1][0],max(dp[j-1][1],dp[j-1][2]))+a[i][1];
					dp[j][2]=max(dp[j-1][0],max(dp[j-1][1],dp[j-1][2]))+a[i][2];
				}
				else{
					dp[j][0]=max(dp[(n-1)/2][0],max(dp[j-1][1],dp[j-1][2]))+a[i][0];
					dp[j][1]=max(dp[j-1][0],max(dp[(n-1)/2][1],dp[j-1][2]))+a[i][1];
					dp[j][2]=max(dp[j-1][0],max(dp[j-1][1],dp[(n-1)/2][2]))+a[i][2];
				}
			}
		}
		printf("%d\n",max(dp[n][0],max(dp[n][1],dp[n][2])));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 