#include<bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 5;
long long a[N], k, n, f[N], ans = 0, vis[N];
bool fun(int x, int y) {
	for(int i = x; i <= y; i ++) {
		if(vis[i]) {
			return false;
		}
	}
	return true;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%lld%lld", &n, &k);
	for(int i = 1; i <= n; i ++) {
		scanf("%lld", &a[i]);
	}
	f[1] = a[1];
	for(int i = 2; i <= n; i ++) {
		f[i] = f[i - 1] ^ a[i];
	}
	for(int i = 0; i <= n - 1; i ++) {
		for(int j = 1; j + i <= n; j ++) {
			int x = (j == 1 ? f[j + i] : f[j + i] ^ f[j - 1]);
			if(x == k) {
				if(fun(j, j + i)) {
					ans ++;
					vis[j] = 1;
					vis[j + i] = 1;
				}
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
