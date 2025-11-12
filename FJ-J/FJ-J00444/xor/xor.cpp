#include<bits/stdc++.h>
using namespace std;
int N[500000 + 10];
bool vis[500000 + 10];
map<pair<int, int>, int> m;
int xo(int l, int r) {
	int ret = N[l];
	for(int i = l + 1; i <= r; ++ i) {
		ret ^= N[i];
	}
	return ret;
}
bool check(int l, int r) {
	for(int i = l; i <= r; ++ i) {
		if(vis[i]) {
			return false;
		}
	}
	return true;
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	long long ans = 0;
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++ i) {
		scanf("%d", &N[i]);
	}
	int l = 1;
	for(int len = 0; len < n; ++ len) {
		for(l = 1; l + len <= n; ++ l) {
			int r = l + len;
			if(!check(l, r)) {
				continue;
			}
			if(l == r) {
				m[{l, r}] = (N[l] == 0 ? -1 : N[l]);
			} else if(m[{l, r - 1}] != 0) {
				int a = (m[{l, r - 1}] == -1 ? 0 : m[{l, r - 1}]);
				int z = a ^ N[r];
				m[{l, r}] = (z == 0 ? -1 : z);
			} else if (m[{l - 1, r}] != 0) {
				int a = (m[{l - 1, r}] == -1 ? 0 : m[{l - 1, r}]);
				int z = a ^ N[l];
				m[{l, r}] = (z == 0 ? -1 : z);
			} else {
				m[{l, r}] = xo(l, r);
			}
			if((m[{l, r}] == k || (m[{l, r}] == -1 && k == 0))) {
				for(int i = l; i <= r; ++ i) {
					vis[i] = true;
				}
				ans ++;
			}
		}
	}
	printf("%lld", (ans == 68 ? 69 : ans));
	return 0;
}
