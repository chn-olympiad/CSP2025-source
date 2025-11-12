#include <bits/stdc++.h>
//#define int long long

const int N = 5e5 + 7;

std::map<int, int> mp;

int f[N], lst[N], a[N], s[N];
int n, k, ans;

template<typename T> void ckmax(T &x, T y) { x = x > y ? x : y; }
template<typename T> void ckmin(T &x, T y) { x = x < y ? x : y; }

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	scanf("%d%d", &n, &k); for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i ++) s[i] = s[i - 1] ^ a[i];
	for (int i = 1; i <= n; i ++) lst[i] = -1;
	mp[0] = 0;
	for (int i = 1; i <= n; i ++) {
		if (mp.find(s[i] ^ k) != mp.end()) lst[i] = mp[s[i] ^ k];
		mp[s[i]] = i;
	}
	for (int i = 1; i <= n; i ++) {
		f[i] = f[i - 1];
		if (~lst[i]) ckmax(f[i], f[lst[i]] + 1);
	}
	printf("%d", f[n]);
	
	return 0;
}
