#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N = 110ll;
ll m, n, a[N], id, sfls[N][N];  // SFLS, HSC

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (ll i = 1;i <= n * m;++i) cin >> a[i];
	id = a[1];
	sort(a + 1, a + n * m + 1, greater<int>());
	ll i = 1, j = 1, idx = 1, cng = 1;  // i column, j  row
	while(idx <= n * m) {
		sfls[i][j] = a[idx];
		if (a[idx] == id) {
			cout << i << ' ' << j;
			return 0;
		}
		++idx;
		j += cng;
		if (j > n || j < 1) {
			if (i % 2) ++i, j = n, cng = -1;
			else ++i, j = 1, cng = 1;
		}
	}
	return 0;
}

/*
Sort again?
Wait, n, m <= 10
So hai think ge ji mao, simulate is OK(Whose maths problem?)
Why does T1 & T2 == abc A again?
Everybody is different, so I just need to record the score to know who little R is
09:10, AC All 3 test cases
*/
