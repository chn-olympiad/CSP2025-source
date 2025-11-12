#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int MAXN = 1e5 + 10;
int n, a[MAXN][3], t[MAXN];
inline void solve() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
	int c1 = 0, c2 = 0, c3 = 0, wh = -1;
	ll cur = 0;
	for(int i = 1; i <= n; i++) {
		int mx = max(a[i][0], max(a[i][1], a[i][2]));
		cur += mx;
		if (mx == a[i][0]) {
			t[i] = 1;
			c1++;
			if (c1 > n / 2) wh = 1;
		} else if (mx == a[i][1]) {
			t[i] = 2;
			c2++;
			if (c2 > n / 2) wh = 2;
		} else {
			t[i] = 3;
			c3++;
			if (c3 > n / 2) wh = 3;
		}
	}
	if (wh == -1) {
		printf("%lld\n", cur);
		return ;
	}
	vector<ll> rem;
	rem.clear();
	for(int i = 1; i <= n; i++) {
		if (t[i] == 1 && t[i] == wh) {
			rem.push_back(max(a[i][1] - a[i][0], a[i][2] - a[i][0]));
		} else if (t[i] == 2 && t[i] == wh) {
			rem.push_back(max(a[i][0] - a[i][1], a[i][2] - a[i][1]));
		} else if (t[i] == 3 && t[i] == wh) {
			rem.push_back(max(a[i][0] - a[i][2], a[i][1] - a[i][2]));
		}
	}
	sort(rem.begin(), rem.end(), greater<int>());
	int c = 0;
	if (wh == 1) c = c1;
	else if (wh == 2) c = c2;
	else if (wh == 3) c = c3;
	for(int i = 0; i < (int)rem.size(); i++) {
		c--;
		cur += rem[i];
		if (c == n / 2) break; 
	}
	printf("%lld\n", cur);
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--) solve();
	return 0;
} 
