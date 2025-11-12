#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const LL N = 5e2 + 10;
const LL MOD = 998244353;

LL n, m, a[N], c[N];

namespace Calc {
	const LL N = 5e3 + 10;
	LL a[N], c[N];
	string Mult(string as, LL x) {
		memset(a, 0, sizeof a);
		memset(c, 0, sizeof c);
		LL al = as.size(), cl = al + 20;
		for (LL i = 1; i <= al; i++) a[i] = as[al - i] - '0';
		for (LL i = 1; i <= cl; i++) {
			c[i] += a[i] * x;
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
		}
		while (c[cl] == 0 && cl > 1) cl--;
		string cs;
		for (LL i = cl; i >= 1; i--) cs += c[i] + '0';
		return cs;
	}
	string Div(string as, LL x) {
		memset(a, 0, sizeof a);
		memset(c, 0, sizeof c);
		LL al = as.size(), cl = al;
		for (LL i = 1; i <= al; i++) a[i] = as[i - 1] - '0';
		LL rest = 0;
		for (LL i = 1; i <= cl; i++) {
			rest = rest * 10 + a[i];
			c[i] = rest / x;
			rest %= x;
		}
		LL p = 1;
		while (p <= cl && c[p] == 0) p++;
		string cs;
		for (LL i = p; i <= cl; i++) cs += c[i] + '0';
		if (cs.empty()) return "0";
		return cs;
	}
	LL Mod(string as, LL x) {
		memset(a, 0, sizeof a);
		memset(c, 0, sizeof c);
		LL al = as.size(), cl = al;
		for (LL i = 1; i <= al; i++) a[i] = as[i - 1] - '0';
		LL rest = 0;
		for (LL i = 1; i <= cl; i++) {
			rest = rest * 10 + a[i];
			rest %= x;
		}
		return rest;
	}
}

void C(LL n, LL m) {
	n++;
	string ans = "1";
	for (LL i = 1; i <= m; i++) {
		ans = Calc::Div(Calc::Mult(ans, n - i), i);
		// ans = ans * (n - i) / i;
	}
	printf("%lld\n", Calc::Mod(ans, MOD));
}

LL ans[N], vis[N], cnt = 0;
void dfs(LL cur) {
	if (cur > n) {
		LL red = 0, can = 0;
		for (LL i = 1; i <= n; i++) {
			if (c[ans[i]] <= red || a[i] == 0) red++;
			else can++;
		}
		if (can >= m) cnt++;
		return;
	}
	for (LL i = 1; i <= n; i++) {
		if (vis[i]) continue;
		ans[cur] = i;
		vis[i] = true;
		dfs(cur + 1);
		vis[i] = false;
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	bool A = true;
	for (LL i = 1; i <= n; i++) {
		char ch;
		cin >> ch;
		a[i] = ch - 48;
		if (a[i] == 0) A = false;
	}
	LL sum = 0;
	for (LL i = 1; i <= n; i++) {
		scanf("%lld", c + i);
		if (c[i]) sum++;
	}
	// if (A) {
	// 	if (sum < m) printf("0\n");
	// 	else {
	// 		C(m, sum);
	// 	}
	// }
	dfs(1);
	printf("%lld\n", cnt);
	return 0;
}
