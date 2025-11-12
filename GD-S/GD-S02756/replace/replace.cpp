#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <tuple>

const int N = 2e5 + 7, S = 5e6 + 7, C = 26;

//i64 pow1[S]; u64 pow2[S];
//void init() {
//	pow1[0] = pow2[0] = 1;
//	for(int i = 1; i < S; ++i) {
//		pow1[i] = pow1[i-1] * base1 %MOD;
//		pow2[i] = pow2[i-1] * base2;
//	}
//}
//
//struct haxi {
//	i64 h1; u64 h2;
//	haxi(char c) {
//		h1 = c ^ 0x17, h2 = c ^ 0x63;
//	}
//};
//inline haxi operator| (const haxi& x, char c) {
//	haxi y(c);
//	y.h1 = (x.h1 * base1 + y.h1) %MOD;
//	y.h2 = (x.h2 * base2 + y.h2);
//	return y;
//}
//inline haxi operator<< (const haxi& x, int k) { return { x.h1 * pow1[k] %MOD, x.h2 * pow2[k] }; }
//inline haxi operator+ (const haxi& x, const haxi& y) { return { (x.h1 + y.h1) %MOD, x.h2 + y.h2 }; }
//inline haxi operator- (const haxi& x, const haxi& y) { return { (x.h1 - y.h1 + MOD) %MOD, x.h2 - y.h2 }; }

namespace wyx {

struct acAuto {
	int next[S][C], fail[S], dep[S], jump[S];
	std::basic_string<int> end[S];
	// std::basic_string<int> g[N];
	int idx = 1;

	inline void insert(const std::string& str, int x) {
		int p = 1;
		for(auto& c: str) {
			int t = c - 'a';
			p = next[p][t] ? next[p][t] : next[p][t] = ++idx;
		}
		end[p] += x;
	}

	std::queue<int> q;
	void dfs() {
		// assume fail[u] is already known	
		while(!q.empty()) {
			int u = q.front(); q.pop();
			for(int i = 0; i < C; ++i) {
				int& v = next[u][i];
				if(v) {
					fail[v] = fail[u];
					while(fail[v] != 1 && !next[fail[v]][i]) {
						fail[v] = fail[fail[v]];
					}
					fail[v] = next[fail[v]][i] ? next[fail[v]][i] : 1;
					dep[v] = dep[u] + 1;
					q.push(v);
				}
			}
		}
	}

	int dfs2(int u) {
		if(jump[u]) return jump[u];
		return jump[u] = end[u].empty() ? dfs2(fail[u]) : u;
	}

	void build() {
		for(int i = 1; i <= idx; ++i) {
			if(end[i].size() > 1) std::sort(end[i].begin(), end[i].end());
		}
		for(int i = 0; i < C; ++i) {
			int v = next[1][i];
			if(v) {
				fail[v] = 1;
				dep[v] = 1;
				q.push(v);
			}
		}
		dfs();
		jump[1] = 1;
		for(int i = 2; i <= idx; ++i) {
			jump[i] = dfs2(i);
		}
	}
} ac1, ac2;

int n, q;
std::string s1[N], s2[N];
int cq;
// struct __query {int x, y, len, id; } query[S];

typedef std::basic_string<int> array;
inline int calc(const array& a, const array& b) {
	if(a.empty() || b.empty()) return 0;
	int j = 0, res = 0;
	for(int i = 0; i < (int)a.size(); ++i) {
		while(j < (int)b.size() && b[j] < a[i]) {
			++j;
		}
		if(b[j] == a[i]) ++res;
	}
	return res;
}

inline int query_(int p1, int p2, int len) {
	int res = 0;
	while(ac1.dep[p1] >= len && ac2.dep[p2] >= len) {
		if(ac1.dep[p1] == ac2.dep[p2]) {
			res += calc(ac1.end[p1], ac2.end[p2]);
			p1 = ac1.jump[ac1.fail[p1]];
			p2 = ac2.jump[ac1.fail[p2]];
		} else
		if(ac1.dep[p1] > ac2.dep[p2]) {
			p1 = ac1.jump[ac1.fail[p1]];
		} else 
		if(ac2.dep[p2] > ac1.dep[p1]) {
			p2 = ac2.jump[ac2.fail[p2]];
		}
	}
	return res;
}

int query(const std::string& t1, const std::string& t2, int id=0) {
	// run on ac automachine
	//for(int i = 0; i < (int)t1.size(); ++i) {
	//	p1[i] = p1[i-1] | t1[i];
	//	p2[i] = p2[i-1] | t2[i];
	//}
	int l = 0, r = (int)t1.size() - 1; // the leftest/rightest invalid position
	while(t1[l] == t2[l]) ++l;
	while(t1[r] == t2[r]) --r;
	//auto check = [](int i, int p) {
	//	// check if string[i] is valid when its end is at position p
	//	int L = p - len[i] + 1, R = p;
	//	return R >= r && L <= l && h2[R] - (L ? h2[L-1] << (R - L + 1) : (haxi){0, 0}) == h2[i];
	//};
	//auto checkac = [](int p, int post) {
	//	int res = 0;
	//	for(auto& i: ac.end[p]) {
	//		if(check(i, post)) ++res;
	//	}
	//	return res;
	//};
	int p1 = 1, p2 = 1, ans = 0;
	for(int i = 0; i < (int)t1.size(); ++i) {
		int c1 = t1[i] - 'a', c2 = t2[i] - 'a';
		while(p1 != 1 && !ac1.next[p1][c1]) { p1 = ac1.fail[p1]; }
		while(p2 != 1 && !ac2.next[p2][c2]) { p2 = ac2.fail[p2]; }
		if(ac1.next[p1][c1]) p1 = ac1.next[p1][c1];
		if(ac2.next[p2][c2]) p2 = ac2.next[p2][c2];
		// std::cerr << "query " << i << ' ' << p1 << ' ' << p2 << "\n";
		if(i >= r) ans += query_(p1, p2, i - l + 1);
	}
	return ans;
}

inline void main() {
	std::cin >> n >> q;
	for(int i = 1; i <= n; ++i) {
		std::cin >> s1[i] >> s2[i];	
		ac1.insert(s1[i], i), ac2.insert(s2[i], i);
		// init_hash(s1[i], h1[i]), init_hash(s2[i], h2[i]);
	}
	ac1.build(), ac2.build();
	std::string t1, t2;
	for(int i = 1; i <= q; ++i) {
		std::cin >> t1 >> t2;
		std::cout << query(t1, t2) << "\n";
	}
}

};


int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	// init();
	wyx::main();
}
