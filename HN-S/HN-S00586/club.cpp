#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

void FileIO (string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 1e5 + 10;

struct Member {
	int x, y, z;
} a[N];

int T, n, stk[3][N], top[3], ans, b[N], m, c[N];

void Solve () {
	cin >> n, top[0] = top[1] = top[2] = ans = m = 0;
	for (int i = 1; i <= n; i++) {
	  cin >> a[i].x >> a[i].y >> a[i].z, ans += max({a[i].x, a[i].y, a[i].z});
		if (a[i].x >= a[i].y && a[i].x >= a[i].z) stk[0][++top[0]] = i, c[i] = max(a[i].y, a[i].z) - a[i].x;
		else if (a[i].y >= a[i].z) stk[1][++top[1]] = i, c[i] = max(a[i].x, a[i].z) - a[i].y;
		else stk[2][++top[2]] = i, c[i] = max(a[i].y, a[i].x) - a[i].z;
	}
	int id = -1;
	if (top[0] > n / 2) id = 0;
	if (top[1] > n / 2) id = 1;
	if (top[2] > n / 2) id = 2;
	if (id != -1) {
		for (int i = 1; i <= top[id]; i++) b[++m] = c[stk[id][i]];
		sort(b + 1, b + m + 1);
		for (int i = m; i > n / 2; i--) ans += b[i];
	}
	cout << ans;
}

int main () {
	ios::sync_with_stdio(0), cin.tie(0);
	FileIO("club");
	for (cin >> T; T--; Solve(), cout << '\n') {}
	return 0;
}
