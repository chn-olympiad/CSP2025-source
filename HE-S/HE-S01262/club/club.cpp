#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n;
struct people{
	int a;
	int b;
	int c;
} a[N];
bool cmpa(people a, people b) {
	return a.a > b.a;
}/*
bool cmpb(people a, people b) {
	return a.b > b.b;
}
bool cmpc(people a, people b) {
	return a.c > b.c;
}*/
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d%d%d", &a[i].a, &a[i].b, &a[i].c);
		sort(a, a + n, cmpa);
		long long ans = 0;
		int i = 0;
		while (i * 2 + 2 <= n) {
			ans += a[i].a;
			i++;
		}
		/*int aa = 0, i = 0;
		long long ans = 0;
		while (aa * 2 + 2 <= n && i < n) {
			if (a[i].a >= a[i].b && a[i].a >= a[i].b) {
				ans += a[i].a;
				aa++;
				a[i].a = 0;
				a[i].b = 0;
				a[i].c = 0;
			}
			i++;
		}
		sort(a, a + n, cmpb);
		int b = 0;
		i = 0;
		while (b * 2 + 2 <= n && i < (n - aa)) {
			if (a[i].b >= a[i].c) {
				ans += a[i].b;
				b++;
				a[i].a = 0;
				a[i].b = 0;
				a[i].c = 0;
			}
			i++;
		}
		sort(a, a + n, cmpc);
		int c = 0;
		while (c * 2 + 2 <= n && i < (n - aa - b)) {
			ans += a[i].b;
			c++;
			a[i].a = 0;
			a[i].b = 0;
			a[i].c = 0;
			i++;
		}*/
		printf("%lld\n", ans);
		/*sort(a, a + n, cmpa);
		int i = 0, j = 0, aa = 0, bb = 0, cc = 0;
		long long ans = 0;
		while (i * 2 <= n && a[i].a >= a[i].b && a[i].a >= a[i].c) ans += a[i++].a;
		aa = i;
		cout << 2;
		sort(a + i, a + n, cmpb);
		while (j * 2 <= n && a[i + j].b >= a[i + j].a && a[i + j].b >= a[i + j].c) {
			ans += a[i + j].b;
			i++;
			j++; 
		}
		bb = j;
		sort(a + i, a + n, cmpc);
		j = 0;
		while (j * 2 <= n && a[i + j].c >= a[i + j].b && a[i + j].c >= a[i + j].a) {
			ans += a[i + j].a;
			i++;
			j++;
		}
		cc = j;
		cout << 3;
		while (i < n) {
			char maxn, midn, minn;
			if (a[i].a < a[i].b) {
				if (a[i].b < a[i].c) {
					maxn = 'c', midn = 'b', minn = 'a';
				} else if (a[i].a < a[i].c) {
					maxn = 'b', midn = 'c', minn = 'a';
				} else {
					maxn = 'b', midn = 'a', minn = 'c';
				}
			} else {
				if (a[i].a < a[i].c) {
					maxn = 'c', midn = 'a', minn = 'b';
				} else if (a[i].b < a[i].c) {
					maxn = 'a', midn = 'c', minn = 'b';
				} else {
					maxn = 'a', midn = 'b', minn = 'c';
				}
			}
			if (maxn == 'a' && aa * 2 + 2 <= n) {
				aa++;
				ans += a[i].a;
			} else if ((maxn == 'b' || aa * 2 + 2 > n) && bb * 2 + 2 <= n) {
				bb++;
				ans += a[i].b;
			} else if (cc * 2 + 2 <= n) {
				cc++;
				ans += a[i].c;
			}
			i++;
		}
		printf("%lld\n", ans);*/
	}
	return 0;
}
