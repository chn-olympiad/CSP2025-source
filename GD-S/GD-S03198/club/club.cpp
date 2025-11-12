#include <bits/stdc++.h>
using namespace std;

#define N 100010
#define ll long long
ll ans, res;
struct node {
	int a, b, c, id;
} h[N], t[N], p[N];
int n, cnta, cntb, cntc;
bool vis[N];

bool cmp1(node _a, node _b) {
	if (_a.a == _b.a) {
		if (_a.b == _b.b) return _a.c > _b.c;
		else return _a.b > _b.b;
	} else return _a.a > _b.a;
}
bool cmp2(node _a, node _b) {
	if (_a.b == _b.b) {
		if (_a.a == _b.a) return _a.c > _b.c;
		else return _a.a > _b.a;
	} else return _a.b > _b.b;
}
bool cmp3(node _a, node _b) {
	if (_a.c == _b.c) {
		if (_a.a == _b.a) return _a.a > _b.a;
		else return _a.b > _b.b;
	} else return _a.c > _b.c;
}

void dfs(int x) {
	if (cnta > n / 2) return ;
	if (cntb > n / 2) return ;
	if (cntc > n / 2) return ;
	if (x == n + 1) {
	//	cout << cnta << " " << cntb << " " << cntc << " " << res << endl;
		ans = max(ans, res); 
		return ;
	}
	
	if (cnta + 1 <= n / 2) {
		res += h[x].a;
		++cnta;
		dfs(x + 1);
		res -= h[x].a;
		--cnta;
	}
	
	if (cntb + 1 <= n / 2) {
		res += h[x].b;
		++cntb;
		dfs(x + 1);
		res -= h[x].b;
		--cntb;
	}
	
	if (cntc + 1 <= n / 2) {
		res += h[x].c;
		++cntc;
		dfs(x + 1);
		res -= h[x].c;
		--cntc;
	}
}

void run(void) {
	memset(vis, 0, sizeof vis);
	cnta = cntb = cntc = res = ans = 0;
	
	bool fl1 = 1, fl2 = 1;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d %d", &h[i].a, &h[i].b, &h[i].c);
		h[i].id = i;
		t[i] = p[i] = h[i];
		if (h[i].b) fl1 = 0;
		if (h[i].c) fl2 = 0;
	}
	if (n <= 10) {
		dfs(1);
		printf("%lld\n", ans);
		return ;
	}
	if (fl1 && fl2) {
		sort(h + 1, h + n + 1, cmp1);
		for (int i = 1; i <= n / 2; ++i) ans += h[i].a;
		printf("%lld\n", ans);
		return ;
	}

//	puts("QWq");
	if (fl2) {
		sort(h + 1, h + n + 1, cmp1);
		sort(t + 1, t + n + 1, cmp2);
		int l1 = 1, l2 = 1;
		while (l1 < n && l2 < n) {
			while (vis[h[l1].id]) ++l1;
			while (vis[t[l2].id]) ++l2;
			if (h[l1].id == t[l2].id) {
				bool ff = 1;
				if (h[l1].a > h[l2].b) {
					if (cnta + 1 <= n / 2) ans += h[l1].a, ++cnta;
					else if (cntb + 1 <= n / 2) ans += h[l1].b, ++cntb;
				} else if (h[l1].a < h[l2].b) {
					if (cntb + 1 <= n / 2) ans += h[l1].b, ++cntb;
					else if (cnta + 1 <= n / 2) ans += h[l1].a, ++cnta;
				} else {
					ans += h[l1].a;
					if (cnta + 1 <= n / 2 && cntb + 1 <= n / 2) {
						if (cnta < cntb) ++cnta;
						else ++cntb;
					} else if (cnta + 1 <= n / 2) ++cnta;
					else if (cntb + 1 <= n / 2) ++cntb;
					else ff = 0;
				}
				if (ff) vis[h[l1].id] = 1;
				continue;
			}
			if (h[l1].a + t[l2].b > h[l1].b + t[l2].a) {
				if (cnta + 1 <= n / 2) ans += h[l1].a, ++cnta, vis[h[l1].id] = 1;
				if (cntb + 1 <= n / 2) ans += t[l2].b, ++cntb, vis[t[l2].id] = 1;
			} 
			if (h[l1].a + t[l2].b < h[l1].b + t[l2].a) {
				if (cnta + 1 <= n / 2) ans += t[l2].a, ++cnta, vis[t[l2].id] = 1;
				if (cntb + 1 <= n / 2) ans += h[l1].b, ++cntb, vis[h[l1].id] = 1;
			} 
			if (h[l1].a + t[l2].b == h[l1].b + t[l2].a) {
				ans += h[l1].a + t[l2].b;
				vis[h[l1].id] = vis[p[l2].id] = 0;
			} 
			if (cnta == n / 2) {
				for (int i = 1; i <= n; ++i)
					if (!vis[h[i].id]) ans += vis[h[i].b];
				break;
			}
			if (cntb == n / 2) {
				for (int i = 1; i <= n; ++i)
					if (!vis[h[i].id]) ans += vis[h[i].a];
				break;
			}
		}
		if (cnta == n / 2) {
			for (int i = 1; i <= n; ++i)
				if (!vis[h[i].id]) ans += vis[h[i].b];
		}
		if (cntb == n / 2) {
			for (int i = 1; i <= n; ++i)
				if (!vis[h[i].id]) ans += vis[h[i].a];
		}
		printf("%lld\n", ans);
		return ;
	}
	sort(h + 1, h + n + 1, cmp1);
	sort(t + 1, t + n + 1, cmp2);
	sort(p + 1, p + n + 1, cmp3);
	
/*	for (int i = 1; i <= n; ++i) {
		printf("%d %d %d\n", h[i].a, h[i].b, h[i].c);
	}*/
	/*
	for (int i = 1; i <= n; ++i) {
		if (vis[h[i].id]) continue;
		while (vis[t[lt].id]) ++lt;
		while (vis[p[lp].id]) ++lp;
		
		if (h[i].a + t[lt].b > h[i].b + t[lt].a && h[i].a + p[lp].c > h[i].c + p[lp].a) {
			
		}
	}
	*/
	return ;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) run();
	return 0;
}
