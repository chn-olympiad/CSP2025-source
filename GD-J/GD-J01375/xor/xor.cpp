#include <bits/stdc++.h>
using namespace std;
//#define int long long
const int N = 5e5 + 5;
int n, a[N], dp[N], k, sum[N];
map<int, vector<int> > m;
signed main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		sum[i] = sum[i - 1] ^ a[i];
	}
	if (a[1] == k) dp[1] = 1;
	for (int i = 2; i <= n; i++){
		dp[i] = dp[i - 1];
		int t = k ^ sum[i];
		if (!m[t].empty()) dp[i] = max(dp[i], dp[m[t][m[t].size() - 1]] + 1);
		m[sum[i]].push_back(i);
	}
	printf("%d", dp[n]);
	return 0;
}
