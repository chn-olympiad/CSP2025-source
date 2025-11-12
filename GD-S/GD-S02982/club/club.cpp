#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
using namespace std;
const int N = 1e5+7, M = 2e4;
int i, j, k, n, m, T, x[N], y[N], z[N], u, v, w, us[N];
int a, b, c, gs; ll res, cnt, ans;
struct pq {
	int b, c, p;
	#define b(i) d[i].b
	#define c(i) d[i].c
//	#define d(i) d[i].d
	#define p(i) d[i].p
} d[N];
struct ab {
	int a, o;
	#define a(i) t[i].a
	#define o(i) t[i].o
} t[N];
//pair<int,int> t[N];
bool cmp(pq x, pq y) {return x.b > y.b;}
bool cmp1(ab a, ab b) {
	return a.a > b.a;
}

void sol() {
	scanf("%d", &n);
	u=v=w=ans = res = cnt = 0, m = n/2;
	for(i=1; i<=n; i++) {
		scanf("%d%d%d", &a, &b, &c);
		res += a;
		p(i) = i, b(i) = b-a, c(i) = c-b;
		x[i] = a, y[i] = b, z[i] = c;
		if(y[i] > x[i] && y[i] > z[i]) ++v, cnt += y[i];
		else if(x[i] > y[i] && x[i] > z[i]) ++u, cnt += x[i];
		else ++w, cnt += z[i];
	}
	if(u <= m && v <= m && w <= m) {
		ans = cnt;
	}
	memset(us, 0, sizeof us);
	gs = 0;
	if(u > m) {
		ll tmp = cnt;
//		puts("qwq");
		for(i=1; i<=n; i++) {
			if(x[i] >= y[i] && x[i] >= z[i]) {
				t[++gs] = {y[i]-x[i], i};
				t[++gs] = {z[i]-x[i], i};
			}
		}
		sort(t+1, t+1+gs, cmp1);
		int q = u-m, i = 1;
		while(q) {
			while(us[o(i)]) ++i;
			us[o(i)] = 1, tmp += a(i), --q;
		}
		ans = max(ans, tmp);
	}
	memset(us, 0, sizeof us);
	gs = 0;
	if(v > m) {
//		puts("qwq");
		ll tmp = cnt;
		for(i=1; i<=n; i++) {
			if(y[i] >= x[i] && y[i] >= z[i]) {
				t[++gs] = {x[i]-y[i], i};
				t[++gs] = {z[i]-y[i], i};
			}
		}
		sort(t+1, t+1+gs, cmp1);
		int q = v-m, i = 1;
		while(q) {
			while(us[o(i)]) ++i;
			us[o(i)] = 1, tmp += a(i), --q;
		}
//		cout << tmp << " " << cnt << " " << v-m<<" " << v<<"\n";
		ans = max(ans, tmp);
	}
	memset(us, 0, sizeof us);
	gs = 0;
	if(w > m) {
		ll tmp = cnt;
		for(i=1; i<=n; i++) {
			if(z[i] >= y[i] && z[i] >= x[i]) {
				t[++gs] = {x[i]-z[i], i};
				t[++gs] = {y[i]-z[i], i};
			}
		}
		sort(t+1, t+1+gs, cmp1);
		int q = w-m, i = 1;
		while(q) {
			while(us[o(i)]) ++i;
			us[o(i)] = 1, tmp += a(i), --q;
		}
		ans = max(ans, tmp);
	}
//	printf("%lld\n", ans);
	sort(d+1, d+1+n, cmp);
	for(i=1; i<=m; i++) {
		res += b(i);
	}
	for(i=1; i<=m; i++) b(i) = y[p(i)];
	for(i=m+1; i<=n; i++) b(i) = x[p(i)];
	for(i=1; i<=n; i++) {
		b(i) = z[p(i)] - b(i);
	}
	sort(d+1, d+1+n, cmp);
	for(i=1; i<=m; i++) {
		if(b(i) > 0) res += b(i);
	}
	ans = max(ans, res);
//	cout << u << " " << v << " " << w << "\n";
	printf("%lld\n", ans);
//	exit(0);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while(T--) sol();
	return 0;
}
