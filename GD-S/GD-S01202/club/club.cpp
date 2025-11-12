#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f
using namespace std;

int t;

struct Member {
	int a[5];
	bool vis;
} m[100005];

int n, a, b, c, ans;

void dfs(int x, int sum) {
	if (x > n) {
		if (sum >= ans) ans = sum; 
		return ;
	}
	
	for (int i = 1; i <= n; i++) {
		if (m[i].vis == 0) {
			m[i].vis = 1;
			if (a < n / 2) {
				a++;
				dfs(x + 1, sum + m[i].a[1]);
				a--;
			}
			if (b < n / 2) {
				b++;
				dfs(x + 1, sum + m[i].a[2]);
				b--;
			}
			if (c < n / 2) {
				c++;
				dfs(x + 1, sum + m[i].a[3]);
				c--;
			}
			m[i].vis = 0;
		}
	}
}

bool cmpA(Member x, Member y) {
	return x.a[1] > y.a[1];
}

bool cmpB1(Member x, Member y) {
	if (x.a[1] != y.a[1]) return x.a[1] > y.a[1];
	return x.a[2] < y.a[2];
}
bool cmpB2(Member x, Member y) {
	return x.a[2] > y.a[2];
}

void spA() {
	sort(m + 1, m + 1 + n, cmpA);
	for (int i = 1; i <= n / 2; i++) ans += m[i].a[1];
	printf("%lld\n", ans);
	return ;
}

void spB() {
	sort(m + 1, m + 1 + n, cmpB1);
	for (int i = 1; i <= n && a < n / 2; i++) {
		if (m[i].vis == 0 && m[i].a[1] > m[i].a[2]) {
			ans += m[i].a[1];
			m[i].vis = 1;
			a++;
		}
	}
	sort(m + 1, m + 1 + n, cmpB2);
	for (int i = 1; i <= n && b < n / 2; i++) {
		if (m[i].vis == 0) {
			ans += m[i].a[2];
			m[i].vis = 1;
			b++;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (m[i].vis == 0) {
			if (a < n / 2) {
				if (m[i].a[1] > m[i].a[2]) {
					a++;
					ans += m[i].a[1];
				}
				else if (b == n / 2) {
					a++;
					ans += m[i].a[1];
				}
			}
			if (b < n / 2) {
				b++;
				ans += m[i].a[2];
			}
		}
	}
	printf("%lld\n", ans);
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	scanf("%lld", &t);
	
	while (t--) {
		int f1 = 0, f2 = 0, f3 = 0;
		a = b = c = ans = 0;
		
		scanf("%lld", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%lld%lld%lld", &m[i].a[1], &m[i].a[2], &m[i].a[3]);
			if (m[i].a[2] != 0) f2 = 1;
			if (m[i].a[3] != 0) f3 = 1;
			m[i].vis = 0;
		}
		
		if (f2 == 0 && f3 == 0) {
			spA();
			continue;
		}
		
		if (f3 == 0) {
			spB();
			continue;
		}
		
		dfs(1, 0);
		
		printf("%lld\n", ans);
	}
	
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
/*
1 
10 
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
*/
