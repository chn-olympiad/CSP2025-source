#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 1 << 21;
int n, k, a[N], s[N];
bool vis[M];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) s[i] = s[i - 1] ^ a[i];
	int l = 0, base = 0, ans = 0;
	vis[0] = true;
	for (int r = 1; r <= n; ++r) {
		if (vis[(s[r] ^ base) ^ k]) {
			++ans;
			//cout << r << ' ';
			for (int i = l; i < r; ++i)
				vis[s[i] ^ base] = false;
			base = s[r];
			l = r;
		}
		vis[s[r] ^ base] = true;
	}
	cout << ans;
	return 0;
}
/*
g++ xor.cpp -o xor -std=c++14 -O2 -static
*/