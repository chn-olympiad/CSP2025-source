#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

const int N = 2e5 + 5, B = 131;

int n, q;
ull p[N];
vector<ull> a[2][N], b[2]; 
string s[2][N], t[2];

ull Qa(int id, int i, int l, int r) {
	return a[id][i][r] - a[id][i][l - 1] * p[r - l + 1];
}

ull Qb(int id, int l, int r) {
	return b[id][r] - b[id][l - 1] * p[r - l + 1];
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	p[0] = 1;
	for (int i = 1; i <= 100; i++) {
		p[i] = p[i - 1] * B;
	}
	for (int i = 1; i <= n; i++) {
		cin >> s[0][i] >> s[1][i];
		s[0][i] = '#' + s[0][i];
		s[1][i] = '#' + s[1][i];
		a[0][i].push_back(0);
		a[1][i].push_back(0);
		for (int j = 1; j < s[0][i].size(); j++) {
			a[0][i].push_back(a[0][i].back() * B + s[0][i][j]);
		}
		for (int j = 1; j < s[1][i].size(); j++) {
			a[1][i].push_back(a[1][i].back() * B + s[1][i][j]);
		}
	}
	for (int _ = 1; _ <= q; _++) {
//		cout << "---------\n";
		cin >> t[0] >> t[1];
		t[0] = '#' + t[0];
		t[1] = '#' + t[1];
		b[0].clear();
		b[1].clear();
		b[0].push_back(0);
		b[1].push_back(0);
		for (int j = 1; j < t[0].size(); j++) {
			b[0].push_back(b[0].back() * B + t[0][j]);
		}
		for (int j = 1; j < t[1].size(); j++) {
			b[1].push_back(b[1].back() * B + t[1][j]);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j + s[0][i].size() - 1 < t[0].size() && j + s[1][i].size() - 1 < t[1].size(); j++) {
//				cout << _ << ' ' << i << ' ' << j << '\n';
//				cout << (Qb(0, j, j + s[0][i].size() - 1) == Qa(0, i, 1, s[0][i].size() - 1)) << '\n';
//				cout << (Qb(1, j, j + s[1][i].size() - 1) == Qa(1, i, 1, s[1][i].size() - 1)) << '\n';
//				cout <<	(Qb(0, 1, j - 1) == Qb(1, 1, j - 1)) << '\n';
//				cout << (Qb(0, j + s[0][i].size(), t[0].size() - 1) == Qb(1, j + s[1][i].size(), t[1].size() - 1)) << '\n';
				if (Qb(0, j, j + s[0][i].size() - 1) == Qa(0, i, 1, s[0][i].size() - 1) && 
					Qb(1, j, j + s[1][i].size() - 1) == Qa(1, i, 1, s[1][i].size() - 1) && 
					Qb(0, 1, j - 1) == Qb(1, 1, j - 1) && 
					Qb(0, j + s[0][i].size(), t[0].size() - 1) == Qb(1, j + s[1][i].size(), t[1].size() - 1)) {
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
/**
*/
