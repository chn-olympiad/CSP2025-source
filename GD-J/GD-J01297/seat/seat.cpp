#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define ULL unsigned long long
#define LLL __int128
#define Pii pair<int, int>
#define fst first
#define snd second
#define pb push_back
#define endl '\n'

namespace gdb7
{
	int a[110];
	signed main(void) {
		freopen("seat.in", "r", stdin);
		freopen("seat.out", "w", stdout);
		int n, m, pos = 0;
		cin >> n >> m;
		cin >> a[1];
		for (int i = 2; i <= n * m; ++i) {
			cin >> a[i];
			if (a[i] > a[1]) {
				++pos;
			}
		}
		int lie = 2 * (pos / (2 * n)) + 1, hang, t1 = pos % (2 * n);
		if (t1 >= n) {
			++lie;
			t1 -= n;
			hang = n - t1;
		} else {
			hang = t1 + 1;
		}
		cout << lie << " " << hang << endl;
		return 0;
	}
}

signed main(void)
{
	return gdb7::main();
}

