#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int a[N][5], cnt[5];
struct S{
	int d, m1, m2, p1, p2;
}s[N];
bool cmp(S x, S y) { return x.d > y.d; }
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while(T--) {
		memset(cnt, 0, sizeof cnt);
		int n; cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			int m1 = 0, id1 = 0, m2 = 0, id2 = 0;
			for (int j = 1; j <= 3; ++j) {
				if (m1 <= a[i][j]) {
					m2 = m1, id2 = id1;
					m1 = a[i][j], id1 = j;
				} else if (m2 < a[i][j]) {
					m2 = a[i][j], id2 = j;
				}
			}
			s[i].d = m1 - m2;
			s[i].m1 = m1, s[i].p1 = id1;
			s[i].m2 = m2, s[i].p2 = id2; 
		}
		sort(s+1, s+1+n, cmp);
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			if (cnt[s[i].p1] < n/2) ans += s[i].m1, cnt[s[i].p1]++;
			else ans += s[i].m2, cnt[s[i].p2]++;
		}
		cout << ans << "\n";
	}
	return 0;
}
