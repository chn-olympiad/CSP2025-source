#include <bits/stdc++.h>
using namespace std;
int n, m;
struct stu {
	int id, val;
} a[110];
bool cmp(stu x, stu y) {
	return x.val > y.val;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i].val;
		a[i].id = i;
	}
	sort(a + 1, a + n * m + 1, cmp);
	int tmp = 1;
	for (; a[tmp].id != 1; tmp++);
	int xxx = (tmp - 1) / n + 1, yyy;
	yyy = (tmp - 1) % n + 1;
	if (xxx % 2 == 0) yyy = n - yyy + 1;
	cout << xxx << ' ' << yyy;
	return 0;
}
