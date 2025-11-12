#include<bits/stdc++.h>
#define LL long long

using namespace std;

const int maxn = 1e5 + 10;

int n;

int a[maxn][3];

priority_queue<int, vector<int>, greater<int> > rev[3];

int cnt[3];

int sum = 0;

void clear() {
	for (int i = 0; i < 3; i++) {
		cnt[i] = 0;
	}
	sum = 0;
}

void solve() {
	clear();
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
//		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}
	
	for (int i = 1; i <= n; i++) {
		int x = a[i][0], y = a[i][1], z = a[i][2];
		if (x >= y && x >= z) {
			int dy = x - y;
			int dz = x - z;
			int dd = min(dy, dz);
			if (cnt[0] == n / 2) {
				int mn_pop = rev[0].top();
				if (dd < mn_pop) { // put aside
					sum += x - dd;
				} else {
					sum += x - mn_pop;
					rev[0].pop();
					rev[0].push(dd);
				}
			} else {
				sum += x;
				rev[0].push(dd);
				cnt[0]++;
			}
		} else if (y >= x && y >= z) {
			int dx = y - x;
			int dz = y - z;
			int dd = min(dx, dz);
			if (cnt[1] == n / 2) {
				int mn_pop = rev[1].top();
				if (dd < mn_pop) { // put aside
					sum += y - dd;
				} else {
					sum += y - mn_pop;
					rev[1].pop();
					rev[1].push(dd);
				}
			} else {
				sum += y;
				rev[1].push(dd);
				cnt[1]++;
			}
		} else if (z >= x && z >= y) {
			int dx = z - x;
			int dy = z - y;
			int dd = min(dx, dy);
			if (cnt[2] == n / 2) {
				int mn_pop = rev[2].top();
				if (dd < mn_pop) { // put aside
					sum += z - dd;
				} else {
					sum += z - mn_pop;
					rev[2].pop();
					rev[2].push(dd);
				}
			} else {
				sum += z;
				rev[2].push(dd);
				cnt[2]++;
			}
		}
	}
	
	cout << sum << endl;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int T;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
