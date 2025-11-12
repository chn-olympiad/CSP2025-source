#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5, M = 2e4 + 10;

int n, half_n, ans;

int f[M];

struct node {
	int x, y, z;
};
node a[N];

bool cmp_A(node a, node b) { return a.x > b.x; }

bool cmp_BX(node a, node b) {
	if (a.x == b.x) return a.y > b.y;
	return a.x > b.x;
}

bool cmp_BY(node a, node b) {
	if (a.y == b.y) return a.x > b.x;
	return a.y > b.y;
}

void dfs(int k, int x, int y, int z, int tot) {

	if (k == n + 1) {
		ans = max(ans, tot);
		return;
	}

	if (x + 1 <= half_n) dfs(k + 1, x + 1, y, z, tot + a[k].x);

	if (y + 1 <= half_n) dfs(k + 1, x, y + 1, z, tot + a[k].y);

	if (z + 1 <= half_n) dfs(k + 1, x, y, z + 1, tot + a[k].z);

}

void solve() {
	dfs(1, 0, 0, 0, 0);

	cout << ans << '\n';
}

int main () {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T; cin >> T;
	while (T --) {
		memset(a, 0, sizeof(a));
		memset(f, 0xcf, sizeof(f));

		cin >> n;
		half_n = n / 2;

		bool flag_A = true, flag_B = true;
		for (int i = 1; i <= n; i ++) {
			int d, e, f; cin >> d >> e >> f;
			a[i] = {d, e, f};

			if (e != 0 || f != 0) flag_A = false;
			if (f != 0) flag_B = false;
		}
		
		if (n <= 30) {
			ans = 0;
			solve();
			continue;
		}
		
		if (flag_A == true) {
			sort(a + 1, a + n + 1, cmp_A);
			
			int tot = 0;
			for (int i = 1; i <= half_n; i ++) {
				tot += a[i].x;
			}
			
			cout << tot << '\n';
			continue;
		}
		else if (flag_B == true) {
			sort(a + 1, a + n + 1, cmp_BX);
			int tot = 0;
			int cnt1 = 0;
			
			vector<int> tmp;
			for (int i = 1; i <= n; i ++) {
				if (a[i].x >= a[i].y && cnt1 < half_n) {
					tot += a[i].x;
					cnt1 ++;
				}
				else if (a[i].y > a[i].x) {
					tmp.push_back(a[i].y);
				}
			}
			
			sort(tmp.begin(), tmp.end());
			
			int cnt_y = 0;
			for (auto t : tmp) {
				if (cnt_y < half_n) {
					tot += t;
					cnt_y ++;
				}
				else break;
			}
			
			int tot2 = 0;
			int cnt2 = 0;

			tmp.clear();
			for (int i = 1; i <= n; i ++) {
				if (a[i].y >= a[i].x && cnt2 < half_n) {
					tot2 += a[i].y;
					cnt2 ++;
				}
				else if (a[i].x > a[i].y) {
					tmp.push_back(a[i].x);
				}
			}

			sort(tmp.begin(), tmp.end());

			int cnt_x = 0;
			for (auto t : tmp) {
				if (cnt_x < half_n) {
					tot2 += t;
					cnt_x ++;
				}
				else break;
			}
			
			ans = 0;
			ans = max(tot, tot2);
			
			cout << ans << '\n';
			
			continue;
		}
	}


	return 0;
}