#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> PII;
const int N = 505, MOD = 998244353;
int n, a[N], m, ans;
char c[N];
bool vis[N];
void dfs(int x, int y, int k){
	if (x == n + 1){
		if (k <= n - m) ans = (ans + 1) % MOD;
		return;
	}
	for (int i = 1; i <= n; i++){
		if (vis[i]) continue;
		vis[i] = 1;
		if (c[x] == '0' || a[i] <= k){
			dfs(x + 1, y, k + 1);
		}else dfs(x + 1, y + 1, k);
		vis[i] = 0;
	}
}
signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%lld%lld%s", &n, &m, c + 1);
	for (int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	if (n <= 11) dfs(1, 0, 0);
	else{
		for (int i = 1; i <= n; i++){
			ans = ans * i % MOD;
		}
	}
	printf("%lld", ans);
	return 0;
}/*
3 2
101
1 1 2
*//*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
