#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct peo {
	int a, b, c;
	int s() {
		return a + b + c;
	}
} p[N];
vector<peo> a, b, c;
bool cmpa(peo a, peo b) {
	if (a.s() - a.a == b.s() - b.a) return a.a < b.a;
	return a.s() - a.a > b.s() - b.a;
}
bool cmpb(peo a, peo b) {
	if (a.s() - a.b == b.s() - b.b) return a.b < b.b;
	return a.s() - a.b > b.s() - b.b;
}
bool cmpc(peo a, peo b) {
	if (a.s() - a.c == b.s() - b.c) return a.c < b.c;
	return a.s() - a.c > b.s() - b.c;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int q, n, x, y;
	long long cnt;
	scanf("%d", &q);
	while (q--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d%d%d", &p[i].a, &p[i].b, &p[i].c);
		for (int i = 1; i <= n; i++) {
			x = p[i].a - p[i].b;
			if (x < 0) {
				y = p[i].b - p[i].c;
				if (y < 0) {
					c.push_back(p[i]);
				} else {
					b.push_back(p[i]);
				}
			} else {
				y = p[i].a - p[i].c;
				if (y < 0) {
					c.push_back(p[i]);
				} else {
					a.push_back(p[i]);
				}
			}
		}
		sort(a.begin(), a.end(), cmpa);
		sort(b.begin(), b.end(), cmpb);
		sort(c.begin(), c.end(), cmpc);
		if (a.size() > n / 2) {
			while (a.size() > n / 2) {
				x = a[0].b - a[0].c;
				if (x < 0) {
					c.push_back(a[0]);
					a.erase(a.begin());
				} else {
					b.push_back(a[0]);
					a.erase(a.begin());
				}
			}
		}
		if (b.size() > n / 2) {
			while (b.size() > n / 2) {
				x = b[0].a - b[0].c;
				if (x < 0) {
					c.push_back(b[0]);
					b.erase(b.begin());
				} else {
					a.push_back(b[0]);
					b.erase(b.begin());
				}
			}
		}
		if (c.size() > n / 2) {
			while (c.size() > n / 2) {
				x = c[0].a - c[0].b;
				if (x < 0) {
					b.push_back(c[0]);
					c.erase(c.begin());
				} else {
					a.push_back(c[0]);
					c.erase(c.begin());
				}
			}
		}
		cnt = 0;
		for (auto it: a) cnt += it.a;
		for (auto it: b) cnt += it.b;
		for (auto it: c) cnt += it.c;
		printf("%lld\n", cnt);
		memset(p, 0, sizeof p);
		a.clear();
		b.clear();
		c.clear();
	}
	return 0;
}
