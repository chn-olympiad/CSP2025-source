#include<bits/stdc++.h>

const int N = 500105;
int A[N], S[N], need[N], dp[N];
const int T = 2000005;
int lst[T];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++)
		scanf("%d", A + i), S[i] = S[i - 1] ^ A[i], need[i] = k ^ S[i];
	memset(lst, -1, sizeof(lst));
	lst[0] = 0;
	for(int i = 1; i <= n; i++) {
		if(~lst[need[i]])
			dp[i] = dp[lst[need[i]]] + 1;
		dp[i] = std::max(dp[i], dp[i - 1]);
		lst[S[i]] = i;
	}
	printf("%d\n", dp[n]);
	return 0;
}

