#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fir first
#define sec second

bool ST;

const int N = 2e5 + 5, M = 5e6 + 5;
int n, q;
struct element { string s, t; };

const int H1 = 131, mod1 = (1e4 + 5e4 + 1919810) * 233 + 19;
const int H2 = 31, mod2 = 998244353;
struct has { int x, y; } f[M];
void add(has &a, char c) {
	a.x = (a.x * H1 + c) % mod1,
	a.y = (a.y * H2 + c) % mod2;
}
bool same(has a, has b) {
	return (a.x == b.x && a.y == b.y);
}
void output(has x) {
	cout << x.x << " " << x.y;
}
const int mod = 1e18 + 7;
pii merge(has a, has b, has c) {
	int res1 = a.x;
	res1 = (res1 * H1 + a.y) % mod1;
	res1 = (res1 * H1 + b.x) % mod1;
	res1 = (res1 * H1 + b.y) % mod1;
	res1 = (res1 * H1 + c.x) % mod1;
	res1 = (res1 * H1 + c.y) % mod1;
	int res2 = a.x;
	res2 = (res2 * H2 + a.y) % mod;
	res2 = (res2 * H2 + b.x) % mod;
	res2 = (res2 * H2 + b.y) % mod;
	res2 = (res2 * H2 + c.x) % mod;
	res2 = (res2 * H2 + c.y) % mod;
	return {res1, res2};
}

struct element2 {
	has fir;
	int sec, id;
};
map<pii, vector<element2>> mp;

bool ED;

void solve() {
//	mp2[merge({1, 2}, {1, 2}, {1, 2})] ++;
//	cout << mp2[merge({1, 2}, {1, 2}, {1, 2})] << endl;
	cin >> n >> q;
	for(int i = 1; i <= n; i ++) {
		element x;
		cin >> x.s >> x.t;
		if(x.s == x.t) { continue; }
		int len = x.s.size();
		has pre = {0, 0}, suf = {0, 0};
		int l = -1, r = len;
		for(int j = 0; j < len; j ++) {
			if(x.s[j] != x.t[j]) { break; }
			l = j;
		}
		for(int j = l; j >= 0; j --) { add(pre, x.s[j]); }
		for(int j = len - 1; j >= 0; j --) {
			if(x.s[j] != x.t[j]) { break; }
			r = j;
		}
		for(int j = r; j < len; j ++) { add(suf, x.s[j]); }
//		cout << "- " << l << " " << r << endl;
		has midx = {0, 0}, midy = {0, 0};
		for(int j = l + 1; j < r; j ++) {
			add(midx, x.s[j]), add(midy, x.t[j]);
		}
		element2 tmp = {suf, len - r, i};
//		output(midx), cout << endl;
//		output(midy), cout << endl;
//		output(pre), cout << endl;
//		output(suf), cout << endl;
		mp[merge(midx, midy, pre)].push_back(tmp);
	}
	for(int id = 1, res = 0; q --; id ++) {
		res = 0;
		element e;
		cin >> e.s >> e.t;
		if(e.s.size() != e.t.size()) {
			cout << 0 << endl; continue;
		}
		int l = -1, r = e.s.size();
		for(; l + 1 < e.s.size() && e.s[l + 1] == e.t[l + 1]; l ++);
		for(; r - 1 >= 0 && e.s[r - 1] == e.t[r - 1]; r --);
//		cout << "- " << l << " " << r << endl;
		has midx = {0, 0}, midy = {0, 0};
		for(int j = l + 1; j < r; j ++) {
			add(midx, e.s[j]), add(midy, e.t[j]);
		}
//		output(midx), cout << endl;
//		output(midy), cout << endl;
		has pre = {0, 0};
		for(int j = r; j < e.s.size(); j ++) {
			f[j - r + 1] = f[j - r];
			add(f[j - r + 1], e.s[j]);
		}
		for(int j = l; j >= -1; j --) {
//			output(pre), cout << endl;
			vector<element2>& vec = mp[merge(midx, midy, pre)];
//			cout << "++ " << mp2[(element2){midx, midy, pre}] << endl;
			if(vec.size()) {
				for(element2 x : vec) {
	//				cout << "-- ";
	//				output(x.fir), cout << endl;
	//				cout << x.sec << " ", output(f[x.sec]), cout << endl;
//					if(id == 457) {
//						cout << "---- " << e.s.size() - r << " " << x.sec << endl;
//						output(x.fir), cout << endl;
//						output(f[x.sec]), cout << endl;
//						cout << "- " << x.id << endl;
//					}
					res += (x.sec <= e.s.size() - r && same(x.fir, f[x.sec]));
				}
			}
//			cout << "- " << vec.size() << endl;
			if(j == -1) { break; }
			add(pre, e.s[j]);
		}
		cout << res << endl;
	}
}
void init() {

}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int cas = 1; // cin >> cas;
	for(; cas --; ) { init(), solve(); }
	return 0;
}
