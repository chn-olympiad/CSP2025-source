#include <bits/stdc++.h>
#define MAXN 15
using namespace std;

int n, m;
int a[MAXN * MAXN];

bool cmp(int x, int y) {
	return x > y;
}

int find(int num, int l, int r) {
	while (l <= r) {
		if (a[l] == num) return l;
		if (a[r] == num) return r;
		int mid = l + (r - l) / 2;
		if (a[mid] > num) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);	
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	int tot = n * m;
	for (int i = 1; i <= tot; i++) {
		cin >> a[i];
	}
	int num = a[1];
	sort(a + 1, a + 1 + tot, cmp);
	int x = find(num, 1, tot);
	int ans_x = 0, ans_y = 0;
	ans_x = (x - 1) / n + 1;
	if (ans_x % 2 == 1) {
		ans_y = (x - 1) % n + 1;
	} else {
		ans_y = m - (x - (ans_x - 1) * n) + 1;
	}
	cout << ans_x << " " << ans_y << endl;
	return 0;
}