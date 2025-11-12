#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 111;

int n, m;
int a[N];
signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int score, dy;
	cin >> n >> m;
	int i, h, l;
	for (i = 1; i <= n * m; ++i) cin >> a[i];
	score = a[1];
	sort(a + 1, a + 1 + n * m, greater<int>());
	i = dy = h = l = 1;
	while (a[i++] != score) {
        h += dy;
        if (h > n) ++l, dy = -1, h = n;
        else if (h < 1) ++l, h = 1, dy = 1;
	}
	printf("%lld %lld\n", l, h);
	return 0;
}
