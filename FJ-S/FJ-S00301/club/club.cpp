#include <bits/stdc++.h>
using namespace std;
int t, n, p[20005], s[5];
long long sum;
struct node {
	int a, b, c, m, k, l;
}a[20005];
bool cmp (node a, node b) {
	return a.m > b.m;
}
int main () {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	scanf ("%d", &t);
	while (t--) {
		for (int i = 1; i <= 20005; i++) p[i] = 0;
		s[1] = 0, s[2] = 0, s[3] = 0, sum = 0;
		scanf ("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf ("%d%d%d", &a[i].a, &a[i].b, &a[i].c);
			if (a[i].a >= a[i].b && a[i].b >= a[i].c) a[i].k = 1, a[i].l = 2, a[i].m = a[i].a - a[i].b;
			else if (a[i].a >= a[i].c && a[i].c >= a[i].b) a[i].k = 1, a[i].l = 3, a[i].m = a[i].a - a[i].c;
			else if (a[i].b >= a[i].a && a[i].a >= a[i].c) a[i].k = 2, a[i].l = 1, a[i].m = a[i].b - a[i].a;
			else if (a[i].b >= a[i].c && a[i].c >= a[i].a) a[i].k = 2, a[i].l = 3, a[i].m = a[i].b - a[i].c;
			else if (a[i].c >= a[i].a && a[i].a >= a[i].b) a[i].k = 3, a[i].l = 1, a[i].m = a[i].c - a[i].a;
			else if (a[i].c >= a[i].b && a[i].b >= a[i].a) a[i].k = 3, a[i].l = 2, a[i].m = a[i].c - a[i].b;
		}
		sort (a+1, a+n+1, cmp);
		//for (int i = 1; i <= n; i++) printf ("%d %d %d %d %d %d\n", a[i].a, a[i].b, a[i].c, a[i].k, a[i].l, a[i].m);
		for (int i = 1; i <= n; i++) {
			bool flag = 0;
			if (a[i].k == 1) {
				if (s[1] + 1 <= n / 2) s[1]++, sum += a[i].a; 
				else flag = 1;
			}
			if (a[i].k == 2) {
				if (s[2] + 1 <= n / 2) s[2]++, sum += a[i].b; 
				else flag = 1;
			}
			if (a[i].k == 3) {
				if (s[3] + 1 <= n / 2) s[3]++, sum += a[i].c; 
				else flag = 1;
			}
			if (flag) {
				if (a[i].l == 1) s[1]++, sum += a[i].a;
				if (a[i].l == 2) s[2]++, sum += a[i].b;
				if (a[i].l == 3) s[3]++, sum += a[i].c;
			}
		}
		printf ("%d\n", sum);
	}
	return 0;
}
