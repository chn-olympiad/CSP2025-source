#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000010;
int dp[maxn], id[maxn];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k, x, sum = 0, ans = 0;
	cin >> n >> k;
	memset(id, -1, sizeof(id));
	id[0] = 0;
	for(int i = 1;i <= n;i++){
		cin >> x;
		sum ^= x;
		if(id[k ^ sum] != -1) dp[i] = dp[id[k ^ sum]] + 1;
		dp[i] = max(dp[i], dp[i - 1]);
		id[sum] = i;
		// ans = max(ans, dp[i]);
	}
	cout << dp[n];
	return 0;
}