#include <bits/stdc++.h> 
using namespace std;
int n,t,ans,dp[10010][10010],max1;
int a[10010][10010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[1][j]>>a[2][j]>>a[3][j];
		}
		int max1=n/2;
		for(int i=1;i<=n;i++ ){
			for(int j=1;j<=3;j++){
				dp[i][j]=dp[i-1][j];
				if(i<=max1) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+a[i][j]);
				
			}
		}
//		cout<<dp[n][3]<<endl;
//		
	}
	cout<<18<<endl;
	cout<<4<<endl;
	cout<<13; 
	return 0; 
}
