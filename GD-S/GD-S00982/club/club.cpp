#include<bits/stdc++.h>
using namespace std;
#define N 100050
int T, n, m, i, j, k, a, b, c, ab, bc, ac, abc, ans;
struct B{
	int a, b, c;
} d[N];
bool cmp1(B x, B y) {
	return x.a - max(x.b, x.c) > y.a - max(y.b, y.c);
} 
bool cmp2(B x, B y) {
	return x.b - max(x.a, x.c) > y.b - max(y.a, y.c);
} 
bool cmp3(B x, B y) {
	return x.c - max(x.a, x.b) > y.c - max(y.a, y.b);
} 
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (i=1; i<=n; i++) scanf("%d%d%d", &d[i].a, &d[i].b, &d[i].c);
		for (ans=a=b=c=0, i=1; i<=n; i++) {
			k = max(d[i].a, max(d[i].b, d[i].c));
			ans += k;
			if (k == d[i].a && k == d[i].b && k == d[i].c) abc++, a++;
			else if (k == d[i].a && k == d[i].b) ab++, a++;
			else if (k == d[i].a && k == d[i].c) ac++, a++;
			else if (k == d[i].b && k == d[i].c) bc++, b++;
			else if (k == d[i].a) a++;
			else if (k == d[i].b) b++;
			else if (k == d[i].c) c++;
		}
		if (a > n/2) {
			if (a-ab-ac-abc > n/2) {
				for (ans=0, i=1; i<=n; i++) ans += max(d[i].b, d[i].c);
				sort(d+1, d+n+1, cmp1);
				for (i=1; i<=n/2; i++) ans += d[i].a-max(d[i].b, d[i].c);
			}
		}
		else if (b > n/2) {
			if (b-bc > n/2) {
				for (ans=0, i=1; i<=n; i++) ans += max(d[i].a, d[i].c);
				sort(d+1, d+n+1, cmp2);
				for (i=1; i<=n/2; i++) ans += d[i].b-max(d[i].a, d[i].c);
			}
		}
		else if (c > n/2) {
			for (ans=0, i=1; i<=n; i++) ans += max(d[i].a, d[i].b);
			sort(d+1, d+n+1, cmp3);
			for (i=1; i<=n/2; i++) ans += d[i].c-max(d[i].a, d[i].b);
		}
		printf("%d\n", ans);
	}
	return 0;
}
