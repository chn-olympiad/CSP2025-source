#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int a1[MAXN], a2[MAXN], a3[MAXN], gx[10], t1, t2, t3, idx1, idx2, idx3;
map<int, int> mp; 
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n, ans = 0, cnt = 0;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a1[i] >> a2[i] >> a3[i];
		}
		sort(a1 + 1, a1 + n + 1);
		for (int i = n; i >= 1; --i) {
			if (cnt < n / 2) {
				ans += a1[i];
				cnt++;
			}
			
		}
		cout << ans << '\n';
	}
	return 0;
}
