#include<bits/stdc++.h>
using namespace std;
long long t,n,n1[100005],n2[100005],n3[100005],ans,dp[100005][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>n1[i]>>n2[i]>>n3[i];
		}
		int s1=0,s2=0,s3=0;
		for(int i=1;i<=n;i++){
			if(s1<n/2){
				dp[i][1]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+n1[i];
				
			}else dp[i][1]=max(dp[i-1][2],dp[i-1][3])+n1[i];
			if(s2<n/2){
				dp[i][2]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+n2[i];
				
			}else dp[i][2]=max(dp[i-1][3],dp[i-1][1])+n2[i];
			if(s3<n/2){
				dp[i][3]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+n3[i];
			}else	dp[i][3]=max(dp[i-1][2],dp[i-1][1])+n3[i];
			if(dp[i][3]>dp[i][2]&&dp[i][3]>dp[i][1]) s3++;
			if(dp[i][2]>dp[i][1]&&dp[i][2]>dp[i][3]) s2++;
			if(dp[i][1]>dp[i][2]&&dp[i][1]>dp[i][3]) s1++;
		}
		cout<<max(dp[n][1],max(dp[n][2],dp[n][3]));
		
	}
	
	return 0;
}
