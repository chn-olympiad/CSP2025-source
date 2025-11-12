#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
int n, a[100005][4], h[100005][4], tmp[100005], cur[100005];
pair<int, pair<int, int> > p[100005];
int house[4];
vector<pair<int, int> > loss[4];
bool cmp(pair<int, int> aa, pair<int, int> bb) {
	if (aa.second != bb.second) return aa.second > bb.second;
	return aa.first < bb.first;
}
inline void get_rank(int x) {
	pair<int, int> b[4];
	for (int i = 1; i <= 3; i++) b[i] = make_pair(i, a[x][i]);
	sort(b + 1, b + 4, cmp);
	for (int i = 1; i <= 3; i++) h[x][i] = b[i].first;
}
inline bool cmp1(pair<int, pair<int, int> > aa, pair<int, pair<int, int> > bb) {
	int aaa[4], bbb[4];
	aaa[1] = aa.first, aaa[2] = aa.second.first, aaa[3] = aa.second.second;
	bbb[1] = bb.first, bbb[2] = bb.second.first, bbb[3] = bb.second.second;
	sort(aaa + 1, aaa + 4);
	sort(bbb + 1, bbb + 4);
	for (int i = 3; i >= 1; i--) {
		if (aaa[i] > bbb[i]) return true;
		if (aaa[i] < bbb[i]) return false;
	}
	return false;
}
inline bool cmp2(pair<int, int> aa, pair<int, int> bb) {
	if (aa.second != bb.second) return aa.second < bb.second;
	return aa.first < bb.first;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int T; cin >> T;
	while (T--) {
		memset(house, 0, sizeof(house));
		memset(cur, 0, sizeof(cur));
		for (int i = 1; i <= 3; i++) loss[i].clear();
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i][1] >> a[i][2] >> a[i][3];
		for (int i = 1; i <= n; i++) p[i] = make_pair(a[i][1], make_pair(a[i][2], a[i][3]));
		sort(p + 1, p + n + 1, cmp1);
		for (int i = 1; i <= n; i++) a[i][1] = p[i].first, a[i][2] = p[i].second.first, a[i][3] = p[i].second.second;
		//for (int i = 1; i <= n; i++) cout << a[i][1] << ' ' << a[i][2] << ' ' << a[i][3] << '\n';
		for (int i = 1; i <= n; i++) get_rank(i);
		//cout << "rank:\n";
		//for (int i = 1; i <= n; i++) cout << h[i][1] << ' ' << h[i][2] << ' ' << h[i][3] << '\n';
		for (int i = 1; i <= n; i++) tmp[i] = 1;
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			int id = h[i][tmp[i]];
			house[id]++, cur[i] = id;
			ans += 1ll * a[i][id];
			for (int j = tmp[i] + 1; j <= 3; j++) {
				int pre = a[i][id], now = a[i][h[i][j]];
				loss[id].push_back(make_pair(i, pre - now));
				//cout << "loss house=" << id << " member=" << i << " value=" << pre - now << endl;
			}
			//cout << i << " -> " << id << endl;
			if (house[id] > n / 2) {
				sort(loss[id].begin(), loss[id].end(), cmp2);
				for (pair<int, int> now : loss[id]) {
					int _id = now.first;
					if (cur[_id] != id) continue;
					house[h[_id][tmp[_id]]]--;
					//cout << "change " << _id << " from " << h[_id][tmp[_id]];
					ans -= 1ll * a[_id][h[_id][tmp[_id]]];
					tmp[_id]++;
					house[h[_id][tmp[_id]]]++;
					ans += 1ll * a[_id][h[_id][tmp[_id]]];
					cur[_id] = h[_id][tmp[_id]];
					//cout << " to " << h[_id][tmp[_id]] << endl;
					break;
				}
			}
		}
		cout << ans << '\n';
		//for (int i = 1; i <= n; i++) cout << cur[i] << ' ';
		//cout << '\n';
	}
	return 0;
}
