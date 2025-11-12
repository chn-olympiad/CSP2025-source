#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

int n, m, R;
struct node {
	int s, xb;
} a[100005];

bool cmp(node x, node y) {
	return x.s > y.s;
}

struct edge {
	int x, y;
} ans[100005];

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i].s;
		a[i].xb = i;
	} 
	sort(a + 1, a + n * m + 1, cmp);
	
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (i & 1) {
				ans[(i - 1) * n + j].x = i;
				ans[(i - 1) * n + j].y = j;
			}
			else {
				ans[(i - 1) * n + j].x = i;
				ans[(i - 1) * n + j].y = n - j + 1;
			}
		}
	}
	
	for (int i = 1; i <= n * m; i++) {
		if (a[i].xb == 1) {
			R = i;
			break;
		}
	}
	cout << ans[R].x << ' ' << ans[R].y << endl;
	return 0;
} 
