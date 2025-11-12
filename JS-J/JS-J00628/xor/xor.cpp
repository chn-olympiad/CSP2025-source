#include <bits/stdc++.h>
using namespace std;
int n, k, a[500010], dp[500010], mx[500010], S[500010], lst[500010], cur[2000010];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	memset(lst, -1, sizeof(lst));
	memset(cur, -1, sizeof(cur));
	cur[0] = 0;
	for (int i=1; i<=n; i++){
		cin >> a[i];
		S[i] = S[i-1] ^ a[i];
		if (cur[S[i]^k] != -1)
			lst[i] = cur[S[i]^k];
		cur[S[i]] = i;
	}
	for (int i=1; i<=n; i++){
		dp[i] = dp[i-1];
		if (lst[i] != -1)
			dp[i] = max(dp[i], mx[lst[i]]+1);
		mx[i] = max(mx[i-1], dp[i]);
	}
	cout << dp[n];
}