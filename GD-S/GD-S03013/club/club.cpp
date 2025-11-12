//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> 
using namespace std;

typedef long long ll;
// #define int ll

 #define SUBMIT

#define fi first
#define se second

signed main() {
#ifdef SUBMIT
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("club.in", "r", stdin); freopen("club.out", "w", stdout);
//	freopen("club5.in", "r", stdin); freopen("club5.out", "w", stdout);
#endif

	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		vector<vector<pair<int, int>>> sat(n + 1, vector<pair<int, int>>(3, make_pair(0, 0)));
		for (int i = 1; i <= n; ++i) {
			sat[i][0].se = 0, sat[i][1].se = 1, sat[i][2].se = 2;
			cin >> sat[i][0].fi >> sat[i][1].fi >> sat[i][2].fi;
			sort(sat[i].begin(), sat[i].end());
//			cout << sat[i][0].fi << ' ' << sat[i][1].fi << ' ' << sat[i][2].fi << '\n';
		}

		ll ans = 0LL;
		
		vector<vector<pair<int, int>>> conts(3, vector<pair<int, int>>());
		vector<int> sz(3, 0);
		for (int i = 1; i <= n; ++i) {
			conts[sat[i][2].se].push_back(make_pair(sat[i][2].fi - sat[i][1].fi, i));
			ans += sat[i][2].fi;
			sz[sat[i][2].se] += 1;
		}

		for (int i = 0; i < 3; ++i) {
			if (sz[i] > n / 2) {
				sort(conts[i].begin(), conts[i].end());
				for (int j = 0; j < conts[i].size(); ++j) {
					if (sz[i] <= n / 2)
						break;
					const int del_delta = conts[i][j].fi, del_id = conts[i][j].se;
					ans -= del_delta;
					sz[i] -= 1;
				}
			}
		}

		cout << ans << '\n';

	}

	return 0;
}
