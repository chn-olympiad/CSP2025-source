#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 1e5+50;
int an, bn, cn;
struct P {
	int a, b, c;
} p[N], a[N], b[N], c[N];
bool cmp1(P x, P y) {
//	return x.a<y.a;
	return max(x.b, x.c) < max(y.b, y.c);
}
bool cmp2(P x, P y) {
//	return x.b<y.b;
	return max(x.a, x.c) < max(y.a, y.c);
}
bool cmp3(P x, P y) {
//	return x.c<y.c;
	return max(x.a, x.b) < max(y.a, y.b);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n;
		an = 0;
		bn = 0;
		cn = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> p[i].a >> p[i].b >> p[i].c;
		}
		for (int i = 1; i <= n; i++) {
			if (p[i].a >= p[i].b && p[i].a >= p[i].c) {
				a[++an] = p[i];
				push_heap(a + 1, a + an + 1, cmp1);

			} else if (p[i].b >= p[i].a && p[i].b >= p[i].c) {
				b[++bn] = p[i];
				push_heap(b + 1, b + bn + 1, cmp2);

			} else if (p[i].c >= p[i].a && p[i].c >= p[i].b) {
				c[++cn] = p[i];
				push_heap(c + 1, c + cn + 1, cmp3);
			}
			if (an > n / 2) {
				pop_heap(a + 1, a + an + 1, cmp1);
				P cur = a[an--];
				if (cur.b > cur.c) {
					b[++bn] = cur;
					push_heap(b + 1, b + bn + 1, cmp2);

				} else {
					c[++cn] = cur;
					push_heap(c + 1, c + cn + 1, cmp3);
				}
			}
			if (bn > n / 2) {
				pop_heap(b + 1, b + bn + 1, cmp2);
				P cur = b[bn--];
				if (cur.a > cur.c) {
					a[++an] = cur;
					push_heap(a + 1, a + an + 1, cmp1);

				} else {
					c[++cn] = cur;
					push_heap(c + 1, c + cn + 1, cmp3);
				}
			}
			if (cn > n / 2) {
				pop_heap(c + 1, c + cn + 1, cmp3);
				P cur = c[cn--];
				if (cur.b > cur.a) {
					b[++bn] = cur;
					push_heap(b + 1, b + bn + 1, cmp2);

				} else {

					a[++an] = cur;
					push_heap(a + 1, a + an + 1, cmp1);
				}
			}
//			cout<<an<<bn<<cn;
		}
		int ans = 0;
		for (int i = 1; i <= an; i++) {
			ans += a[i].a;
		}
		for (int i = 1; i <= bn; i++) {
			ans += b[i].b;
		}
		for (int i = 1; i <= cn; i++) {
			ans += c[i].c;
		}
		cout << ans << "\n";
	}
	return 0;
}