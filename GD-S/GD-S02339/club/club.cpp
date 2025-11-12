#include<bits/stdc++.h>
using namespace std;
int dp[100005][3],temp[100005][3],a[1000005],b[10000005],c[1000005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--){
		memset(dp,-1,sizeof(dp));
		memset(temp,-1,sizeof(temp));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		dp[0][1]=dp[0][2]=dp[0][3]=0;
		temp[0][1]=temp[0][2]=temp[0][3]=0;
		long long sum=0;
		for(int i=1;i<=n;i++){
			int kk1=-1,kk2=-1,kk3=-1;
			for(int k1=n/2;k1>=1;k1--){
				kk1=max(kk1,max(temp[k1][2],temp[k1][3]));
				kk2=max(kk2,max(temp[k1][1],temp[k1][3]));
				kk3=max(kk3,max(temp[k1][2],temp[k1][1]));
			}	
			dp[n/2][1]=max(dp[n/2][1],kk1+a[i]);
			dp[n/2][2]=max(dp[n/2][2],kk2+b[i]);
			dp[n/2][3]=max(dp[n/2][3],kk3+c[i]);
			for(int j=n/2-1;j>=1;j--){
				dp[j][1]=max(dp[j][1],max(temp[j-1][1],kk1)+a[i]);
				dp[j][2]=max(dp[j][2],max(temp[j-1][2],kk2)+b[i]);
				dp[j][3]=max(dp[j][3],max(temp[j-1][3],kk3)+c[i]);
			}
			for(int j=n/2;j>=1;j--){
				temp[j][1]=dp[j][1];
				temp[j][2]=dp[j][2];
				temp[j][3]=dp[j][3];		
			}
		}
		cout<<max(dp[n/2][1],max(dp[n/2][2],dp[n/2][3])<<endl;
	}
	return 0;
} 
