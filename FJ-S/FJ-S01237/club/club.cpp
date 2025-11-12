#include<bits/stdc++.h>
using namespace std;
//#define int long long
//const int mod=

int t;
int n;
pair<int, int> s[5];
int v[3][100005], vtop[3];
int ans;

void solve() {
	ans = 0;
	vtop[0] = vtop[1] = vtop[2] = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int k = 0; k < 3; k++) {
			scanf("%d", &s[k].first);
			s[k].second = k;
		}
		sort(s, s + 3);
		int mi = s[2].first - s[1].first;
		int g = s[2].second;
		ans += s[2].first;
		v[g][++vtop[g]] = mi;
	}
	for (int i = 0; i < 3; i++) {
		sort(v[i] + 1, v[i] + 1 + vtop[i], greater<int>());
		while (vtop[i] > n / 2) {
			ans -= v[i][vtop[i]];
			vtop[i]--;
		}
	}
	printf("%d\n", ans);
	return ;
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	scanf("%d", &t);
	while (t--)solve();

	return 0;
}
