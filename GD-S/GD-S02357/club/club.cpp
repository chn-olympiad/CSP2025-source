#include<bits/stdc++.h>
#define For(i, x, y) for (int i = x; i <= y; i++)
using namespace std;
int n;
struct worker {
	int a, b, c;
} w[100005], s[100005];
bool cmp(worker x, worker y) {
	int sumx = x.a + x.b + x.c, sumy = y.a + y.b + y.c;
	if (sumx != sumy) return sumx > sumy;
	else if (x.a != y.a) return x.a > y.a;
	else if (x.b != y.b) return x.b > y.b;
	else return x.c > y.c;
}
bool chk(int x) {
	if (x >= n / 2) return false;
	else return true;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t, ans;
	cin >> t;
	while (t--) {
		ans = 0;
		cin >> n;
		For(i, 1, n) {
			cin >> w[i].a >> w[i].b >> w[i].c;
			s[i].a = s[i - 1].a + w[i].a;
			s[i].b = s[i - 1].b + w[i].b;
			s[i].c = s[i - 1].c + w[i].c;
		}
		sort(w + 1, w + n + 1, cmp);
		For(i, 1, n) {
			s[i].a = s[i - 1].a + w[i].a;
			s[i].b = s[i - 1].b + w[i].b;
			s[i].c = s[i - 1].c + w[i].c;
		}
		int cnt1 = 0, cnt2 = 0, cnt3 = 0;
		For(i, 1, n) {
			int wus1 = (s[n].a - s[i].a);
			int wus2 = (s[n].b - s[i].b);
			int wus3 = (s[n].c - s[i].c);
			if (cnt1 == n / 2) w[i].a = 0;
			if (cnt2 == n / 2) w[i].b = 0;
			if (cnt3 == n / 2) w[i].c = 0;
			if (!chk(cnt1 + 1)) wus1 = -1e9;
			int sum1 = w[i].a - w[i].b - w[i].c + max(wus1, max(wus2, wus3));
			wus1 = (s[n].a - s[i].a);
			if (!chk(cnt2 + 1)) wus2 = -1e9;
			int sum2 = w[i].b - w[i].a - w[i].c + max(wus1, max(wus2, wus3));
			wus2 = (s[n].b - s[i].b);
			if (!chk(cnt3 + 1)) wus3 = -1e9;
			int sum3 = w[i].c - w[i].b - w[i].a + max(wus1, max(wus2, wus3));
			wus3 = (s[n].c - s[i].c);
			if (cnt1 == n / 2) sum1 = -1e9;
			if (cnt2 == n / 2) sum2 = -1e9;
			if (cnt3 == n / 2) sum3 = -1e9;
			if (sum1 >= sum2) {
				if (sum1 >= sum3) {
					cnt1++;
					ans += w[i].a;
				} else {
					cnt3++;
					ans += w[i].c;
				}
			} else if (sum2 >= sum3) {
				if (sum2 >= sum1) {
					cnt2++;
					ans += w[i].b;
				} else {
					cnt1++;
					ans += w[i].a;
				}
			} else if (sum3 >= sum1) {
				if (sum3 >= sum2) {
					cnt3++;
					ans += w[i].c;
				} else {
					cnt2++;
					ans += w[i].a;
				}
			}
		}
		cout << ans << endl; 
	}
}
