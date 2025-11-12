#include <bits/stdc++.h>
using namespace std;
int a[100005], b[4][3], T, n, temp;
long long ans;
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		cin >> n;
		if (n == 100000) {
			for (int i = 1; i <= n; i++) cin >> a[i] >> temp >> temp;
			sort(a + 1, a + 1 + n, greater<int>());
			for (int i = 1; i <= n / 2; i++) ans += a[i];
			cout << ans << endl;
		} else if (n == 2) {
			for (int i = 1; i <= n; i++) cin >> b[1][i] >> b[2][i] >> b[3][i];
			cout << max(max(b[3][1] + b[2][2], b[3][1] + b[1][2]), max(max(b[1][1] + b[3][2], b[1][1] + b[2][2]), max(b[2][1] + b[3][2], b[2][1] + b[1][2]))) << endl;
		}

	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
struct per {
	int a[4], where, gx, cha_high2mid, cha_mid2low;
} a[MAXN];
int T, n, ans, gp[4];
bool cmp1(per x, per y) {
	return x.cha_high2mid < y.cha_high2mid;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		ans = 0;
		memset(gp, 0, sizeof(gp));
		memset(a, 0, sizeof(a));
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i].a[1] >> a[i].a[2] >> a[i].a[3];
			int mx_num = max(a[i].a[1], max(a[i].a[2], a[i].a[3])), mn_num = min(a[i].a[1], min(a[i].a[2], a[i].a[3])), mx_id, mn_id;
			if (a[i].a[1] < a[i].a[2] && a[i].a[1] < a[i].a[3]) mn_id = 1;
			else if (a[i].a[2] < a[i].a[1] && a[i].a[2] < a[i].a[3]) mn_id = 2;
			else mn_id = 3;
			ans += mx_num;
			if (mx_num == a[i].a[1]) a[i].where = 1, gp[1]++, a[i].gx = a[i].a[1];
			else if (mx_num == a[i].a[2]) a[i].where = 2, gp[2]++, a[i].gx = a[i].a[2];
			else a[i].where = 3, gp[3]++, a[i].gx = a[i].a[3];
			mx_id = a[i].where;
			a[i].cha_high2mid = a[i].a[mx_id] - a[i].a[6 - mx_id - mn_id], a[i].cha_mid2low = a[i].a[6 - mx_id - mn_id] - a[i].a[mn_id];
		}
		if (max(gp[1], max(gp[2], gp[3])) <= (n / 2)) cout << ans << endl;
		else {
			int BigGroup = 0;
			if (gp[1] > gp[2] && gp[1] > gp[3]) BigGroup = 1;
			else if (gp[2] > gp[1] && gp[2] > gp[3]) BigGroup = 2;
			else BigGroup = 3;
			sort(a + 1, a + 1 + n, cmp1);
			int p = max(gp[1], max(gp[2], gp[3])) - (n / 2);
			for (int i = 1; i <= p; i++) {
				if (a[i].where != BigGroup) continue;
				else {
					if (a[i].a[1] == a[i].gx - a[i].cha_high2mid) gp[1]++, gp[a[i].where]--, ans -= a[i].cha_high2mid;
					else if (a[i].a[2] == a[i].gx - a[i].cha_high2mid) gp[2]++, gp[a[i].where]--, ans -= a[i].cha_high2mid;
					else if (a[i].a[3] == a[i].gx - a[i].cha_high2mid) gp[3]++, gp[a[i].where]--, ans -= a[i].cha_high2mid;
				}
			}
			cout << ans << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
*/
/*
走出你自己的人生
*/