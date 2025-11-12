#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2*1e5+4;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);


	int t = 0;
	string m1[MAXN], m2[MAXN], h1, h2;

	int n, q;
	cin >> n >> q;

	long long strlen[MAXN] = {};

	for (int i = 1; i <= n; i++) {
		cin >> m1[i] >> m2[i];
		strlen[i] = m1[i].size();
	}

	for (int i = 1; i <= q; i++) {
		int cnt = 0;
		cin >> h1 >> h2;

		for (int j = 1; j <= n; j++) {

		}
	}

	return 0;
}
