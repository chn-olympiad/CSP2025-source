#include <bits/stdc++.h>
using namespace std;
const int M = 998244353;
int n, a[5010];
long long ans;
void dfs(int x, int s, int ma, int v){
	if(x == n + 1){
		if(v >= 3 && s > 2 * ma) ans++;
		return;
	}
	dfs(x + 1, s + a[x], a[x], v + 1);
	dfs(x + 1, s, ma, v);
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	dfs(1, 0, 0, 0);
	ans %= M;
	printf("%lld", ans);
	return 0;
}
