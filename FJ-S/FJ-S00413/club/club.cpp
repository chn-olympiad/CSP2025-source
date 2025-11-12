#include<bits/stdc++.h>
using namespace std;

int t,n;

int a[100010][5];
int dp[100010][5];

int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i = 1;i <= n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dp[1][1] = a[1][1];
		dp[1][2] = a[1][2];
		dp[1][3] = a[1][3];
		for(int i = 2;i <= n / 2;i++){
			dp[i][1] = max(dp[i - 1][1],max(dp[i - 1][2],dp[i - 1][3])) + a[i][1];
			dp[i][2] = max(dp[i - 1][1],max(dp[i - 1][2],dp[i - 1][3])) + a[i][2];
			dp[i][3] = max(dp[i - 1][1],max(dp[i - 1][2],dp[i - 1][3])) + a[i][3];
		}
		for(int i = n / 2 + 1;i <= n;i++){
			dp[i][1] = max(dp[i - 1][2],dp[i - 1][3]) + a[i][1];
			dp[i][2] = max(dp[i - 1][1],dp[i - 1][3]) + a[i][2];
			dp[i][3] = max(dp[i - 1][1],dp[i - 1][2]) + a[i][3];
		}
		cout<<max(dp[n][1],max(dp[n][2],dp[n][3]))<<endl;
	}
	return 0;
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
