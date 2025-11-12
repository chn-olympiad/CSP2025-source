#include <bits/stdc++.h>
using namespace std;
int t, n;
struct Node {
	int val, id;
}a[4], b[4];
int c[100010];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> t;
	while (t--) {
		int ans = 0;
		cin >> n;
		if (n == 2) {
			for (int i = 1; i <= 3; i++) {
				cin >> a[i].val;
				a[i].id = i;
			}
			for (int i = 1; i <= 3; i++) {
				cin >> b[i].val;
				b[i].id = i;
			}
			int aans[10];
			aans[1] = a[1].val + b[2].val;
			aans[2] = a[1].val + b[3].val;
			aans[3] = a[2].val + b[1].val;
			aans[4] = a[2].val + b[3].val;
			aans[5] = a[3].val + b[1].val;
			aans[6] = a[3].val + b[2].val;
			for (int i = 1; i <= 6; i++)
				ans = max(ans, aans[i]);
			cout << ans << endl;
		} else {
			int garbages;
			for (int i = 1; i <= n; i++) {
				cin >> garbages >> c[i] >> garbages;
			}
			sort(c + 1, c + 1 + n, cmp);
			for (int i = 1; i <= n / 2; i++) {
				ans += c[i];
			}
			cout << ans << endl;
		}
	}
	return 0;
}

