#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct node {
	int x, y, z;
}a[N];
int cha[N];

int check (int x1, int y1, int z1) {
	if (x1 >= y1 && x1 >= z1) return 1;
	if (y1 >= x1 && y1 >= z1) return 2;
	return 3;
}

int check2 (int x1, int y1, int z1) {
	if ((x1 <= y1 && x1 >= z1) || (x1 >= y1 && x1 <= z1)) return 1;
	if ((y1 <= x1 && y1 >= z1) || (y1 >= x1 && y1 <= z1)) return 2;
	return 3;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("clud.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		memset(cha, 0x3f3f3f, sizeof(cha));
		int n;
		cin >> n;
		int cnt[4] = {0, 0, 0, 0};
		for (int i = 1; i <= n; i++) {
			cin >> a[i].x >> a[i].y >> a[i].z;
			cnt[check(a[i].x, a[i].y, a[i].z)]++;
		}
		long long ans = 0;
		if (cnt[1] <= n / 2 && cnt[2] <= n / 2 && cnt[3] <= n / 2) {
			for (int i = 1; i <= n; i++) {
				if (check(a[i].x, a[i].y, a[i].z) == 1) {
					ans += a[i].x; 
				} else if (check(a[i].x, a[i].y, a[i].z) == 2) {
					ans += a[i].y;
				} else {
					ans += a[i].z;
				}
			}
		} else {
			for (int i = 1; i <= n; i++) {
				if (check(a[i].x, a[i].y, a[i].z) == 1) {
					ans += a[i].x; 
				} else if (check(a[i].x, a[i].y, a[i].z) == 2) {
					ans += a[i].y;
				} else {
					ans += a[i].z;
				}
			}
			int res = check(cnt[1], cnt[2], cnt[3]); 
			for (int i = 1; i <= n; i++) {
				if (check(a[i].x, a[i].y, a[i].z) == res) {
					int pre = check2(a[i].x, a[i].y, a[i].z);
					int num1, num2;
					if (res == 1) num1 = a[i].x;
					if (res == 2) num1 = a[i].y; 
					if (res == 3) num1 = a[i].z; 
					if (pre == 1) num2 = a[i].x; 
					if (pre == 2) num2 = a[i].y; 
					if (pre == 3) num2 = a[i].z;
					cha[i] = min((num1 - num2), cha[i]);
				}
			}
			sort(cha + 1, cha + n + 1);
			for (int i = 1; i <= cnt[res] - n / 2; i++) {
				ans -= cha[i];
			}
		}
		cout << ans << endl;
	}
	return 0; 
}
