#include<bits/stdc++.h>
using namespace std;
int t,n,dp[310][310][310],a[100010][5],b[100010],ans,tt;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=tt=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]+a[i][3]==0)tt++;
		}
		if(tt==n){
			for(int i=1;i<=n;i++){
				b[i]=a[i][1];
			}
			sort(b+1,b+n+1);
			for(int i=n;i>n/2;i--){
				ans+=b[i];
			}
			cout<<ans<<endl;
			continue;
		}
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=n/2;k++){
					if(i+j+k>n){
						break;
					}
					dp[i][j][k]=0;
					if(i>0){
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i+j+k][1]);
					}if(j>0){
						dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+a[i+j+k][2]);
					}if(k>0){
						dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]+a[i+j+k][3]);
					}
				}
			}
		}
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				ans=max(ans,dp[i][j][n-i-j]);
			}
		}
		cout<<ans<<endl;
	} 
	return 0;
} 
