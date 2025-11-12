#include <bits/stdc++.h> 
const int N = 1e5 + 5;

int n, a[N], b[N], c[N], ans;
std::priority_queue<int> q[4];
 
void run()
{
	scanf("%d", &n); ans = 0;
	for (int i = 1; i <= 3; ++i)
		while (!q[i].empty()) q[i].pop();
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d%d", a + i, b + i, c + i);
		if (a[i] >= b[i] && a[i] >= c[i]) {
			ans += a[i];
			q[1].push(std::max(b[i], c[i]) - a[i]); 
			if (q[1].size() > n >> 1) { ans += q[1].top(); q[1].pop(); }
		} else if (b[i] >= a[i] && b[i] >= c[i]) {
			ans += b[i];
			q[2].push(std::max(a[i], c[i]) - b[i]);
			if (q[2].size() > n >> 1) { ans += q[2].top(); q[2].pop(); }
		} else {
			ans += c[i];
			q[3].push(std::max(a[i], b[i]) - c[i]);
			if (q[3].size() > n >> 1) { ans += q[3].top(); q[3].pop(); }	
		}
	} printf("%d\n", ans);
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T; scanf("%d", &T);
	while (T--) run();
	return 0;
}
