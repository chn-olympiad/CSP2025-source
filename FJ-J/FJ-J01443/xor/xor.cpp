#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline ll read() {
	ll x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x;
}

const int N = 5e5 + 10;
ll n, k, tot, ans = 1;
ll a[N];
struct edge {
	int l, r;
}e[N];

bool cmp(const edge& a, const edge& b) {
	return a.r < b.r;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	n = read(), k = read();
	for (int i = 1; i <= n; ++i) {
		a[i] = read();
	}
	for (int i = 1; i <= n; ++i) {
		ll sum = a[i];
		if (sum == k) {
			e[++tot].l = i;
			e[tot].r = i;
			continue;
		}
		for (int j = i + 1; j <= n; ++j) {
			sum ^= a[j];
			if (sum == k) {
				e[++tot].l = i;
				e[tot].r = j;
				break;
			}
		}
	}
	sort(e + 1, e + 1 + tot, cmp);
	int rr = e[1].r;
	for (int i = 2; i <= tot; ++i) {
		if (e[i].l <= rr) continue;
		rr = e[i].r;
		++ans;
	}
	if (tot == 0) printf("0");
	else printf("%lld", ans);
	return 0;
}
