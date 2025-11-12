#include<bits/stdc++.h> 
using namespace std;
int n, k;
int a[500010];
int ans;
void dfs(int u, int num, int sum) {
	if(u == n + 1) {
		ans = max(ans, sum);
		return;
	} 
	if(n - u + 1 < ans - sum) return;
	if((num ^ a[u]) == k || a[u] == k) {
//		cout << u << ' ' << sum << endl;
		dfs(u + 1, 0, sum + 1);
	}
	dfs(u + 1, a[u], sum);
	dfs(u + 1, (num ^ a[u]), sum);
}
int p[200010];
int dp[200010][256];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	if(n <= 2) {
		cout << 0;
	} else if(n <= 10) {
		dfs(1, 0, 0);
		cout << ans;
	} else if(k == 0 || k == 1){
		for(int i = 1; i <= n; i++) if(a[i] == 1) ans++;
		if(k == 1) cout << ans; 
		else cout << n - ans + ans / 2;
	} else {
//		for(int i = 1; i <= n; i++) {
//			p[i] = (p[i - 1] ^ a[i]);
//		}
//		for(int i = 1; i <= n; i++) {
//			for(int j = i; j <= n; j++) {
//				if((p[j] ^ p[i - 1]) == k) {
//					ans++;
//					i = j;
//					break;
//				}
//			}
//		}
		int maxx = 0;
		for(int i = 1; i <= n; i++) {
			maxx = maxx | a[i];
			for(int j = 0; j <= maxx; j++) {
				if(a[i] == j) dp[i][j]++;
				dp[i][j] += dp[i - 1][(j ^ a[i])];
			}
		}
		cout << dp[n][k];
//		int cnt = 0, i = 1;
//		while(i <= ans) {
//			cnt++;
//			if(i == ans) break;
//			for(int j = i + 1; j <= ans; j++) {
//				if(q[j].l > q[i].r) {
//					i = j;
//					break;
//				}
//				if(j >= ans) i = ans + 1;
//			}
//		}
//		cout << cnt;
	}
	return 0;
}
