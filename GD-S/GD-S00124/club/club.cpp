#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using pii = pair<int, int>;
using pli = pair<LL, int>;
constexpr int maxn = 1e5;
int n;
int num[maxn + 10];
LL t[maxn + 10][3];
LL a[maxn + 10][4], sum1, sum2, sum3;
void solve() {
	cin >> n;
	sum1 = sum2 = sum3 = 0;
	for (int i = 1; i <= n; ++i) {
		num[i] = 0;
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		sum1 += a[i][1];
		sum2 += a[i][2];
		sum3 += a[i][3];
		t[i][1] = a[i][1] - a[i][2];
		t[i][2] = a[i][3] - a[i][2];
	}
	LL ans = sum2, res = 0;
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	for (int i = 1; i <= n; ++i) {
		if (t[i][1] > t[i][2]) {
			if (t[i][1] >= 0) res += t[i][1], ++cnt1, num[i] = 1;
			else ++cnt3, num[i] = 3;
		} else {
			if (t[i][2] >= 0) res += t[i][2], ++cnt2, num[i] = 2;
			else ++cnt3, num[i] = 3;
		}
	}
	if (cnt1 <= n / 2 && cnt2 <= n / 2 && cnt3 <= n / 2) {
		cout << ans + res << "\n";
		return ;
	}
	priority_queue<LL> q;
	if (cnt3 > n / 2) {
		for (int i = 1; i <= n; ++i) {
			if (num[i] == 3) q.push(max(t[i][1], t[i][2]));
		} 
		while (!q.empty()) {
			LL p = q.top(); q.pop();
			res += p;
			cnt3--;
			if (cnt3 <= n / 2) {
				cout << ans + res << "\n";
				return ;
			}
		}
	}
	if (cnt2 > n / 2) {
		for (int i = 1; i <= n; ++i) {
			if (num[i] == 2) q.push(max(t[i][1] - t[i][2], -t[i][2]));
		} 
		while (!q.empty()) {
			LL p = q.top(); q.pop();
			res += p;
			cnt2--;
			if (cnt2 <= n / 2) {
				cout << ans + res << "\n";
				return ;
			}
		}
	}
	if (cnt1 > n / 2) {
		for (int i = 1; i <= n; ++i) {
			if (num[i] == 1) q.push(max(t[i][2] - t[i][1], -t[i][1]));
		} 
		while (!q.empty()) {
			LL p = q.top(); q.pop();
			res += p;
			cnt1--;
			if (cnt1 <= n / 2) {
				cout << ans + res << "\n";
				return ;
			}
		}
	}
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	while (T--) solve();
	return 0;
}

