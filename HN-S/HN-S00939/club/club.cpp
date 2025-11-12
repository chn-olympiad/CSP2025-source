#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 5;
int n, a[N][3], ans, d[N];
vector<int> v[3];

void solve() {
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		int x = a[i][0], y = a[i][1], z = a[i][2];
		if(x >= y && x >= z) {
			v[0].push_back(i), ans += x;
			d[i] = max(y - x, z - x);
		} else if(y >= x && y >= z) {
			v[1].push_back(i), ans += y;
			d[i] = max(x - y, z - y);
		} else {
			v[2].push_back(i), ans += z;
			d[i] = max(x - z, y - z);
		}
	}
	int id = -1;
	if(v[0].size() > n / 2) { id = 0; }
	if(v[1].size() > n / 2) { id = 1; }
	if(v[2].size() > n / 2) { id = 2; }
	if(id == -1) { return cout << ans << endl, void(); }
	sort(v[id].begin(), v[id].end(), [](const int &x, const int &y) {
		return d[x] > d[y];
	});
	for(int i = 1; i <= v[id].size() - n / 2; i ++) {
		ans += d[v[id][i - 1]];
	}
	cout << ans << endl;
}
void init() {
	ans = 0, v[0].clear(), v[1].clear(), v[2].clear();
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int cas = 1; cin >> cas;
	for(; cas --; ) { init(), solve(); }
	return 0;
}

