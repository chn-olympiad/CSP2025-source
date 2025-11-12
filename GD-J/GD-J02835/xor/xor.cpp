#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, k;
int a[N];
signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		a[i] ^= a[i - 1];
	map<int, int> ds;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ds[a[i - 1]] = i;
		if (ds.find(a[i] ^ k) != ds.end()) {
			ds.clear();
			ans++;
		}
	}
	cout << ans;
}