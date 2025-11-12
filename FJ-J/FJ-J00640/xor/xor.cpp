#include <bits/stdc++.h>
using namespace std;

int n, k, a[500005], q[500005], dp[500005], t[2000005];

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) q[i] = q[i - 1] ^ a[i];
	for(int i = 1; i <= n; i++){
		dp[i] = dp[i - 1];
		if(q[i] == k || t[q[i] ^ k]) dp[i] = max(dp[i], dp[t[q[i] ^ k]] + 1); 
	    t[q[i]] = i;
	}
    cout << dp[n] << "\n"; 
	return 0;
} 
