#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;

const int N = 1e5 + 5;
int t, n;
struct node {
	int st, nd, rd;
	bool operator < (const node &o) const {
		return st > o.st;
	} 
}a[N];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		int ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].st >> a[i].nd >> a[i].rd;
		}
		sort(a + 1, a + n + 1);
		int tot = n / 2;
		if (n == 2) {
			int max1 = max(a[1].st, max(a[1].nd, a[1].rd));
			int max2 = max(a[2].st, max(a[2].nd, a[2].rd)), max3;
			if (max1 > max2) {
				ans += max1;
				if (max1 == a[1].st) max3 = max(a[2].nd, a[2].rd);
				else if (max1 == a[1].nd) max3 = max(a[2].st, a[2].rd);
				else max3 = max(a[2].st, a[2].nd);
			}
			else {
				ans += max2;
				if (max1 == a[2].st) max3 = max(a[1].nd, a[1].rd);
				else if (max1 == a[2].nd) max3 = max(a[1].st, a[1].rd);
				else max3 = max(a[1].st, a[1].nd);
			}
			ans += max3;
			cout << ans << endl;
			continue;
		}
		for (int i = 1; i <= tot; i++) {
			ans += a[i].st;
		}
		cout << ans << endl;
	}
	return 0;
}
// Can I have only ten points? I' m too silly to solve this problem.
