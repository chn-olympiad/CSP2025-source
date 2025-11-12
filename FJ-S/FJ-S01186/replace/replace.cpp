#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct node {
	string s1, s2;	
}a[N];
 
int find1(string t1, string t2, int len) {
	int i;
	for (i = 0; i < len; i++) {
		if (t1[i] != t2[i]) return i;
	}
	return i;
}

int find2(string t1, string t2, int len) {
	int i;
	for (i = len - 1; i >= 0; i--) {
		if (t1[i] != t2[i]) return i;
	}
	return i;
} 
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].s1 >> a[i].s2;
	}
	while (q--) {
		long long ans = 0;
		string t1, t2;
		cin >> t1 >> t2;
		int len = t1.size();
		int l = find1(t1, t2, len);
		int r = find2(t1, t2, len);
 		if (r < l) {
			for (int i = 1; i <= n; i++) {
				int len1 = (a[i].s1).size();
				if (a[i].s1 == a[i].s2 && len1 <= len) {
					ans += (len - len1);
				}
			}
			cout << ans << endl;
		} else {
			int res = r - l + 1;
			for (int i = 1; i <= n; i++) {
				int len1 = (a[i].s1).size();
				if (len1 < res || len1 > len) continue;
				for (int j = max(0, r - len1 + 1); j + len1 <= len && j <= l; j++){
					bool flag = 1;
					for (int k = j; k <= j + len1 - 1; k++) {
						if (a[i].s1[k] != t1[k] || a[i].s2[k] != t2[k]) {
							flag = 0;
							break;
						}
					}
					if (flag) ans++;
				}
			}
			cout << ans << endl;
		}
	}
	return 0; 
}
