#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
long long t, n, ans, fl = 1, k[5], flb = 1, flc = 1, flB = 1;
long long aa[100005], a[100005][5], bb[100005], cc[100005];
void dfs(long long l, long long sum) {
	if (l == n + 1) {
		ans = max(ans, sum);
		return;
	}
	for (int i = 1; i <= 3; i++) {
		if (k[i] < n / 2) {
			k[i]++;
			dfs(l + 1, sum + a[l][i]);
			k[i]--;
		}
	}
}
bool cmp(long long q, long long e) {
	return q > e;
}
struct node {
	long long xx, mm, kkk, id;
};
node u[100005];
bool cmd(node q, node e) {
	return abs(q.kkk) < abs(e.kkk);
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		ans = 0;
		fl = 1;
		flb = 1;
		flc = 1;
		flB = 1;
		for (int i = 1; i <= 5; i++) k[i] = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (a[i][2] != 0 || a[i][3] != 0) {
				fl = 0;
			}
			if (a[i][1] != 0 || a[i][3] != 0) {
				flb = 0;
			}
			if (a[i][2] != 0 || a[i][1] != 0) {
				flc = 0;
			}
			if (a[i][3] != 0) flB = 0;
			aa[i] = a[i][1];
			bb[i] = a[i][2];
			cc[i] = a[i][3];
			u[i].kkk = a[i][1] - a[i][2];
			if (a[i][1] >= a[i][2]) u[i].xx = 1;
		}
		if (fl) {
			sort(aa + 1, aa + n + 1, cmp);
			for (int i = 1; i <= n / 2; i++) {
				ans += aa[i];
			}
			cout << ans;
		} else if (flb) {
			sort(bb + 1, bb + n + 1, cmp);
			for (int i = 1; i <= n / 2; i++) {
				ans += bb[i];
			}
			cout << ans;
		} else if (flc) {
			sort(cc + 1, cc + n + 1, cmp);
			for (int i = 1; i <= n / 2; i++) {
				ans += cc[i];
			}
			cout << ans;
		} else if (flB) {
			for (int i = 1; i <= n; i++) {
				ans += max(a[i][1], a[i][2]);
				if (a[i][1] >= a[i][2]) k[1]++;
				else k[2]++;
			}
			sort(u + 1, u + n + 1, cmd);
			int O = 1;
			while (k[1] > n / 2) {
				if(u[O].kkk>=0){
					ans -= u[O].kkk;
					k[1]--;
				}
				O++;
			}
			O = 1;
			while (k[2] > n / 2) {
				if(u[O].kkk<=0){
					ans += u[O].kkk;
					k[2]--;
				}
				O++;
			}
			cout<<ans;
		} else {
			dfs(1, 0);
			cout << ans;
		}
	}
}