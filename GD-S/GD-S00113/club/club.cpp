#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
const int N = 1e5 + 5;
ll a[N][4];
vector<int> c[4];
vector<int> tmp;
int buc[N];

int cp1(ll x, ll y, ll z) {
	if (x >= y && x >= z) return 1;
	if (y >= x && y >= z) return 2;
	return 3;
}

int cp2(int v, ll x, ll y, ll z) {
	if (v == 1) {
		if (y >= z) return 2;
		else return 3;
	}
	if (v == 2) {
		if (x >= z) return 1;
		else return 3;
	}
	if (v == 3) {
		if (x >= y) return 1;
		else return 2;
	}
	return 0;
}

bool cmp(int x, int y) {
	ll xp1 = a[x][buc[x]];
	ll xp2 = a[x][cp2(buc[x], a[x][1], a[x][2], a[x][3])];
	ll yp1 = a[y][buc[y]];
	ll yp2 = a[y][cp2(buc[y], a[y][1], a[y][2], a[y][3])];
	return xp2 - xp1 < yp2 - yp1;
}

void solve() {
	for (int i = 1; i <= 3; i++) c[i].clear();
	tmp.clear();
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) cin >> a[i][j];
	}
	for (int i = 1; i <= n; i++) {
		buc[i] = cp1(a[i][1], a[i][2], a[i][3]);
		c[buc[i]].push_back(i);
	}
	int flag = 0;
	for (int i = 1; i <= 3; i++) {
		if (c[i].size() > (n / 2)) {
			flag = i;
			break;
		}
	}
	if (flag) {
		tmp = c[flag];
		sort(tmp.begin(), tmp.end(), cmp);
		int r = tmp.size() - n / 2;
		for (int i = 1; i <= r; i++) {
			int x = tmp.back();
			tmp.pop_back();
			int npos = cp2(buc[x], a[x][1], a[x][2], a[x][3]);
			c[npos].push_back(x);
		}
		c[flag] = tmp;
	}
	ll ans = 0;
	for (int i = 1; i <= 3; i++) {
		for (auto x : c[i]) {
			ans += a[x][i];
		}
	}
	printf("%lld\n", ans);
} 

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}
