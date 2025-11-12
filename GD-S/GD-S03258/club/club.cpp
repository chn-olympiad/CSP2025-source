#include<bits/stdc++.h>
using namespace std;

int t;
int dp[100050][5]={};
int a[100050][5]={};
int n;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		} 
		for(int i=1;i<=3;i++){
			dp[n][i]=a[n][i];
		}
		int f[100]={};
		for(int i=n-1;i>=1;i--){
			for(int j=1;j<=3;j++){
				int tmp=4;
				for(int k=1;k<=3;k++){
					if(dp[i][j]<dp[i+1][k]+a[i][j]){
						if(k==j){
							if(f[k]+1<n/2){
								dp[i][j]=dp[i+1][k]+a[i][j];
								tmp=k;
							}
						}else{
							if(f[k]<=n/2){
								dp[i][j]=dp[i+1][k]+a[i][j];
								tmp=k;
							}
						}
					}
				}				
				f[tmp]++;
			}
		}
		int ans=INT_MIN;
		for(int i=1;i<=3;i++){
			ans=max(ans,dp[1][i]);
		}
		cout<<ans<<endl; 
	}
	
	return 0;
} 
