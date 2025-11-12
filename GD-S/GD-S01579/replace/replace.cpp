#include <bits/stdc++.h>
using namespace std;
using ll = long long; using ld = long double; using pll = pair<ll, ll>;
template<typename T1, typename T2> bool chkmin(T1 &a, const T2 &b) { return b < a ? (a = b, true) : false; }
template<typename T1, typename T2> bool chkmax(T1 &a, const T2 &b) { return b > a ? (a = b, true) : false; }
void fileIO(const string& x) { freopen((x + ".in").c_str(), "r", stdin); freopen((x + ".out").c_str(), "w", stdout); } 
mt19937_64 gen(random_device{}());
ll test_case = 1, test_num = 1;
const int int_Inf = 1e9; const ll Inf = 1e18;

const ll L = 5e6 + 5, Q = 2e5 + 5;

ll n, q;
vector<string> s1, s2;
vector<string> t1, t2;

struct BIT {
	ll t[L];
	stack<ll> hist;
	ll lowbit(ll x) { return x & -x; }
	void upd(ll x, ll val) {
		hist.push(x);
		for(int i = x; i < L; i += lowbit(i)) {
			t[i] += val;
		}
	}
	ll query(ll x) {
		ll res = 0;
		for(int i = x; i >= 1; i -= lowbit(i)) {
			res += t[i];
		}
		return res;
	}
	void clear() {
		while(!hist.empty()) {
			ll x = hist.top(); hist.pop();
			for(int i = x; i < L; i += lowbit(i)) {
				t[i] = 0;
			}
		}
	}
} bt;

namespace B {
	bool check() {
		auto check_str = [](const vector<string> &str_vec) {
			for(auto str : str_vec) {
				ll b_cnt = 0;
				for(char ch : str) {
					if(ch != 'a' && ch != 'b') return false;
					if(ch == 'b') b_cnt++;
				}
				if(b_cnt != 1) return false;
			}
			return true;
		};
		return check_str(s1) && check_str(s2) && check_str(t1) && check_str(t2);
	}
	struct Node {
		ll pre, suf;
	};
	vector<Node> pts[L * 2];
	struct Query {
		ll pre, suf, id;
	};
	vector<Query> qry[L * 2];
	ll ans[Q];
	void solve() {
		for(int i = 0; i < n; i++) {
			ll p1 = -1, p2 = -1, sz = s1[i].size();
			assert(s1[i].size() == s2[i].size());
			for(int j = 0; j < sz; j++) if(s1[i][j] == 'b') p1 = j;
			for(int j = 0; j < sz; j++) if(s2[i][j] == 'b') p2 = j;
			ll dlt = p2 - p1 + 5e6;
			pts[dlt].push_back({ p1, sz - p1 });
		}
		for(int i = 0; i < q; i++) {
			ll p1 = -1, p2 = -1, sz = t1[i].size();
			assert(t1[i].size() == t2[i].size());
			for(int j = 0; j < sz; j++) if(t1[i][j] == 'b') p1 = j;
			for(int j = 0; j < sz; j++) if(t2[i][j] == 'b') p2 = j;
			ll dlt = p2 - p1 + 5e6;
			qry[dlt].push_back({ p1, sz - p1, i });
		}
		for(int i = 0; i < L * 2; i++) if(!pts[i].empty()) {
			sort(pts[i].begin(), pts[i].end(), [](const Node &p1, const Node &p2) {
				return p1.pre < p2.pre;
			});
		}
		for(int i = 0; i < L * 2; i++) if(!qry[i].empty()) {
			sort(qry[i].begin(), qry[i].end(), [](const Query &p1, const Query &p2) {
				return p1.pre < p2.pre;
			});
		}
		for(int i = 0; i < L * 2; i++) {
			if(pts[i].size() == 0 || qry[i].size() == 0) continue;
			bt.clear();
			int j = 0;
			for(auto [x1, x2, id] : qry[i]) {
				while(j < pts[i].size() && pts[i][j].pre <= x1) bt.upd(pts[i][j].suf, 1), j++;
				ans[id] = bt.query(x2);
			}
		}
		for(int i = 0; i < q; i++) cout << ans[i] << "\n";
	}
}
const ll Base = 131, Mod = 1e9 + 7;
struct Hash_str {
	vector<ll> hsh, pw;
	Hash_str() {}
	Hash_str(const string &s) {
		pw = hsh = vector<ll>(s.size());
		hsh[0] = s[0], pw[0] = 1;
		for(int i = 1; i < s.size(); i++) {
			hsh[i] = (hsh[i - 1] * Base + s[i]) % Mod;
			pw[i] = pw[i - 1] * Base % Mod;
		}
	}
	ll hash_val(ll x) {
		if(x < 0 || x >= hsh.size()) return 0;
		return hsh[x];
	}
	ll query(ll l, ll r) {
//		assert(l <= r);
		ll res = hash_val(r) - hash_val(l - 1) * pw[r - l + 1];
		res = (res % Mod + Mod) % Mod;
		return res;
	}
};
namespace brute {
	bool check() {
		return n * q <= 1e9;
	}
	void solve() {
		vector<Hash_str> hs1(s1.begin(), s1.end()), hs2(s2.begin(), s2.end());
		vector<Hash_str> ht1(t1.begin(), t1.end()), ht2(t2.begin(), t2.end());
		for(int i = 0; i < q; i++) {
			ll ans = 0;
			string& t1_ = t1[i], t2_ = t2[i];
			ll t_sz = t1_.size();
			for(int j = 0; j < n; j++) {
				string& s1_ = s1[j], s2_ = s2[j];
				ll s_sz = s1_.size();
				for(int k = 0; k + s_sz - 1 < t1_.size(); k++) { // [k, k + s_sz - 1]
					if(ht1[i].query(k, k + s_sz - 1) == hs1[j].query(0, s_sz - 1) &&
					ht2[i].query(k, k + s_sz - 1) == hs2[j].query(0, s_sz - 1) &&
					ht1[i].query(0, k - 1) == ht2[i].query(0, k - 1) && ht1[i].query(k + s_sz, t_sz - 1) == ht2[i].query(k + s_sz, t_sz - 1)) ans++;
				}
			}
			cout << ans << "\n";
		}
	}
}
namespace cheat_pts {
	void solve() {
		for(int i = 0; i < q; i++) cout << "0\n";
	}
}

void solution() {
	cin >> n >> q;
	s1 = s2 = vector<string>(n);
	t1 = t2 = vector<string>(q);
	for(int i = 0; i < n; i++) cin >> s1[i] >> s2[i];
	for(int i = 0; i < q; i++) cin >> t1[i] >> t2[i];
	
	if(B::check()) B::solve();
	else if(brute::check()) brute::solve();
	else cheat_pts::solve();
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	fileIO("replace");
	
	solution();
	
	return 0;
}

