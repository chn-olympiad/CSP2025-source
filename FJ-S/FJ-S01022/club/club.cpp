#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int T, n, d[N], ans;
struct tmp {
	int a, b, c;
} s[N];
bool cmp(tmp x, tmp y) {
	return x.a + x.b + x.c > y.a + y.b + y.c;
}
struct res {
	int num, id;
} ok[10];
bool cmpok(res x, res y) {
	return x.num > y.num;
}
void dfs(int k) {
	if (k == n + 1) {
		int sum = 0, c1 = 0, c2 = 0, c3 = 0;
		for (int i = 1; i <= n; i++) {
			if (d[i] == 1) {
				sum += s[i].a; c1++; 
			} else if (d[i] == 2) {
				sum += s[i].b; c2++;
			} else {
				sum += s[i].c; c3++;
			}
		}
		if (c1 <= n/2 && c2 <= n/2 && c3 <= n/2) ans = max(ans, sum);
		return ;
	}
	d[k] = 1, dfs(k + 1);
	d[k] = 2, dfs(k + 1);
	d[k] = 3, dfs(k + 1);
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n), ans = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d %d %d", &s[i].a, &s[i].b, &s[i].c);
		}
		if (n <= 10) {
			dfs(1);
			printf("%d\n", ans);
			continue;
		}
		sort(s + 1, s + n + 1, cmp);
		int ans = 0, c1 = 0, c2 = 0, c3 = 0, mx = n / 2;
		for (int i = 1; i <= n; i += 2) {
			ok[1].num = s[i].a + s[i + 1].a, ok[1].id = 1;
		//	cout << ok[1].num << endl;
			ok[2].num = s[i].a + s[i + 1].b, ok[2].id = 2;
		//	cout << ok[2].num << endl;
			ok[3].num = s[i].a + s[i + 1].c, ok[3].id = 3;
		//	cout << ok[3].num << endl;
			ok[4].num = s[i].b + s[i + 1].a, ok[4].id = 4;
		//	cout << ok[4].num << endl;
			ok[5].num = s[i].b + s[i + 1].b, ok[5].id = 5;
		//	cout << ok[5].num << endl;
			ok[6].num = s[i].b + s[i + 1].c, ok[6].id = 6;
		//	cout << ok[6].num << endl;
			ok[7].num = s[i].c + s[i + 1].a, ok[7].id = 7;
		//	cout << ok[7].num << endl;
			ok[8].num = s[i].c + s[i + 1].b, ok[8].id = 8;
		//	cout << ok[8].num << endl;
			ok[9].num = s[i].c + s[i + 1].c, ok[9].id = 9;
		//	cout << ok[9].num << endl;
			sort(ok + 1, ok + 10, cmpok);
			for (int j = 1; j <= 9; j++) {
				int id = ok[j].id, isok = 0;
				if (id == 1) {
					if (c1 + 2 <= mx) {
						c1 += 2, ans += ok[j].num, isok = 1;
					}
				}
				if (id == 2) {
					if (isok) {
						continue;
					} else {
						if (c1 + 1 <= mx && c2 + 1 <= mx) {
							c1++, c2++, ans += ok[j].num, isok = 1;
						}
					}
				}
				if (id == 3) {
					if (isok) {
						continue;
					} else {
						if (c1 + 1 <= mx && c3 + 1 <= mx) {
							c1++, c3++, ans += ok[j].num, isok = 1;
						}
					}
				}
				if (id == 4) {
					if (isok) {
						continue;
					} else {
						if (c2 + 1 <= mx && c1 + 1 <= mx) {
							c2++, c1++, ans += ok[j].num, isok = 1;
						}
					}
				}
				if (id == 5) {
					if (isok) {
						continue;
					} else {
						if (c2 + 2 <= mx) {
							c2 += 2, ans += ok[j].num, isok = 1;
						}
					}
				}
				if (id == 6) {
					if (isok) {
						continue;
					} else {
						if (c2 + 1 <= mx && c3 + 1 <= mx) {
							c2++, c3++, ans += ok[j].num, isok = 1;
						}
					}
				}
				if (id == 7) {
					if (isok) {
						continue;
					} else {
						if (c3 + 1 <= mx && c1 + 1 <= mx) {
							c3++, c1++, ans += ok[j].num, isok = 1;
						}
					}
				}
				if (id == 8) {
					if (isok) {
						continue;
					} else {
						if (c3 + 1 <= mx && c2 + 1 <= mx) {
							c3++, c2++, ans += ok[j].num, isok = 1;
						}
					}
				}
				if (id == 9) {
					if (isok) {
						continue;
					} else {
						if (c3 + 2 <= mx) {
							c3 += 2, ans += ok[j].num, isok = 1;
						}
					}
				}
				if (isok) break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
