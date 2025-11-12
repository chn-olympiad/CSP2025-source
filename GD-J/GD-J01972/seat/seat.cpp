#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define mems(x, v) memset((x), (v), sizeof (x))
#define mcpy(x, y) memcpy((x), (y), sizeof (x))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long double wisdom;

pii a[114514];
int main() {
	freopen("seat.in", "r", stdin); freopen("seat.out", "w", stdout);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n * m; i++) cin >> a[i].first, a[i].second = i;
	sort(a + 1, a + n * m + 1, greater <pii>());
	int p = -1; for (int i = 1; i <= n * m; i++) if (a[i].second == 1) {p = i; break;}
	int x = 1, y = 1;
	for (int i = 1; i < p; i++) {
		if (x & 1) {if (y < n) y++; else y = n, x++;}
		else {if (y > 1) y--; else y = 1, x++;}
	}
	cout << x << ' ' << y << '\n';
	return 0;
}
