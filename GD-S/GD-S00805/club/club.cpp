#include <bits/stdc++.h>
int n;
long long ans;
struct {int my[3]; int chose;} student[100005];
void func(int ind, int anum, int bnum, int cnum) {
	if (ind == n) {
		long long tmp = 0;
		for (int i = 0; i < n; ++i) tmp += student[i].my[student[i].chose];
		if (tmp > ans) ans = tmp;
		return;
	}
	if (anum < n / 2) student[ind].chose = 0, func(ind + 1, anum + 1, bnum, cnum);
	if (bnum < n / 2) student[ind].chose = 1, func(ind + 1, anum, bnum + 1, cnum);
	if (cnum < n / 2) student[ind].chose = 2, func(ind + 1, anum, bnum, cnum + 1);
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	for (scanf("%d", &t); t--;) {
		scanf("%d", &n), ans = 0;
		for (int i = 0; i < n; ++i) scanf("%d%d%d", &student[i].my[0], &student[i].my[1], &student[i].my[2]);
		func(0, 0, 0, 0), printf("%lld\n", ans);
	}
}
