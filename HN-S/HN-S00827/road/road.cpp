#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int kMaxN = 1e4 + 5, kM = 15;

int n, m, k, r[kMaxN + kM], c[kM];
bool b[kM];
vector<array<int, 3>> e;
LL ans = 1e18;

int R(int x) {
	return x == r[x] ? x : r[x] = R(r[x]);
}

LL C(LL v) {
	iota(r + 1, r + kMaxN + kM, 1);
	for (auto i : e) {
		if ((i[1] <= n || b[i[1] - n]) && R(i[1]) != R(i[2])) {
			v += i[0];
			if (v > ans) {
				return v;
			}
			r[R(i[1])] = R(i[2]);
		}
	}
	return v; 
}

void S(int s, LL v) {
	if (v > ans) {
		return ;
	}
	if (s > k) {
		ans = min(ans, C(v));
		return ;
	}
	S(s + 1, v);
	b[s] = 1;
	S(s + 1, v + c[s]);
	b[s] = 0;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> n >> m >> k;
	for (int i = 1, x, y, w; i <= m; i++) {
		cin >> x >> y >> w;
		e.push_back({w, x, y});
	}
	bool f = 1;
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		f &= !c[i];
		for (int j = 1, x; j <= n; j++) {
			cin >> x;
			e.push_back({x, i + n, j});
		}
	}
	stable_sort(e.begin(), e.end());
	if (f) {
		fill(b + 1, b + k + 1, 1);
		cout << C(0);
		return 0;
	}
	S(1, 0);
	cout << ans;
	return 0;
} 
