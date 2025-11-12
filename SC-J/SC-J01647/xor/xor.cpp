#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500005;
int a[N], d[N];
struct cla {
	int s, e;
} stu[N];
bool cmp(cla x, cla y) {
	return x.e < y.e;
}
signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int cur = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			int ans = a[i];
			for (int k = i + 1; k <= j; k++) {
				ans ^= a[k];
			}
			if (ans == m) {
				stu[++cur] = {i, j};
			}
		}
	}
	stable_sort(stu + 1, stu + cur + 1, cmp);
	int ans = 0;
	int en = 0;
	for (int i = 1; i <= cur; i++) {
		if (en < stu[i].s) {
			en = stu[i].e;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}