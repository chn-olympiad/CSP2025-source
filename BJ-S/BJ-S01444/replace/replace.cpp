#include <iostream>
#include <cstring>
#include <string>

using namespace std;

namespace subB {
	const int N = 1e7 + 10;
	const int M = 5e6 + 5;

	int h[N], ne[M], e[M], f[M], idx;

	void add(int u, int v, int w) {
		e[idx] = v;
		f[idx] = w;
		ne[idx] = h[u];
		h[u] = idx ++ ;
	}

	int find(string s) {
		for (int i = 0; i < (int)s.size(); i ++ ) {
			if (s[i] == 'b') return i;
		}
		return 0;
	}
	
	void solve(int n, int q) {
		memset(h, -1, sizeof h);
		while (n -- ) {
			string a, b;
			cin >> a >> b;
			int L = a.size();
			int fa = find(a), fb = find(b);
			add(fa - fb + M, min(fa, fb), L - max(fa, fb));
		}
		while (q -- ) {
			string a, b;
			cin >> a >> b;
			int L = a.size();
			int fa = find(a), fb = find(b);
			int ans = 0;
			for (int i = h[fa - fb + M]; ~i; i = ne[i]) {
				if (e[i] <= min(fa, fb) && f[i] <= L - max(fa, fb)) ans ++ ;
			}
			cout << ans << endl;
		}
	}
}

namespace sub1 {
	const int N = 110;
	string a[N], b[N];
	void solve(int n, int q) {
		for (int i = 0; i < n; i ++ ) cin >> a[i] >> b[i];
		while (q -- ) {
			string p, q;
			cin >> p >> q;
			if (p.size() != q.size()) {
				cout << 0 << endl;
				continue;
			}
			int ans = 0;
			for (int i = 0; i < n; i ++ ) {
				for (int j = 0; j < (int)p.size() - (int)a[i].size() + 1; j ++ ) {
					bool flag = true;
					for (int k = j; k < j + (int)a[i].size(); k ++ ) {
						if (a[i][k - j] != p[k]) {
							flag = false;
							break;
						}
					}
					if (flag) {
						string r = p;
						for (int k = j; k < j + (int)a[i].size(); k ++ ) {
							r[k] = b[i][k - j];
						}
						if (r == q) ans ++ ;
					}
				}
			}
			cout << ans << endl;
		}
	}
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	if (n <= 100 && q <= 100) sub1::solve(n, q);
	else subB::solve(n, q);
}
