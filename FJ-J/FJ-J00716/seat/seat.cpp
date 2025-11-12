#include <bits/stdc++.h>
#define Write ios::sync_with_stdio(0);
#define by cin.tie(0);
#define Na1L0n9 cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int N = 1e2 + 10;
const int MOD = 998244353;
int n, m, r, dx, dy = 1, x = 1, y = 1, s[N];
bool cmp (int x, int y) {
	return x > y;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	Write by Na1L0n9
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> s[i];
	}
	r = s[1];
	sort(s + 1, s + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (s[i] == r) {
			cout << x << " " << y;
			break;
		}
		if (dx) {
			x++;
			dx = 0;
		}
		else {
			y += dy;
			if (y == n || y == 1) {
				dx = 1, dy = -dy;
			}
		}
		//cout << x << " " << y << "\n";
	}
	return 0;
}
// WoW，我做出T2了，这是真的吗，我的csp-j居然能拿到200分的高分，ccf对我太好了 
