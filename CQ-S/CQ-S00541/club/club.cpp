#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int MAXN = 1e5 + 5;
int n, la, lb, lc;
struct Node {
	int x, y, z;
}ls[MAXN];

struct P {
	int x, pos;
}a[5][MAXN];

bool cmp1(P x, P y) {
	return x.x - max(ls[x.pos].y, ls[x.pos].z) > y.x - max(ls[y.pos].y, ls[y.pos].z);
}

bool cmp2(P x, P y) {
	return x.x - max(ls[x.pos].x, ls[x.pos].z) > y.x - max(ls[y.pos].x, ls[y.pos].z);
}

bool cmp3(P x, P y) {
	return x.x - max(ls[x.pos].x, ls[x.pos].y) > y.x - max(ls[y.pos].x, ls[y.pos].y);
}

void solve() {
	la = lb = lc = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> ls[i].x >> ls[i].y >> ls[i].z;
		if (ls[i].x == max(ls[i].x, max(ls[i].y, ls[i].z))) {
			a[1][++la].x = ls[i].x;
			a[1][la].pos = i;
		} else if (ls[i].y == max(ls[i].x, max(ls[i].y, ls[i].z))) {
			a[2][++lb].x = ls[i].y;
			a[2][lb].pos = i;
		} else {
			a[3][++lc].x = ls[i].z;
			a[3][lc].pos = i;
		}
	}
	int ans = 0;
	// a[1]
	if (la > n / 2) {
		sort(a[1] + 1, a[1] + 1 + la, cmp1);
		for (int i = 1; i <= n / 2; i++) {
			ans += a[1][i].x;
		}
		for (int i = n / 2 + 1; i <= la; i++) {
			ans += max(ls[a[1][i].pos].y, ls[a[1][i].pos].z);
		}
	} else {
		for (int i = 1; i <= la; i++) {
			ans += a[1][i].x;
		}
	}
	if (lb > n / 2) {
		sort(a[2] + 1, a[2] + 1 + lb, cmp2);
		for (int i = 1; i <= n / 2; i++) {
			ans += a[2][i].x;
		}
		for (int i = n / 2 + 1; i <= lb; i++) {
			ans += max(ls[a[2][i].pos].x, ls[a[2][i].pos].z);
		}
	} else {
		for (int i = 1; i <= lb; i++) {
			ans += a[2][i].x;
		}
	}
	if (lc > n / 2) {
		sort(a[3] + 1, a[3] + 1 + lc, cmp3);
		for (int i = 1; i <= n / 2; i++) {
			ans += a[3][i].x;
		}
		for (int i = n / 2 + 1; i <= lc; i++) {
			ans += max(ls[a[3][i].pos].x, ls[a[3][i].pos].y);
		}
	} else {
		for (int i = 1; i <= lc; i++) {
			ans += a[3][i].x;
		}
	}
	cout << ans << '\n';
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T; while (T--) solve();
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
