#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int Mod = 998244353, mod = 1e9 + 7, N = 1e5 + 10;
int a[N][3], b[N], cnt[3], maxs[N];

void solve() {
	int n, sum = 0;
	cnt[0] = cnt[1] = cnt[2] = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		int maxn = 0, cd = 0;
		for (int j = 0; j < 3; j++) {
			if (a[i][j] > maxn) cd = maxn, maxn = a[i][j], maxs[i] = j;
			else if (a[i][j] > cd) cd = a[i][j];
		}
		b[i] = maxn - cd, cnt[maxs[i]]++, sum += maxn;
	}
	int mn = 0, ms;
	for (int i = 0; i < 3; i++) {
		if (cnt[i] > mn) mn = cnt[i], ms = i;
	}
	if (mn > n / 2) {
		int ne = mn - n / 2;
		vector<int> t;
		for (int i = 1; i <= n; i++) {
			if (maxs[i] == ms) t.push_back(b[i]);
		}
		sort(t.begin(), t.end());
		for (int i = 0; i < ne; i++) sum -= t[i];
	}
	cout << sum << endl;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	
	return 0;
}

