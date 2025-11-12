#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int t,n,dp[N/2][4];
struct{
	int a,b,c;
}a[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		memset(dp,0,sizeof dp);
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			for(int j=n/2;j>=1;j--){
				dp[j][1]=max(dp[j][1],dp[j-1][1]+a[i].a);
				dp[j][2]=max(dp[j][2],dp[j-1][2]+a[i].b);
				dp[j][3]=max(dp[j][3],dp[j-1][3]+a[i].c);
			}
		}
		int ans=0;
		for(int i=1;i<=n/2;i++){
			for(int j=1;j<=n/2;j++){
				int k=n-i-j;
				ans=max(ans,dp[i][1]+dp[j][2]+dp[k][3]);
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
