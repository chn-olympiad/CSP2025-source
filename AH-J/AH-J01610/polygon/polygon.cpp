#include<bits/stdc++.h>
using namespace std;
const int Mod = 998244353;
int n, a[5005], vis[5005], maxn = INT_MIN, ans = 0;
void dfs(int sum, int re, int maxnn, int last) {
	if(!re) {
		if(sum > maxnn * 2) {
			ans ++;
			ans %= Mod;
		}
		return ;
	}
	for(int i = last; i <= n; i ++) {
		if(!vis[i]) {
			vis[i] = 1;
			dfs(sum + a[i], re - 1, max(maxnn, a[i]), i);
			vis[i] = 0;
		}
	}
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		maxn = max(maxn, a[i]);
	}
	if(maxn == 1) {
		long long sum = 0;
		for(int i = 3; i <= n; i ++) {
			int s = 1, x = 1;
			for(int j = n; j >= n - i + 1; j --) {
				s *= j;
			}
			for(int j = 1; j <= i; j ++) {
				x *= j;
			}
			sum += s / x;
			sum %= Mod;
		}
		printf("%lld\n", sum % Mod);
		return 0;
	}
	for(int i = 3; i <= n; i ++) {
		dfs(0, i, 0, 1);
	}
	printf("%d\n", ans % Mod);
	return 0;
}
