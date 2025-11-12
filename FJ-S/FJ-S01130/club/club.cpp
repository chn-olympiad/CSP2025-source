#include <bits/stdc++.h>

using namespace std;

const long long N = 1e6 + 5, mod = 998244353, inf = 4e18;

inline long long read() {
	long long x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') {
			f = -1;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + (ch - '0');
		ch = getchar();
	}
	return x * f;
}

long long t, n, belong[N], cnt1 = 0, cnt2 = 0, ans = 0;

bool flaga = 1, flagb = 1;

priority_queue<pair<long long, long long> > q;

struct person {
	long long id, s1, s2, s3, diff1, diff2;
} a[N];

bool cmp1(person x, person y) {
	return x.diff1 > y.diff1;
}

bool cmp2(person x, person y) {
	return x.diff2 > y.diff2;
}

bool cmpa(person x, person y) {
	return x.s1 > y.s1;
}

void solve_a() {
	sort(a + 1, a + n + 1, cmpa);
	for (long long i = 1; i <= n / 2; ++i) {
		ans += a[i].s1;
	}
	printf("%lld\n", ans);
}

void solve_b() {
	sort(a + 1, a + n + 1, cmp1);
	for (long long i = 1; i <= n / 2; ++i) {
		belong[a[i].id] = 2;
	}
	for (long long i = 1; i <= n; ++i) {
		if (belong[a[i].id] == 1) {
			ans += a[i].s1;
		} else {
			ans += a[i].s2;
		}
	}
	printf("%lld\n", ans);
}

struct data {
	long long id, x, to;
} b[N];

bool cmp_hope(data a, data b) {
	return a.x > b.x;
}

long long cnt[5];

long long hope() {
	cnt[1] = n, cnt[2] = 0, cnt[3] = 0;
	long long tot = 0, res = 0;
	for (long long i = 1; i <= n; ++i) {
		belong[i] = 1;
		++tot;
		b[tot].id = i;
		b[tot].x = a[i].s2 - a[i].s1;
		b[tot].to = 2;
		++tot;
		b[tot].id = i;
		b[tot].x = a[i].s3 - a[i].s1;
		b[tot].to = 3;
	}
	sort(b + 1, b + tot + 1, cmp_hope);
	for (long long i = 1; i <= tot; ++i) {
//			cout << b[i].id << '\n';
		if (belong[b[i].id] != 1) {
			continue;
		}
		if (cnt[1] > n / 2) {
			if (cnt[b[i].to] >= n / 2) {
				continue;
			}
			--cnt[1], ++cnt[b[i].to];
			belong[b[i].id] = b[i].to;
		} else {
			if (b[i].x > 0) {
				if (cnt[b[i].to] >= n / 2) {
					continue;
				}
				--cnt[1], ++cnt[b[i].to];
				belong[b[i].id] = b[i].to;
			} else {
				break;
			}
		}
	}
	for (long long i = 1; i <= n; ++i) {
		if (belong[a[i].id] == 1) {
			res += a[i].s1;
		} else if (belong[a[i].id] == 2) {
			res += a[i].s2;
		} else {
			res += a[i].s3;
		}
	}
	return res;
}

void a_sad_story() {
	long long lrh = hope();
	for (long long i = 1; i <= n; ++i) {
		belong[i] = 1;
	} 
	sort(a + 1, a + n + 1, cmp1);
	for (long long i = 1; i <= n / 2; ++i) {
		belong[a[i].id] = 2;
	}
	for (long long i = 1; i <= n; ++i) {
		if (belong[a[i].id] == 1) {
			a[i].diff2 = a[i].s3 - a[i].s1;
		} else {
			a[i].diff2 = a[i].s3 - a[i].s2;
		}
	}
	sort(a + 1, a + n + 1, cmp2);
	for (long long i = 1; i <= n / 2; ++i) {
		if (a[i].diff2 > 0) {
			belong[a[i].id] = 3;
		} else {
			break;
		}
	}
	for (long long i = 1; i <= n; ++i) {
		if (belong[a[i].id] == 1) {
			++cnt1;
			a[i].diff1 = a[i].s2 - a[i].s1;
		} else if (belong[a[i].id] == 2) {
			++cnt2;
			a[i].diff1 = a[i].s1 - a[i].s2;
		} else {
			a[i].diff1 = -inf;
		}
	}
	sort(a + 1, a + n + 1, cmp1);
	for (long long i = 1; i <= n; ++i) {
		if (a[i].diff1 > 0) {
			if (belong[a[i].id] == 1 && cnt2 < n / 2) {
				belong[a[i].id] = 2, a[i].diff1 = a[i].s1 - a[i].s2;;
				--cnt1, ++cnt2;
			} else if (belong[a[i].id] == 2 && cnt1 < n / 2) {
				belong[a[i].id] = 1, a[i].diff1 = a[i].s2 - a[i].s1;
				++cnt1, --cnt2;
			}
		} else {
			break;
		}
	}
	while (!q.empty()) {
		q.pop();
	}
	if (cnt1 == n / 2) {
		for (long long i = 1; i <= n; ++i) {
			if (belong[a[i].id] == 1) {
				q.push(make_pair(-a[i].diff1, a[i].id));
			}
		}
		for (long long i = 1; i <= n; ++i) {
			if (belong[a[i].id] == 2) {
				if (a[i].diff1 - q.top().first > 0) {
					swap(belong[a[i].id], belong[q.top().second]);
					q.pop();
					q.push(make_pair(a[i].diff1, a[i].id));
				}
			}
		}
	} else if (cnt2 == n / 2) {
		for (long long i = 1; i <= n; ++i) {
			if (belong[a[i].id] == 2) {
				q.push(make_pair(-a[i].diff1, a[i].id));
			}
		}
		for (long long i = 1; i <= n; ++i) {
			if (belong[a[i].id] == 1) {
				if (a[i].diff1 - q.top().first > 0) {
					swap(belong[a[i].id], belong[q.top().second]);
					q.pop();
					q.push(make_pair(a[i].diff1, a[i].id));
				}
			}
		}
	}
	for (long long i = 1; i <= n; ++i) {
		if (belong[a[i].id] == 1) {
			ans += a[i].s1;
		} else if (belong[a[i].id] == 2) {
			ans += a[i].s2;
		} else {
			ans += a[i].s3;
		}
	}
	printf("%lld\n", max(ans, lrh));
//	printf("%lld\n", ans);
}

void dfs(long long x, long long cnt1, long long cnt2, long long cnt3, long long sum) {
	if (x > n) {
		ans = max(ans, sum);
		return;
	}
	if (cnt1 < n / 2) {
		dfs(x + 1, cnt1 + 1, cnt2, cnt3, sum + a[x].s1);
	}
	if (cnt2 < n / 2) {
		dfs(x + 1, cnt1, cnt2 + 1, cnt3, sum + a[x].s2);
	}
	if (cnt3 < n / 2) {
		dfs(x + 1, cnt1, cnt2, cnt3 + 1, sum + a[x].s3);
	}
}

void solve_TAT() {
	dfs(1, 0, 0, 0, 0);
	printf("%lld\n", ans);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	for (t = read(); t--; ans = 0, cnt1 = 0, cnt2 = 0) {
		n = read();
		for (long long i = 1; i <= n; ++i) {
			a[i].id = i;
			a[i].s1 = read();
			a[i].s2 = read();
			a[i].s3 = read();
			a[i].diff1 = a[i].s2 - a[i].s1;
			belong[i] = 1;
			if (a[i].s2 != 0) {
				flaga = 0;
			}
			if (a[i].s3 != 0) {
				flaga = 0;
				flagb = 0;
			}
		}
		if (n <= 15) {
			solve_TAT();
		} else if (flaga) {
			solve_a();
		} else if (flagb) {
			solve_b();
		} else {
			a_sad_story();
		}
	}
	return 0;
}

// CSP-S2025 rp++!!! 
