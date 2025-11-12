#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, ans;
struct node{
	string s1, s2;
	string suf, pre, d1, d2;
	bool operator <(const node &A) const{
		return A.d1 < d1;
	}
}p[200005];



string t1, t2, suff, pref, d1f, d2f;

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> p[i].s1 >> p[i].s2;
		bool flag = 0;
		for (int pos = 0; pos < p[i].s1.size(); pos++) {
			if (p[i].s1[pos] != p[i].s2[pos]) {
				flag = 1;
				p[i].d1 += p[i].s1[pos], p[i].d2 += p[i].s2[pos];
			}
			if (p[i].s1[pos] == p[i].s2[pos] && flag) p[i].suf += p[i].s1[pos];
			if (p[i].s1[pos] == p[i].s2[pos] && !flag) p[i].pre += p[i].s1[pos];
		}
	}
	sort(p + 1, p + n + 1);
	for (int i = 1; i <= m; i++) {
		suff = pref = d1f = d2f = "";
		ans = 0;
		cin >> t1 >> t2;
		bool flag = 0;
		for (int pos = 0; pos < t1.size(); pos++) {
			if (t1[pos] != t2[pos]) {
				flag = pos;
				d1f += t1[pos], d2f += t2[pos];
			}
			if (t1[pos] == t2[pos] && flag) suff += t1[pos];
			if (t1[pos] == t2[pos] && !flag) pref += t1[pos];
		}
		int pos = 0, l = 0, r = n;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (p[mid].d1 < d1f) l = mid + 1;
			else pos = mid, r = mid - 1;
		}
		for (int j = pos; j <= n; j++) {
			if (d1f != p[j].d1) break;
			if (d2f > p[j].d2) break;
			if (d2f == p[j].d2) {
				bool f1 = 0, f2 = 0;
				for (int k = p[j].pre.size() - 1; k >= 0; k--) {
					if (pref[pref.size() - p[j].pre.size() + k] != p[j].pre[k]) f1 = true; break;
				}
				
				for (int k = 0; k < p[j].suf.size(); k++) {
					if (suff[k] != p[j].suf[k]) f2 = true; break;
				}
				if (!f1 && !f2) ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}