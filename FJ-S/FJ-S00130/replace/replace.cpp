#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
struct node {
	int x, y, z, zz;
	bool operator < (const node &o) const {
		if (x != o.x) return x < o.x;
		if (y != o.y) return y < o.y;
		return zz < o.zz;
	}
} c[maxn];
map<int, int> m;
string s1[maxn], s2[maxn], t1, t2;
int n, q, aa, bb, cc, dd, a[maxn], b[maxn];
int main() {
	freopen("replace4.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) cin >> s1[i] >> s2[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < s1[i].size(); j++) {
			if (s1[i][j] == 'b') a[i] = j;
		}
		for (int j = 0; j < s2[i].size(); j++) {
			if (s2[i][j] == 'b') b[i] = j;
		}
		c[i].x = a[i] - b[i], c[i].y = a[i], c[i].z = i, c[i].zz = s1[i].size() - a[i] - 1;
	}
	sort(c + 1, c + n + 1);
	while (q--) {
		cin >> t1 >> t2;
		cout << 0 << endl;
		continue;
		if (t1.size() != t2.size()) {
			puts("0");
			continue;
		}
		aa = bb = 0;
		for (int i = 0; i < t1.size(); i++) {
			if (t1[i] == 'b') aa = i;
		}
		for (int i = 0; i < t2.size(); i++) {
			if (t2[i] == 'b') bb = i;
		}
		int l = 1, r = n;
		while (l < r) {
			int mid = l + r >> 1;
			if (c[mid].x < aa - bb) l = mid + 1;
			else r = mid;
		}
		cc = l;
		l = 1, r = n + 1;
		while (l < r) {
			int mid = l + r >> 1;
			if (c[mid].x <= aa - bb) l = mid + 1;
			else r = mid;
		}
		dd = l - 1;
		if (c[cc].x != aa - bb || c[dd].x != aa - bb) {
			puts("0");
			continue;
		}
		l = cc, r = dd + 1;
		while (l < r) {
			int mid = l + r >> 1;
			if (c[mid].y < aa) l = mid + 1;
			else r = mid;
		}
		dd = l;
		l = cc, r = dd + 1;
		while (l < r) {
			int mid = l + r >> 1;
			if (c[mid].zz < bb) l = mid + 1;
			else r = mid;
		}
		dd = l;
		printf("%d\n", dd - cc + 1);
		if (dd - cc + 1 == 5) {
			cout << t1 << " " << t2 << endl;
			cout << aa - bb << endl;
			cout << t1.size() << endl;
			for (int i = cc; i <= dd; i++) {
				cout << c[i].y << " ";
				cout << s1[c[i].z] << " " << s2[c[i].z] << endl;
			}
			cout << endl;
		}
	}
	return 0;
}
/*
1 10
aba baa
aaba abaa
*/
