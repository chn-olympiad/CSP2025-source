#include <bits/stdc++.h>
using namespace std;

int n, q;

string s1[200010], s2[200010];
string t1, t2;

int pre[5000010], suf[5000010];

//struct node{
//	int x, y, id;
//};
//vector<node> tmp[5000010];
//int ans[200010];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
	}
	if (n <= 1000 && q <= 2000) {
		while (q--) {
			cin >> t1 >> t2;
			if (t1.size() != t2.size()) {
				printf("0\n");
				continue;
			}
			for (int i = 0; i < t1.size(); i++) pre[i] = (i == 0 || pre[i-1]) && (t1[i]==t2[i]);
			for (int i = t1.size()-1; i >= 0; i--) suf[i] = (i == t1.size()-1 || suf[i+1]) && (t1[i]==t2[i]);
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				bool flg0 = 0;
				for (int j = 0; j+s1[i].size()-1 < t1.size(); j++) {
					if ((j != 0 && !pre[j-1]) || (j+s1[i].size() != t1.size() && !suf[j+s1[i].size()])) continue;
					bool flg = 1;
					for (int k = 0; k < s1[i].size(); k++) {
						if (s1[i][k] != t1[j+k] || s2[i][k] != t2[j+k]) {
							flg = 0;
							break;
						}
					}
					if (flg) {
						flg0 = 1;
						break;
					}
				}
				if (flg0) ans++;
			}
			printf("%d\n", ans);
		}
		return 0;
	}
//	int maxv = 0;
//	for (int i = 1; i <= n; i++) {
//		int fir = 0x3f3f3f3f, lst = -0x3f3f3f3f;
//		for (int j = 0; j < s1[i].size(); j++) {
//			if (s1[i][j] != s2[i][j]) {
//				fir = min(fir, j);
//				lst = max(lst, j);
//			}
//		}
//		if (fir < lst) tmp[lst-fir+1].push_back({fir-1, s1[i].size()-lst, 0}), maxv = max(maxv, lst-fir+1);
//	}
//	for (int i = 1; i <= q; i++) {
//		cin >> t1 >> t2;
//		int fir = 0x3f3f3f3f, lst = -0x3f3f3f3f;
//		if (t1.size() != t2.size()) {
//			ans[i] = 0;
//			continue;
//		}
//		for (int j = 0; j < t1.size(); j++) {
//			if (t1[j] != t2[j]) {
//				fir = min(fir, j);
//				lst = max(lst, j);
//			}
//		}
//		if (fir < lst) tmp[lst-fir+1].push_back({fir-1, t1.size()-lst, 0}), maxv = max(maxv, lst-fir+1);
//	}
//	for (int i = 1; i <= maxv; i++) {
//		if (tmp[i].empty()) continue;
//		sort(tmp[i].begin(), tmp[i].end(), [](node a, node b) -> bool {
//			if (a.x == b.x) return a.id < b.id;
//			return a.x < b.x;
//		});
//		
//	}
}
