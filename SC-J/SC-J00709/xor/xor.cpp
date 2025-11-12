#include <iostream>
using namespace std;
const int MAXN = 500010;
int n, k , a[MAXN], pre[MAXN], ans;
bool vis[MAXN];
inline void init() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pre[i] = a[i] ^ pre[i - 1];
	}
}
inline int Xor(int l, int r) {
	return pre[r] ^ pre[l - 1]; 
}
void dfs(int x, int sigma_xor, bool prev, int res) {
	if (vis[x] == true && sigma_xor == k) {
		res++;
	}
	ans = max(ans, res);
	for (int i = x + 1; i <= n; i++) {
		vis[i] = true;
		if (sigma_xor == k) {
			dfs(i, a[i], true, res);
		}
		else dfs(i, sigma_xor ^ a[i], false, res);
		vis[i] = false;
		if (prev == true) dfs(i, 0, true, res);
		
	}
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	init();
	dfs(0, 0, true, 0);
	cout << ans;
	return 0;
}  