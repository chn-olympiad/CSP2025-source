#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
#define sr cin
#define sw cout
#define sendl '\n'
#define seia cout.flush();return 0

struct node {
	int a, b, c;
	int d;
} a[100010];

bool cmp(int x, int y) {
	return a[x].d < a[y].d;
}

vector<int> v1, v2, v3;

void mika() {
	v1.clear();
	v2.clear();
	v3.clear();
	int n;
	sr >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		sr >> a[i].a >> a[i].b >> a[i].c;
		vector<int> h = {a[i].a, a[i].b, a[i].c};
		sort(h.begin(), h.end(), greater<int>());
		ans += h[0];
		if (h[0] == a[i].a) {
			v1.push_back(i);
		} else if (h[0] == a[i].b) {
			v2.push_back(i);
		} else {
			v3.push_back(i);
		}
		a[i].d = h[0] - h[1];	
	}
	if (v1.size() > n / 2) {
		sort(v1.begin(), v1.end(), cmp);
		for (int i = 0; i < v1.size() - n / 2; i++) {
			ans -= a[v1[i]].d;
		}
	}
	if (v2.size() > n / 2) {
		sort(v2.begin(), v2.end(), cmp);
		for (int i = 0; i < v2.size() - n / 2; i++) {
			ans -= a[v2[i]].d;
		}
	}
	if (v3.size() > n / 2) {
		sort(v3.begin(), v3.end(), cmp);
		for (int i = 0; i < v3.size() - n / 2; i++) {
			ans -= a[v3[i]].d;
		}
	}
	sw << ans << sendl;
}

int main() {
	ios::sync_with_stdio(false);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	sr >> T;
	while (T--) {
		mika();
	}
	seia;
}