#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 2 * 1e5 + 5;

vector <int> KMP(string S) {
	vector <int> pi(S.size(), 0);
	S = " " + S;
	for (int i = 2, j = 0; i < (int)S.size(); i++) {
		while (j && S[i] != S[j + 1]) {
			j = pi[j];
		} pi[i] = (j += (S[i] == S[j + 1]));
	} return pi;
}

int n, q;
string a[N], b[N];
string s, e;

//void Match() {
//	for (int k = 1; k <= n; k++) {
//		string t = a[k];
//		for (int i = 1, j = 0; i < (int)t.size(); i++) {
//			while (j && t[i] != s[j + 1]) {
//				j = pi[j];
//			} j += (t[i] == s[j + 1]);
//			if (j == (int)s.size()) {
//				string pree = s.substr(0, )
//			}
//		}
//	}
//}

void solve() {
	int cnt = 0;
	
	for (int i = 1; i <= n; i++) {
		int len1 = (int)a[i].size();
		int len2 = (int)s.size();
		if (len1 > len2) continue;
		for (int j = 0; j < len2; j++) {
			string t = s.substr(j, len1);
			if (t == a[i]) {
				string pree = s.substr(0, j);
				string nxt = s.substr(j + len1);
				string st = pree + b[i] + nxt;
				if (st == e) {
					cnt++;
				}
			}
		}
	}
	cout << cnt << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	while (q--) {
		cin >> s >> e;
		if ((int)s.size() != (int)e.size()) {
			cout << "0\n";
			continue;
		}
		solve();
	}

	return 0;
}

