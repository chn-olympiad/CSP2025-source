#include <bits/stdc++.h>
#define int long long
#define rep(i, l, r) for (int i = (l); i <= (r); ++ i)
#define per(i, l, r) for (int i = (l); i >= (r); -- i)
using namespace std;
const int p1 = 998244353, p2 = 1e9 + 7;
const int N = 2e5 + 10, M = 5e6 + 10, B = 27;
int n, q, p1w[M], p2w[M], ssz[N];
vector <int> s1p1[N], s1p2[N], s2p1[N], s2p2[N];
int tn(char ch) {
	return ch - 'a' + 1;
}
vector <int> get_hash(const string &str, int p) {
	vector <int> ret;
	ret.push_back(tn(str[0]));
	rep(i, 1, (int)(str.size()) - 1) {
		ret.push_back((ret.back() * B % p + tn(str[i])) % p);
	}
	return ret;
}
int get_substr(const vector <int> &v, const int i, const int len, int *pw, int p) {
	if (i == 0) {
		return v[len - 1];
	}
	return (v[i + len - 1] - v[i - 1] * pw[len] % p + p) % p;
}
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	p1w[0] = p2w[0] = 1;
	rep(i, 1, M - 1) {
		p1w[i] = p1w[i - 1] * B % p1;
		p2w[i] = p2w[i - 1] * B % p2;
	}
	cin >> n >> q;
	rep(i, 1, n) {
		string s1, s2;
		cin >> s1 >> s2;
		ssz[i] = s1.size();
		s1p1[i] = get_hash(s1, p1);
		s1p2[i] = get_hash(s1, p2);
		s2p1[i] = get_hash(s2, p1);
		s2p2[i] = get_hash(s2, p2);
	}
	rep(_, 1, q) {
		string t1, t2;
		cin >> t1 >> t2;
		vector <int> t1p1 = get_hash(t1, p1);
		vector <int> t1p2 = get_hash(t1, p2);
		vector <int> t2p1 = get_hash(t2, p1);
		vector <int> t2p2 = get_hash(t2, p2);
		int tsz = t1.size(), ans = 0;
		int lst = tsz - 1;
		while (lst >= 0 && t1[lst] == t2[lst]) {
			-- lst;
		}
		// t1[lst+1~end] == t2[lst+1~end]
		// t1[lst] != t2[lst]
		rep(i, 0, tsz - 1) {
			if (i > 0 && t1[i - 1] != t2[i - 1]) {
				break;
			}
			rep(j, 1, n) {
				if (i + ssz[j] - 1 >= tsz) {
					continue;
				}
				if (i + ssz[j] - 1 < lst) {
					continue;
				}
				// t1[i,len=ssz[j]] == s1[j]
				// substr(t1, i, ssz[j]) == s1[j]
				// t2[i,len=ssz[j]] == s2[j]
				// substr(t2, i, ssz[j]) == s2[j]
				if (get_substr(t1p1, i, ssz[j], p1w, p1) == s1p1[j][ssz[j] - 1]
				 && get_substr(t1p2, i, ssz[j], p2w, p2) == s1p2[j][ssz[j] - 1]
				 && get_substr(t2p1, i, ssz[j], p1w, p1) == s2p1[j][ssz[j] - 1]
				 && get_substr(t2p2, i, ssz[j], p2w, p2) == s2p2[j][ssz[j] - 1]) {
					++ ans;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
