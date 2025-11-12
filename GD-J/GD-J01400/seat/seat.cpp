#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 105;
int n, m, idx, a[N];

signed main() {
	freopen("seat.in", "r", stdin); freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> a[++idx];
    int val = a[1], id = 0;
    sort(a + 1, a + idx + 1, greater <int>());
    for (int i = 1; i <= idx; i++) if (a[i] == val) { id = i; break; }
    int x = (id - 1) / n + 1;
    if (x & 1) cout << x << ' ' << (id % n == 0 ? n : id % n);
    else cout << x << ' ' << n - ((id % n) == 0 ? n : id % n) + 1;
	return 0;
}