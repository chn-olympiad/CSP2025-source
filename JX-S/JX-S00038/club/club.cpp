#include<bits/stdc++.h>
using namespace std;
long long a[100050][3],dp[100050][3],sum[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	long long t,n;
	cin>>t;
	while(t--){
		cin>>n;
		dp[0][0]=0;
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			
		}
		sum[1]=0;
		sum[2]=0;
		sum[3]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
			
				dp[i][j]=max(dp[i-1][1]+a[i][j],max(dp[i-1][2]+a[i][j],
							dp[i-1][3]+a[i][j]));
				
				if(dp[i-1][1]==max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))){
					sum[1]++;
				}else if(dp[i-1][2]==max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))){
					sum[2]++;
			    }else{
					sum[3]++;
				}
		    }
		}	
		long long ans=max(dp[n][1],max(dp[n][2],dp[n][3]));
		cout<<ans<<endl;
	}
	return 0;
}
