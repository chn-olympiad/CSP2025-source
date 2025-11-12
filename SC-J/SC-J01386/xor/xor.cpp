#include <bits/stdc++.h> 
#define ll long long 

using namespace std; 

const int N = 5e5 + 5; 
const int M = 3e6 + 5; 

int n, k; 
int a[N]; 
int pre[N]; 
int dp[N], f[M], ans; 

signed main() {
	freopen("xor.in", "r", stdin); 
	freopen("xor.out", "w", stdout); 
	
	scanf("%d%d", &n, &k); 
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i); 
		pre[i] = pre[i - 1] ^ a[i]; 
	}
	
	memset(f, -1, sizeof f); 
	
	f[0] = 0; 
	for (int i = 1; i <= n; i++) {
		dp[i] = f[k ^ pre[i]] + 1; 
		ans = max(ans, dp[i]); 
		f[pre[i]] = max(f[pre[i]], ans); 
	}
	
	printf("%d", ans); 
	
	return 0; 
} 