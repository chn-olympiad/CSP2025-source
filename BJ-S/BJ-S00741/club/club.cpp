#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int t, n, cnt1, cnt2, cnt3, sum, cnt, ans[100005];
struct node{
	int x, y, z;
}a[100005];

bool cmp1(node a, node b) {
	return a.x >= b.x;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		cnt1 = cnt2 = cnt3 = sum = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].x >> a[i].y >> a[i].z;
			if (a[i].x >= a[i].y && a[i].x >= a[i].z) cnt1++, sum += a[i].x;
			else if (a[i].y >= a[i].x && a[i].y >= a[i].z) cnt2++, sum += a[i].y;
			else cnt3++, sum += a[i].z;
		}
		if (cnt2 > cnt1) {
			for (int i = 1; i <= n; i++) swap(a[i].x, a[i].y);
			swap(cnt1, cnt2);
		}
		if (cnt3 > cnt1) {
			for (int i = 1; i <= n; i++) swap(a[i].x, a[i].z);
			swap(cnt1, cnt3);
		}
		if (cnt1 <= n / 2) {
			cout << sum << "\n";
			continue;
		}

		cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i].x >= a[i].y && a[i].x >= a[i].z) {
				ans[++cnt] = min(a[i].x - a[i].y, a[i].x - a[i].z);
			}
		}
		sort(ans + 1, ans + cnt + 1);
		for (int i = 1; i <= cnt1 - (n / 2); i++) sum -= ans[i];
			cout << sum << "\n";
	}
	return 0;
}