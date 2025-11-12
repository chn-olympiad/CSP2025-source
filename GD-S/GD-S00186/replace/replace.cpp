#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <ctime>
#include <map>
#include <unordered_map>
#include <bitset>
//#define int long long
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ull, ull> PII;
const int N = 2e5 + 10, M = 5e6 + 10, base = 13331;
bool Mst;
int n, q;
ull Hash(string s) {
	ull h = 0;
	for(int i = 0; i < s.size(); i ++)
		h = h * base + s[i];
	return h;
}
map<PII, int> h;
int idx, ans[N];
vector<int> A[N], B[N];
string pre[N], suf[N], pb[N], sb[N];
int Id(PII x) {
	if(h.count(x)) return h[x];
	return h[x] = ++ idx;
}
unordered_map<ull, int> h2;
int idx2;
int I2(ull x) {
	return (h2.count(x) ? h2[x] : h2[x] = ++ idx2);
}
bool st[N];
vector<int> all[M], all2[M];

bool Med;
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout); 
	ios::sync_with_stdio(0), cin.tie(0);
	cerr << abs(&Mst - &Med) / 1048576.0 << "Mb\n";
	clock_t stt = clock();
	cin >> n >> q;
	for(int T = 1; T <= n; T ++) {
		string a, b;
		cin >> a >> b;
		int i = 0, m = (int)a.size(), j = m - 1;
		while(i < m) {
			if(a[i] == b[i]) i ++;
			else break;
		}
		if(i == m) continue;
		while(j >= 0) {
			if(a[j] == b[j]) j --;
			else break;
		}
		for(int t = 0; t < i; t ++) pre[T].push_back(a[t]);
		for(int t = j + 1; t < m; t ++) suf[T].push_back(a[t]);
		int id = Id({Hash(a.substr(i, j - i + 1)), Hash(b.substr(i, j - i + 1))});
		A[id].push_back(T);
	}
	for(int T = 1; T <= q; T ++) {
		string a, b;
		cin >> a >> b;
		if(a.size() != b.size()) {
			cout << 0 << '\n';
			continue;
		}
		int i = 0, m = (int)a.size(), j = m - 1;
		while(i < m) {
			if(a[i] == b[i]) i ++;
			else break;
		}
		if(i == m) continue;
		while(j >= 0) {
			if(a[j] == b[j]) j --;
			else break;
		}
		int id = Id({Hash(a.substr(i, j - i + 1)), Hash(b.substr(i, j - i + 1))});
		B[id].push_back(T);
		for(int t = 0; t < i; t ++) pb[T].push_back(a[t]);
		for(int t = j + 1; t < m; t ++) sb[T].push_back(a[t]);
	}
	for(int i = 1; i <= idx; i ++) {
		for(int i = 1; i <= idx2; i ++) all[i].clear(), all2[i].clear();
		h2.clear(), idx2 = 0;
		for(auto o : A[i]) {
//			cout << i << ' ' << o << ' ' << suf[o] << ' ' << pre[o] << '\n';
			all[I2(Hash(suf[o]))].push_back(o);
			reverse(pre[o].begin(), pre[o].end());
			all2[I2(Hash(pre[o]))].push_back(o);
		}
		for(auto o : B[i]) {
//			cout << i << ' ' << o << ' ' << pb[o] << ' ' << sb[o] << '\n';
			ull hs = 0;
			for(auto t : all[I2(hs)])
				st[t] = 1;
			for(auto c : sb[o]) {
				hs = hs * base + c;
				for(auto t : all[I2(hs)])
					st[t] = 1;
			}
			hs = 0;
			int res = 0;
			reverse(pb[o].begin(), pb[o].end());
			for(auto t : all2[I2(hs)])
				res += st[t];
			for(auto c : pb[o]) {
				hs = hs * base + c;
				for(auto t : all2[I2(hs)])
					res += st[t];
			}
			hs = 0;
			for(auto t : all[I2(hs)])
				st[t] = 0;
			for(auto c : sb[o]) {
				hs = hs * base + c;
				for(auto t : all[I2(hs)])
					st[t] = 0;
			}
			ans[o] = res;
		}
	}
	for(int i = 1; i <= q; i ++) {
		cout << ans[i] << '\n';
	}
	cerr << (1.0 * clock() - stt) / CLOCKS_PER_SEC << "s\n";
	
	return 0;
}
