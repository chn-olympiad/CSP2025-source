#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e5 + 5;
int T;
vector<int> a, b, c;
int main() {
	freopen("club.in", "r" , stdin);
	freopen("club.out", "w" , stdout);
	cin >> T;
	while (T --) {
		int n, s[N][5], ans;
		cin >> n;
		memset(s, 0, sizeof(s));
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= 3; j ++) {
				cin >> s[i][j];
				a.push_back(i);
			}
		while (a.size() > n / 2) {
			int cnt = INT_MIN, id;
			for (int i = 0; i < a.size(); i ++) {
				if (s[a[i]][2] - s[a[i]][1] >= s[a[i]][3] - s[a[i]][1]) {
					if (s[a[i]][2] - s[a[i]][1] >= cnt) {
						id = i;
						cnt = s[a[i]][2] - s[a[i]][1];
					}
				}
				else {
					if (s[a[i]][3] - s[a[i]][1] >= cnt) {
						id = i;
						cnt = s[a[i]][3] - s[a[i]][1];
					}
				}
			}
		}
		while (a.size() > n / 2) {
			int cnt = INT_MIN, id;
			for (int i = 0; i < a.size(); i ++) {
				if (s[a[i]][2] - s[a[i]][1] >= s[a[i]][3] - s[a[i]][1]) {
					if (s[a[i]][2] - s[a[i]][1] >= cnt) {
						id = i;
						cnt = s[a[i]][2] - s[a[i]][1];
					}
				}
				else {
					if (s[a[i]][3] - s[a[i]][1] >= cnt) {
						id = i;
						cnt = s[a[i]][3] - s[a[i]][1];
					}
				}
			}
		}
		while (a.size() > n / 2) {
			int cnt = INT_MIN, id;
			for (int i = 0; i < a.size(); i ++) {
				if (s[a[i]][2] - s[a[i]][1] >= s[a[i]][3] - s[a[i]][1]) {
					if (s[a[i]][2] - s[a[i]][1] >= cnt) {
						id = i;
						cnt = s[a[i]][2] - s[a[i]][1];
					}
				}
				else {
					if (s[a[i]][3] - s[a[i]][1] >= cnt) {
						id = i;
						cnt = s[a[i]][3] - s[a[i]][1];
					}
				}
			}
		}
		cout << ans;
	}
	return 0;
}

