#define ffopen(s) \
ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cerr.tie(0); \
if (*#s) freopen(#s ".in", "r", stdin); \
if (*#s) freopen(#s ".out", "w", stdout); \
//
#include <bits/stdc++.h>
using namespace std;
using intl = long long;
const int N = 100000;
int n, a[N + 10][3];
vector<int> cnt[3];
void slove() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int c : {0, 1, 2}) {
			cin >> a[i][c];
		}
	}
	static int idx[3] = {0, 1, 2};
	intl ans = 0;
	for (int i = 1; i <= n; i++) {
		sort(idx, idx + 3, [&](int x, int y) { return a[i][x] > a[i][y]; } );
		cnt[idx[0]].push_back(i);
		ans += a[i][idx[0]];
	}
	if ((int)cnt[0].size() <= (n >> 1) && (int)cnt[1].size() <= (n >> 1) && (int)cnt[2].size() <= (n >> 1)) {
		cout << ans << '\n';
		return;
	}
	sort(idx, idx + 3, [&](int x, int y) { return cnt[x].size() > cnt[y].size(); } );
	multiset<pair<int, int> > st;
	for (int i : cnt[idx[0]]) {
		st.insert({a[i][idx[1]] - a[i][idx[0]], i});
		st.insert({a[i][idx[2]] - a[i][idx[0]], i});
	}
	int cc = cnt[idx[0]].size();
	while (true) {
		int i, val;
		tie(val, i) = *prev(st.end());
		ans += val, --cc;
		st.erase(st.find({a[i][idx[1]] - a[i][idx[0]], i}));
		st.erase(st.find({a[i][idx[2]] - a[i][idx[0]], i}));
		if (cc <= (n >> 1)) break;
	}
	cout << ans << '\n';
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0), cerr.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T; cin >> T;
	while (T--) {
		slove();
		cnt[0].clear();
		cnt[1].clear();
		cnt[2].clear();
	}
	return 0;
}
