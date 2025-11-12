#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 10;
const int mod = 998244353;

int n, a[N][5];

vector <int> vec[5];
vector <int> chg;

void solve () {
	cin >> n;

	for (int i = 0 ; i < 3 ; i ++) vec[i].clear();
	chg.clear();

	for (int i = 1 ; i <= n ; i ++) 
		for (int j = 0 ; j < 3 ; j ++) cin >> a[i][j];
	
	for (int i = 1 ; i <= n ; i ++) {
		if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2]) vec[0].push_back(i);
		else if (a[i][1] >= a[i][2]) 				  vec[1].push_back(i);
		else										  vec[2].push_back(i);
	}

	int mx = 0, mxp;
	for (int i = 0 ; i < 3 ; i ++) 
		if (vec[i].size() > mx) mx = vec[i].size(), mxp = i;

	if (mx <= n / 2) {
		int ans = 0;
		for (int i = 0 ; i < 3 ; i ++)
			for (auto p : vec[i]) ans += a[p][i];
		cout << ans << '\n';
		return;
	}

	int ans = 0;
	for (int i = 0 ; i < 3 ; i ++)
		for (auto p : vec[i]) ans += a[p][i];

	int k = mx - (n / 2);

	for (auto p : vec[mxp]) {
		int val = 0;
		for (int i = 0 ; i < 3 ; i ++)
			if (i != mxp && a[p][i] > val) val = a[p][i];
		chg.push_back(a[p][mxp] - val);
	}

	sort(chg.begin(), chg.end());

	for (int i = 0 ; i < k ; i ++) ans -= chg[i];

	cout << ans << '\n';
}

signed main () {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	int t = 1;
	cin >> t;

	while (t --) solve();
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/