#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5+6;

int n;
int a[N][3];
int ans;
int cnt[3];

#ifdef AAA
void resolv() {
	int dp[N][3];
	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[0][2] = 0;
	
	for (int i = 0)
}
#endif

void dfs(int i, int k, int sc) {
	if (i == n) {
		ans = max(sc + a[i][k], ans);
		return;
	}
	if (cnt[0] < n / 2)
	{
		cnt[0]++;
		dfs(i + 1, 0, sc + a[i][k]);
		cnt[0]--;
	}
	if (cnt[1] < n / 2)
	{
		cnt[1]++;
		dfs(i + 1, 1, sc + a[i][k]);
		cnt[1]--;
	}
	if (cnt[2] < n / 2)
	{
		cnt[2]++;
		dfs(i + 1, 2, sc + a[i][k]);
		cnt[2]--;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
		
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		ans = 0;
		
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 3; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		
		if (n <= 50) {
		
		cnt[0]++;
		dfs(1, 0, 0);
		cnt[0]--;
		cnt[1]++;
		dfs(1, 1, 0);
		cnt[1]--;
		cnt[2]++;
		dfs(1, 2, 0);
		cnt[2]--;
		
		} else {
			int m[n + 3];
			for (int i = 1; i <= n; i++) {
				m[i] = a[i][0];
			}
			sort(m + 1, m + n + 1, greater<int>());
			for (int i = 0; i <= n / 2; i++) {
				ans += m[i];
			}
		}
		
		printf("%d\n", ans);
		
	}


	return 0;
}

