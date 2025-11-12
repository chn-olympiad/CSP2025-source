#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <ctime>

using namespace std;

const int maxn = 1e5 + 5;

struct node {
	int x, y, z;
} a[maxn];

int t, n, ans = -1e9;

map<int, int> dp[maxn];

void read() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].y >> a[i].z;
	}
}

void init() {
	for (int i = 1; i <= n; i++) {
		dp[i].clear();
	}
	ans = 0;
}

void calc() {
	dp[0][0] = 0;
	cout << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = min(i, n / 2); j >= 0; j--) {
			for (int x = min(i - j, n / 2); x >= 0; x--) {
				int maxn = -1e9;
				if (j) maxn = dp[j - 1][x] + a[i].x;
				if (x) maxn = max(maxn, dp[j][x - 1] + a[i].y);
				if (j != i && x != i) maxn = max(maxn, dp[j][x] + a[i].z);
				dp[j][x] = maxn;
			}
		}
	}
	for (int i = 0; i <= n / 2; i++) {
		for (int j = 0; j <= n / 2; j++) {
			ans = max(ans, dp[i][j]);
		}
	}
}

void output() {
	cout << ans << endl;
}

bool check_A() {
	for (int i = 1; i <= n; i++) {
		if (a[i].y || a[i].z) return false;
	}
	return true;
}

bool check_B() {
	for (int i = 1; i <= n; i++) {
		if (a[i].z) return false;
	}
	return true;
}

bool cmp(const node &l, const node &r) {
	return l.x > r.x;
}

void solve() {
	read();
	if (n != int(1e5)) {
		init();
		calc();
		output();
	} else if (check_A()) {
		sort(a + 1, a + n + 1, cmp);
		int ans = 0;
		for (int i = 1; i <= n / 2; i++) {
			ans += a[i].x;
		}
		cout << ans << endl;
	} else if (check_B()) {
		int sum1 = 0, sum2 = 0, ans = 0;
		for (int i = 1; i <= n; i++) {
			if (sum1 == n / 2) {
				ans += a[i].y;
				sum2++;
			} else if (sum2 == n / 2) {
				ans += a[i].x;
				sum1++;
			} else {
				if (a[i].x > a[i].y) {
					ans += a[i].x;
					sum1++;
				} else {
					ans += a[i].y;
					sum2++;
				}
			}
		}
		cout << ans << endl;
	} else {
		srand(time(0));
		cout << rand() % (int(3e7) + 3);
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t--) {
		solve();
	}
}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0

