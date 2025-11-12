/* CSP 2025 RP++
T2
25 Min Yu ji 100 */
#include <bits/stdc++.h>
using namespace std;
int n, m, a[250], tmp;
int main() {
	freopen("seat.in", "r", stdin), freopen("seat.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n * m; ++i) scanf("%d", a + i);
    tmp = a[1], sort(a + 1, a + n * m + 1, greater<int>());
    int c = 1, r = 1;
    for (int i = 1; i <= n * m; ++i) {
    	if (a[i] == tmp) return cout << c << ' ' << r << endl, 0;
    //	cout << c << ' ' << r << endl;
		if (c % 2 == 1 && r != n) ++r;
		else if (c % 2 == 0 && r != 1) --r;
		else ++c;
	}cout << c << ' ' << r << endl;
	return 0;
}

