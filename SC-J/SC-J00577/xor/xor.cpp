#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, k, a[N], s[N], f[N];
map <int, int> mp;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		s[i] = s[i - 1] ^ a[i];
	}
	mp[0] = 0;
	for (int i = 1; i <= n; ++i) {
		f[i] = f[i - 1];
		if (mp.count(k ^ s[i]))
			f[i] = max(f[i], mp[k ^ s[i]] + 1);
		mp[s[i]] = max(mp[s[i]], f[i]);
	}
	printf("%d\n", f[n]);
	fclose(stdin), fclose(stdout);
	return 0;
}