#include <bits/stdc++.h>
using namespace std;
int p[200005];
int n, q;
struct ss {
	string x, y;
	int h1, h2;
} s[200005];
int h1[5000006], h2[5000006];
bool operator < (ss x, ss y) {
	return x.x.size() < y.x.size();
}
string t1, t2;
int fast_io = [](){
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	return 0;
}();
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i].x >> s[i].y;
		for (int j = 0; j < s[i].x.size(); j++) {
			s[i].h1 = s[i].h1 * 13331 + s[i].x[j];
			s[i].h2 = s[i].h2 * 13331 + s[i].y[j];
		}
	}
	sort(s + 1, s + 1 + n);
	p[0] = 1;
	for (int i = 1; i <= 200000; i++) {
		p[i] = p[i - 1] * 13331;
	}
	while (q--) {
		long long ans = 0;
		cin >> t1 >> t2;
		if (t1.size() ^ t2.size()) {
			cout << "0\n";
			continue;
		}
		for (int i = 1; i <= t1.size(); i++) {
			h1[i] = h1[i - 1] * 13331 + t1[i - 1];
			h2[i] = h2[i - 1] * 13331 + t2[i - 1];
		}
		int dl = 0, dr = t1.size();
		for (int i = 0; i < t1.size(); i++) {
			if (t1[i] != t2[i]) {
				dl = i;
				break;
			}
		}
		for (int i = t1.size() - 1; i >= 0; i--) {
			if (t1[i] != t2[i]) {
				dr = i;
				break;
			}
		}
		//cout << dl << ' ' << dr << '\n';
		int l = 0, r = n + 1;
		while (l + 1 < r) {
			int mid = (l + r) >> 1;
			if (s[mid].x.size() <= dr - dl) l = mid;
			else r = mid;
		}
		//cout << r << endl;
		for (int i = r; i <= n; i++) {
			int m = s[i].x.size();
			for (int j = max(0, dr - m + 1); j <= min(dl, int(t1.size() - m)); j++) {
				//cout << s[i].x << ' ' << s[i].y << '\n';
				if (h1[j + m] - h1[j] * p[m] != s[i].h1) continue;
				if (h2[j + m] - h2[j] * p[m] != s[i].h2) continue;
				ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
