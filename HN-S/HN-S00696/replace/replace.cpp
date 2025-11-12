#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5, M = 5e6 + 5;

struct S {
	string s, t;
} a[N], b[N];

int n, q, flag, h[2], id[2][M], tr[M], ans[N], mx, idtot[2];
 
void D(string s) {
	int o = 0;
	mx = max(mx, (int)s.size());
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != 'a' && s[i] != 'b') {
			flag = 1;
		}
		if (s[i] == 'b') {
			o++; 
		}
	}
	if (o != 1) {
		flag = 1;
	}
}

struct A {
	int x, y, z;
} ;

vector<A> c[2][N];

int lowbit(int x) {
	return (x & (-x));
}

void add(int x, int o) {
	x++;
	for (int i = x; i <= mx; i += lowbit(i)) {
		tr[i] += o;
	}
}

int query(int x) {
	int ans = 0;
	x++;
	for (int i = x; i; i -= lowbit(i)) {
		ans += tr[i];
	}
	return ans;
}

bool cmp(A X, A Y) {
	if (X.x != Y.x) {
		return X.x < Y.x;
	}
	if (X.y != Y.y) {
		return X.y < Y.y;
	}
	return X.z < Y.z;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].s >> a[i].t;
		D(a[i].s), D(a[i].t);
	}
	for (int i = 1; i <= q; i++) {
		cin >> b[i].s >> b[i].t;
		D(b[i].s), D(b[i].t);
	} 
	mx++;
	if (flag) {
		map<pair<string, string>, int> mp;
		for (int i = 1; i <= n; i++) {
			mp[{a[i].s, a[i].t}]++;
		}
		for (int i = 1; i <= q; i++) {
			string s = b[i].s;
			string t = b[i].t;
			if ((int)s.size() != (int)t.size()) {
				cout << 0 << "\n";
				continue;
			}
			int len = (int)s.size(), l = 0, r = (int)s.size();
			for (int j = 0; j < len; j++) {
				if (s[j] != t[j]) {
					l = j;
					break;
				}
			}
			for (int j = len - 1; j >= 0; j--) {
				if (s[j] != t[j]) {
					r = j;
					break;
				}
			}
			int ans = 0;
			for (int j = 0; j <= l; j++) {
				for (int e = r; e < len; e++) {
					string o = s.substr(j, e - j + 1);
					string x = t.substr(j, e - j + 1);
					ans += mp[{o, x}];
				}
			}
			cout << ans << "\n"; 
		}
		return 0;
	}
	int ooo = 0;
	for (int i = 1; i <= n; i++) {
		string s = a[i].s;
		string t = a[i].t;
		int len = a[i].s.size(), l = len, r = -1;
		for (int j = 0; j < len; j++) {
			if (s[j] != t[j]) {
				l = j;
				break;
			}
		}
		for (int j = len - 1; j >= 0; j--) {
			if (s[j] != t[j]) {
				r = j;
				break;
			}
		}
		if (l == len) {
			ooo++;
			continue;
		}
		int o = (s[l] == 'a');
		int cnt = r - l;
		if (!id[o][cnt]) {
			id[o][cnt] = ++idtot[o];
		}
		cnt = id[o][cnt];
		r = len - r - 1;
		c[o][cnt].push_back({l, r, 0});
	}
	for (int i = 1; i <= q; i++) {
		string s = b[i].s;
		string t = b[i].t;
		int len = s.size(), l = len, r = -1;
		for (int j = 0; j < len; j++) {
			if (s[j] != t[j]) {
				l = j;
				break;
			}
		}
		for (int j = len - 1; j >= 0; j--) {
			if (s[j] != t[j]) {
				r = j;
				break;
			}
		}
		int o = (s[l] == 'a');
		int cnt = r - l;
		if (!id[o][cnt]) {
			id[o][cnt] = ++idtot[o];
		}
		cnt = id[o][cnt];
		r = len - r - 1;
		c[o][cnt].push_back({l, r, i});
	}
//	cout << ooo << " ";
	for (int o = 0; o < 2; o++) {
		for (int i = 1; i <= idtot[o]; i++) {
//			cout << c[o][i].size() << " "; 
			sort(c[o][i].begin(), c[o][i].end(), cmp);
			for (int j = 0; j < c[o][i].size(); j++) {
				A cur = c[o][i][j];
//				cout << cur.y << " " << cur.z << "\n"; 
				if (cur.z) {
					ans[cur.z] = query(cur.y);
				} else {
					add(cur.y, 1);
				}
			}
			for (int j = 0; j < c[o][i].size(); j++) {
				A cur = c[o][i][j];
				if (cur.z == 0) {
					add(cur.y, -1);
				}
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}
