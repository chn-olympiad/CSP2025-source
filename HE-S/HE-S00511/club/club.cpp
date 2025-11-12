//club
#include<bits/stdc++.h>
using namespace std;
long long errrrr;
struct node{
		long long ff, ss, tt;
};
node a[100010];
int main() {

	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	
	cin >> errrrr;
	for (int i = 1; i <= errrrr ; i++) {
		int n, ans = 0,dp[5][100010];
	//long long a[100010];
	cin >> n;
	dp[1][0] = 0;
	dp[2][0] = 0;
	dp[3][0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].ff >> a[i].ss >> a[i].tt; 
	}
	for (int i = 1; i <= n; i ++) {
		dp[1][i] = max(dp[1][i - 1], max(dp[2][i - 1], dp[3][i - 1])) + a[i].ff;
		dp[2][i] = max(dp[1][i - 1], max(dp[2][i - 1], dp[3][i - 1])) + a[i].ss;
		dp[3][i] = max(dp[1][i - 1], max(dp[2][i - 1], dp[3][i - 1])) + a[i].tt;
	//cout<<max(dp[1][i], max(dp[2][i], dp[3][i])) << endl; 
	}
	int i = n + 1;
	dp[1][i] = max(dp[1][i - 1], max(dp[2][i - 1], dp[3][i - 1]));
	cout << dp[1][i] << endl;

	}
		return 0;
}
