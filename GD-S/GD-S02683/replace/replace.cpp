#include <iostream>
#include <vector>
#include <limits>

#define repm(i, begin, end) for (int i = begin; i < end; i += 1)
#define rep(i, n) repm(i, 0, n)
#define repi(i, begin, end) for (int i = begin; i <= end; i += 1)
#define rep1(i, n) repi(i, 1, n)

using namespace std;
using llu = long long unsigned;

const bool debugm = true;

template<typename... Args>
void debug(const Args... arg) {
	if (debugm) {
		(int[]) {
			(void(cout << arg << " "), 0)
			... 
		};
		
		cout << endl;
	}
}

void set_io() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
}

struct rule {
	string s, t;
	size_t len = 0;
	int feq = 0;
};

int main() {
	set_io();
	
	int n, q;
	cin >> n >> q;
	
	vector<rule> rules(n);
	rep(i, n) {
		cin >> rules[i].s >> rules[i].t;
		rules[i].len = rules[i].s.size();
		
		rep(j, rules[i].len) {
			if (rules[i].s[j] != rules[i].t[j]) break;
			rules[i].feq += 1;
		}
	}
	
	string s, t;
	rep(_, q) {
		cin >> s >> t;
		
		llu ans = 0;
		for (auto r: rules) {
			int p = 0;
			bool flag = true;
			
			rep(i, r.len) {
				if (s[i] == r.s[p] && t[i] == r.t[p]) {
					p += 1;
					if (p >= r.s.size()) p = 0;
				} else if (s[i] == t[i] && p <= r.feq) {
					p = 0;
				} else {
					flag = false;
					break;
				}
			}
			
			if (flag && p == 0) {
				ans += 1;
			}
		}
		
		cout << ans << endl;
	}
	
	return 0;
}
