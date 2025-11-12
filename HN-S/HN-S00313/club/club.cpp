#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long dp[N][5],a[N][5],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.in","r",stdin);
	int t;cin>>t;
	while(t--){
		ans=0;
		memset(dp,0,sizeof(dp));
		int n;cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				dp[i][j]=max(dp[i-1][j],a[i][j]);
			}
		}
		for(int i=n/2+1;i<=n;i++){
			ans+=max(max(dp[i][1],dp[i][2]),dp[i][3])+max(min(dp[i][1],dp[i][2]),min(dp[i][2],dp[i][3]));
		}cout<<ans<<'\n';
	}
	
	return 0;
} 
