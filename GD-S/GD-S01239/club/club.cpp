#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int n, a[N][3], ans;
void dfs(int x, int t1, int t2, int t3, int k){
	if (max(t1, max(t2, t3)) > n / 2) return;
	if (x == n + 1){
		ans = max(ans, k);
		return;
	}
	dfs(x + 1, t1 + 1, t2, t3, k + a[x][0]);
	dfs(x + 1, t1, t2 + 1, t3, k + a[x][1]);
	dfs(x + 1, t1, t2, t3 + 1, k + a[x][2]);
}
int b[N];
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int ttt;
	scanf("%lld", &ttt);
	while (ttt--){
		scanf("%lld", &n);
		for (int i = 1; i <= n; i++){
			scanf("%lld%lld%lld", &a[i][0], &a[i][1], &a[i][2]);
			b[i] = max(a[i][2], max(a[i][1], a[i][0]));
		}
		sort(b + 1, b + 1 + n, greater<int>());
		ans = 0;
		if (n < 15){
			dfs(1, 0, 0, 0, 0);
			printf("%lld\r\n", ans);
		}else{
			for (int i = 1; i <= n / 2; i++){
				ans += b[i];
			}
			printf("%lld\r\n", ans);
		}
	}
	return 0;
}
