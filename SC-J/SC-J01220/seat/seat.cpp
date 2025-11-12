#include <bits/stdc++.h>
#define E(i, l, r) for(int i = l;i <= r;++ i)
using ll = long long;
using namespace std;
using P = pair<int, int>;
int tt;
namespace wangcy {
	const int N = 1005;
	int a[N], rk[N][N];
	int n, m, cx, cy, dx, dy;
	inline void Main() {
		cin >> n >> m, cx = cy = 1;
		E(i, 1, n*m) cin >> a[i];
		E(i, 1, n*m) {
			if(cx == 1){
				if(cy & 1) dx = 1, dy = 0;
				else dy = 1, dx = 0;
			} else if (cx == n){
				if(cy & 1) dy = 1, dx = 0;
				else dx = -1, dy = 0;
			}
			rk[cx][cy] = i;
			cx += dx, cy += dy;
		}
		int k = a[1];
		stable_sort(a + 1, a + n*m + 1);
		int p = lower_bound(a + 1, a + n*m + 1, k) - a;
		p = n * m - p + 1;
		E(i, 1, n) E(j, 1, m) {
			if(p == rk[i][j]) {
				cout << j << " " << i << "\n";
				break;
			}
		}
		return void();
	}
}
int main() {
	freopen("seat.in", "r", stdin), freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	tt = 1;
	while(tt --) wangcy::Main();
	return 0;
}
// Ex : 100pts