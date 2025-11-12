#include<bits/stdc++.h>
using namespace std; 
#define endl '\n'
#define LL long long
#define fer(i, a, b, args...) for(int i = (a), ##args; i <= (b); i ++)
#define fel(i, a, b, args...) for(int i = (a), ##args; i >= (b); i --)
template <typename T> void chmin(T &x, T y) { if(y < x) x = y; }
template <typename T> void chmax(T &x, T y) { if(y > x) x = y; }
#define fi first
#define se second 
constexpr int N = 2e5 + 10; 
int n, q; 
struct tire {
	struct node {
		node *(to[26]); 
		int cnt; 
		node() {
			fer(i, 0, 25) to[i] = nullptr; 
			cnt = 0; 
		}
	} root; 
	void insert(string const &a) {
		node *p = &root; 
		for(int i = 0; i < a.size(); i ++) {
			auto &to = p->to[a[i] - 'a']; 
			if(to == nullptr) to = new node; 
			p = to; 
		}
		p->cnt ++; 
	}
	int query(string const &a) {
		node *p = &root; 
		int ans = p->cnt; 
		for(int i = 0; i < a.size(); i ++) {
			auto &to = p->to[a[i] - 'a']; 
			if(to == nullptr) break; 
			p = to; 
			ans += p->cnt; 
		}
		return ans; 
	}
}; 
struct tireoftire {
	struct node {
		node *(to[26]); 
		tire x; 
		node() {
			fer(i, 0, 25) to[i] = nullptr; 
		}
	} root; 
	void insert(string const &a, string const &b) {
		node *p = &root; 
		for(int i = 0; i < a.size(); i ++) {
			auto &to = p->to[a[i] - 'a']; 
			if(to == nullptr) to = new node; 
			p = to; 
		}
		p->x.insert(b); 
	}
	int query(string const &a, string const &b) {
		node *p = &root; 
		int ans = p->x.query(b); 
		for(int i = 0; i < a.size(); i ++) {
			auto &to = p->to[a[i] - 'a']; 
			if(to == nullptr) break; 
			p = to; 
			ans += p->x.query(b); 
		}
		return ans; 
	}
}; 
map <pair<string, string>, tireoftire> g; 
signed main() {
	// freopen("replace4.in", "r", stdin); 
	freopen("replace.in", "r", stdin); 
	freopen("replace.out", "w", stdout); 
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0); 
	cin >> n >> q; 
	map<pair<string, string>, bool> f; 
	string a, b; 
	fer(i, 1, n) {
		cin >> a >> b; 
		if(a == b) continue; 
		int k = a.size(); 
		int l = -1, r = -1; 
		fer(i, 0, k - 1) {
			if(a[i] != b[i]) {
				if(l == -1) l = i; 
				r = i; 
			}
		}
		string t = a.substr(0, l); 
		reverse(t.begin(), t.end());
		g[{a.substr(l, r - l + 1), b.substr(l, r - l + 1)}].insert(t, a.substr(r + 1, k - r - 1)); 
	}
	fer(cases, 1, q) {
		cin >> a >> b; 
		int k = a.size(); 
		int l = -1, r = -1; 
		fer(i, 0, k - 1) {
			if(a[i] != b[i]) {
				if(l == -1) l = i; 
				r = i; 
			}
		}
		string t = a.substr(0, l); 
		reverse(t.begin(), t.end());
		cout << g[{a.substr(l, r - l + 1), b.substr(l, r - l + 1)}].query(t, a.substr(r + 1, k - r - 1)) << endl; 
	}
	return 0; 
}
//666ACzidongjizenmedalaizhe?