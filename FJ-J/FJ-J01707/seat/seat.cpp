#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define int long long
using namespace std;
const int N = 105;
int n, m;
pii a[N];
#define getx(x) ((x - 1) % n + 1)
#define gety(x) ((x + n - 1) / n)

bool cmp (pii a, pii b) {
	return a.fi > b.fi;
}

void solve () {
	cin >> n >> m;
	for (int i = 1; i <= n * m; i ++) {
		cin >> a[i].fi; a[i].se = i;
	}
	sort (a + 1, a + 1 + n * m, cmp);
	for (int i = 1; i <= n * m; i ++) {
		if (a[i].se == 1) {
			if (gety(i) & 1); else {
				cout << gety(i) << " " << n - getx(i) + 1; return ;
			}
			cout << gety(i) << " " << getx(i);
			return ;
		}
	}
}

signed main () {  // t2 red ??????!!!!!!? respect n, m <= 10 ; AC t2! 8:56
//	freopen ("seat3.in", "r", stdin);
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	ios :: sync_with_stdio (false), cin.tie (0), cout.tie (0);
	solve ();

	return 0;
}

