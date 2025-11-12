#include <bits/stdc++.h>

long long n, k, pos, ans = 0;
std::map < long long, std::priority_queue < long long > > vis;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	scanf("%lld%lld", &n, &k);
	std::vector < long long > a (n + 5, 0);
	std::vector < long long > sum (n + 5, 0);
	
	vis[sum[0] xor k].push(0);
	for (long long i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		sum[i] = sum[i - 1] xor a[i];
		vis[sum[i] xor k].push(i);
	}
	
	for (long long i = n; i >= 1; i--) {
		while (!vis[sum[i]].empty() && vis[sum[i]].top() >= i) {
			vis[sum[i]].pop();
		}
		if (!vis[sum[i]].empty()) {
			if (vis[sum[i]].top() < i) {
				ans++; 
				i = vis[sum[i]].top() + 1;
			}
		}
	}
	printf("%lld", ans);
	return 0;
} 