#include <bits/stdc++.h>
using namespace std;

int t, n, ans[200010];

struct member {
	int b1, b2, b3;
} a[100010];

bool cmp1(const member &a, const member &b) {
	return a.b1 > b.b1;
}

bool cmp2(const member &a, const member &b) {
	return a.b2 > b.b2;
}

bool cmp3(const member &a, const member &b) {
	return a.b3 > b.b3;
}

bool cmp(const int &a, const int &b) {
	return a > b;
}

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d%d", &a[i].b1, &a[i].b2, &a[i].b3);
	
	if (n == 2) {
		int ans = 0;
		ans = max(ans, a[1].b1 + a[2].b2);
		ans = max(ans, a[1].b1 + a[2].b3);
		ans = max(ans, a[1].b2 + a[2].b1);
		ans = max(ans, a[1].b2 + a[2].b3);
		ans = max(ans, a[1].b3 + a[2].b1);
		ans = max(ans, a[1].b3 + a[2].b2);
		printf("%d\n", ans);
		return;
	}
	
	int l = 0;
	sort(a + 1, a + n + 1, cmp1);
	for (int i = 1; i <= n / 2; i++) 
		ans[++l] = a[i].b1;
		
	sort(a + 1, a + n + 1, cmp2);
	for (int i = 1; i <= n / 2; i++)
		ans[++l] = a[i].b2;
	
	sort(a + 1, a + n + 1, cmp3);
	for (int i = 1; i <= n / 2; i++)	
		ans[++l] = a[i].b3;
	sort(ans + 1, ans + l + 1, cmp);
	
	int sum = 0;
	for (int i = 1; i <= n; i++)
		sum += ans[i];
	
	printf("%d\n", sum);	
}

int main() {
//	freopen("club.in", "r", stdin);
//	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	for ( ; t--; ) 
		solve();
	return 0;
}
