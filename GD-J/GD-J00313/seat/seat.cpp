#include <bits/stdc++.h>
using namespace std;
using i32 = int32_t;

// --------------------------------------------------------------------------------------------

i32 n, m, a[1005], ltc;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (i32 i = 1; i <= n * m; ++i) {
		cin >> a[i];
		if (a[i] >= a[1])
			++ltc;
	}
	i32 c = (ltc + n - 1) / n, k1 = ltc - (c - 1) * n, r = 0;
	if (c & 1)
		r = k1;
	else
		r = n - k1 + 1;
	cout << c << ' ' << r << endl;
	fflush(stdout);
	return 0;
}

/*

For international readers: goto line 38.

发现自己的座位只和排名有关，与 a 值无关。所以先把排名求出来。设排名为 k，则有列数为 c\coloneqq\lceil\frac kn\rceil。在列内他的排名为 k'\coloneqq k-(c-1)n。

当 c 为奇数时，他的行号为 k'，否则为 n-k'+1。直接输出即可。O(nm)。爆标了（划 

Seat depends on rank, but not the value of a. So find the rank first, let it be k. The seat is on the c\coloneqq\lceil\frac kn\rceil -th column. Inside the column the rank will be k'\coloneqq k-(c-1)n.

When c is odd, the row number is k', otherwise n-k'+1. Output it straightly. O(nm). ~~faster than std~~

*/
