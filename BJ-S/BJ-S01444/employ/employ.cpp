#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

const int P = 998244353;

namespace bf {
	void solve(int n, int m, vector<bool> s) {
		vector<int> c;
		vector<int> p;
		for (int i = 0; i < n; i ++ ) {
			int x;
			cin >> x;
			c.push_back(x);
			p.push_back(i);
		}
		int ans = 0;
		do {
			int e = 0, r = 0; // employ or reject count
			for (int i = 0; i < n; i ++ ) {
				if (s[i]) {
					if (c[p[i]] > r) e ++ ;
					else r ++ ;
				} else r ++ ;
			}
			if (e >= m) {
				ans ++ ;
				/*for (auto pp : p) cout << pp << ' ';
				cout << endl;*/
			}
		} while (next_permutation(p.begin(), p.end()));
		cout << ans << endl;
	}
}

namespace perm {
	void solve(int n) {
		LL ans = 1;
		for (int i = 1; i <= n; i ++ ) {
			ans *= i;
			ans %= P;
		}
		cout << ans << endl;
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<bool> s;
	bool flag = true;
	for (int i = 0; i < n; i ++ ) {
		char c;
		cin >> c;
		if (c == '1') s.push_back(1);
		else s.push_back(0), flag = false;
	}
	//if (flag) perm::solve(n);
	//else
	 bf::solve(n, m, s);
}
