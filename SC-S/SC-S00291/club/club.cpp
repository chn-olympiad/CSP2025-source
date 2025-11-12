#include<bits/stdc++.h>
using namespace std;
int mp[100005][3];
int n=200;
int dp[205][105][105][105];
inline void solve(){
	cin>>n;
	memset(dp,0,sizeof(dp)); 
	for(int i=1;i<=n;i++){
		cin>>mp[i][1]>>mp[i][2]>>mp[i][3];
	}
	for(int a=0;a<=n/2;a++){
		for(int b=0;b<=n/2;b++){
			for(int c=0;c<=n-a-b&&c<=n/2;c++){
				if(a!=0){
					dp[a+b+c][a][b][c]=max(dp[a+b+c][a][b][c],dp[a+b+c-1][a-1][b][c]+mp[a+b+c][0]);
				}
				if(b!=0){
					dp[a+b+c][a][b][c]=max(dp[a+b+c][a][b][c],dp[a+b+c-1][a][b-1][c]+mp[a+b+c][1]);
				}
				if(c!=0){
					dp[a+b+c][a][b][c]=max(dp[a+b+c][a][b][c],dp[a+b+c-1][a][b][c-1]+mp[a+b+c][2]);
				}
			}	
		}
	}
	int ans=0;
	for(int a=0;a<=n/2;a++){
		for(int b=0;b<=n/2;b++){
			for(int c=0;c<=n-a-b&&c<=n/2;c++){
				if(ans<dp[n][a][b][c]){
					ans=dp[n][a][b][c];
				}
			}
		}
	}
//	cout<<maxa<<" "<<maxb<<" "<<maxc<<"\n";
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();	
	}
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/