#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> PII;
typedef long long LL;

const int N = 100010;
int T, n, d[N];

struct Node {
	PII a[4];
} p[N];

void solve() {
	vector<int> d;
	scanf("%lld", &n);
	int res = 0, cnt3 = 0, cnt1 = 0, cnt2 = 0; 
	for (int i = 1; i <= n; i ++) {
		scanf("%lld%lld%lld", &p[i].a[1].first, &p[i].a[2].first, &p[i].a[3].first);
		p[i].a[1].second = 1, p[i].a[2].second = 2, p[i].a[3].second = 3;
		sort(p[i].a + 1, p[i].a + 4); 
		res += p[i].a[3].first;
		if (p[i].a[3].second == 1) cnt1 ++;
		if (p[i].a[3].second == 2) cnt2 ++;
		if (p[i].a[3].second == 3) cnt3 ++;
	}
	if (cnt1 > n / 2) {
		for (int i = 1; i <= n; i ++) 
			if (p[i].a[3].second == 1) d.push_back(p[i].a[3].first - p[i].a[2].first);
		sort(d.begin(), d.end());
		for (int i = 0; i < cnt1 - n / 2; i ++) res -= d[i];
	} else if (cnt2 > n / 2) {
		for (int i = 1; i <= n; i ++) 
			if (p[i].a[3].second == 2) d.push_back(p[i].a[3].first - p[i].a[2].first);
		sort(d.begin(), d.end());
		for (int i = 0; i < cnt2 - n / 2; i ++) res -= d[i];				
	} else {		
		for (int i = 1; i <= n; i ++) 
			if (p[i].a[3].second == 3) d.push_back(p[i].a[3].first - p[i].a[2].first);
		sort(d.begin(), d.end());
		for (int i = 0; i < cnt3 - n / 2; i ++) res -= d[i];
	}
	printf("%lld\n", res);
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%lld", &T);
	while (T --) solve();
	return 0;
}
