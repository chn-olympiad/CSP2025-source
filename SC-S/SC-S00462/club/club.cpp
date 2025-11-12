#include <bits/stdc++.h>
using namespace std;
int a[100010][3],dp[210][210][210];
int n,res=0,ans=0;
void solve(){
	memset(dp,0,sizeof dp);
	cin>>n;
	for(int i = 1;i <= n;i++){
		for(int j = 0;j <= 2;j++){
			cin>>a[i][j];
		}
	}
	for(int i = 1;i <= n;i++){
		for(int _0 = n/2;_0 >= 1;_0--){
			for(int _1 = n/2;_1 >= 1;_1--){
				for(int _2 = n/2;_2 >= 1;_2--){
					dp[_0][_1][_2] = max(
						max(dp[_0][_1][_2],dp[_0-1][_1][_2]+a[i][0])
						,max(dp[_0][_1-1][_2]+a[i][1],
							dp[_0][_1][_2-1]+a[i][2]));
				}
			}
		}
	}
	cout<<dp[n/2][n/2][n/2]<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//int st=clock();
	int T;
	cin>>T;
	while(T--) solve();
	//clog<<"time:"<<fixed<<setprecision(2)<<1.0*(clock()-st)/CLOCKS_PER_SEC;
	return 0;
}