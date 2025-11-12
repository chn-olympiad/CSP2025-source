#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	int n, k;cin >> n >> k;
	vector<int> A(n + 1);
	for(int i = 1;i <= n; i++) cin >> A[i];
	vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));// 选前i个数
	dp[0][0] = 0;
	for(int i = n;i >= 1; i--){
		for(int j = i;j <= n; j++){
			if(i == j) dp[i][j] = (A[i] == k ? 1 : 0);
			else if(j - i == 1) dp[i][j] = max((A[i] ^ A[j] == k ? 1 : 0), (A[i] == k ? 1 : 0) + (A[j] == k ? 1 : 0));
			else dp[i][j] = max(dp[i][j - 1] + (A[j] == k ? 1 : 0), dp[i][j - 2] + dp[j - 1][j]);
		}
	}
	
	cout << dp[1][n];
	return 0;
}
/*




*/