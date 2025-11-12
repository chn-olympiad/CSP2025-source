#include<bits/stdc++.h>
using namespace std;
int dp[105][105][105],t,n;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(dp,0,sizeof dp);
		cin>>n;
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			for(int a=n/2;a>=0;a--){
				for(int b=n/2;b>=0;b--){
					for(int c=n/2;c>=0;c--){
						if(a>0)dp[a][b][c]=max(dp[a][b][c],dp[a-1][b][c]+x);
						if(b>0)dp[a][b][c]=max(dp[a][b][c],dp[a][b-1][c]+y);
						if(c>0)dp[a][b][c]=max(dp[a][b][c],dp[a][b][c-1]+z);
					}
				}
			}
		}cout<<dp[n/2][n/2][n/2]<<"\n";
	}
	return 0;
} 
