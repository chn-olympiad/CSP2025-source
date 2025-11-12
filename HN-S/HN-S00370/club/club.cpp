#include <bits/stdc++.h>

using namespace std;
using Pii = pair <int, int>;

const int kN = 1e5 + 5;

bool vis[kN];
int a[kN][3], id[kN], cnt[3];
Pii rec[kN * 2];
int tot;
int T, n, ans;

void Calc (int v) {
	tot = 0;
	fill (vis + 1, vis + 1 + n, 0);
	for (int i = 1; i <= n; ++i) {
		if (id[i] == v) {
			for (int j = 0; j < 3; ++j) {
				if (v != j) {
					rec[++tot] = {a[i][v] - a[i][j], i};
				}
			}
		}
	}
	sort (rec + 1, rec + 1 + tot, [](Pii x, Pii y) {
		return x.first > y.first;
	});
	
	int lim = cnt[v] - n / 2;
	for (; tot && lim; ) {
		Pii lt = rec[tot--];
		int val = lt.first, i = lt.second;
		if (vis[i]) continue;
		bool flag = 1;
		for (int j = 0; j < 3; ++j) if (j != v && val == a[i][v] - a[i][j] && cnt[j] == n / 2) {
			flag = 0;
		}
		if (!flag) {
			continue;
		}
		
		for (int j = 0; j < 3; ++j) if (j != v && a[i][v] - a[i][j] == val) {
			++cnt[j];
			break;
		}
		vis[i] = 1;
		ans -= val;
		--lim;
	}
}

void Solve () {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}
	ans = cnt[0] = cnt[1] = cnt[2] = 0;
	for (int i = 1; i <= n; ++i) {
		int maxi = max (a[i][0], max (a[i][1], a[i][2]));
		if (maxi == a[i][0]) {
			++cnt[0];
			id[i] = 0;
		} else if (maxi == a[i][1]) {
			++cnt[1];
			id[i] = 1;
		} else {
			++cnt[2];
			id[i] = 2;
		} 
		ans += maxi;
	}
	if (cnt[0] > n / 2) {
		Calc (0);
	} else if (cnt[1] > n / 2) {
		Calc (1);
	} else if (cnt[2] > n / 2) {
		Calc (2);
	}
	
	cout << ans << '\n'; 
}

int main () {
  freopen ("club.in", "r", stdin);
  freopen ("club.out", "w", stdout);
  ios::sync_with_stdio (0);
  cin.tie (0), cout.tie (0);
  
  for (cin >> T; T--; Solve ()) {
	}
  return 0;
}

