#include <bits/stdc++.h>

using namespace std;

int read() {
    int x = 0, k = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') k = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * k;
}

#define p1(i) ((i + 1) % 3 == 0 ? 3 : (i + 1) % 3)
#define p2(i) ((i + 2) % 3 == 0 ? 3 : (i + 2) % 3)


struct node {
	int d, id;
} t[100005];
int a[100005][5];
int s[5], k;

bool cmp(node x, node y) {
	if (x.id == k && y.id != k) return 1;
	if (y.id == k && x.id != k) return 0;
	if (x.id == k && y.id == k) return x.d < y.d;
	return 0;
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    
    int T = read();
    while (T--) {
		memset(s, 0, sizeof(s));
		int n = read(), ans = 0, m = n / 2;
		for (int i = 1; i <= n; i++) {
			a[i][1] = read(), a[i][2] = read(), a[i][3] = read();
			for (int j = 1; j <= 3; j++) {
				if (a[i][j] >= a[i][p1(j)] && a[i][j] >= a[i][p2(j)]) {
					t[i].id = j; s[j]++; ans += a[i][j];
					t[i].d = min(a[i][j] - a[i][p1(j)], a[i][j] - a[i][p2(j)]);
					break;
				}
			}
		}
		k = 0;
		for (int j = 1; j <= 3; j++)
			if (s[j] > m) k = j;
		if (k == 0) { printf("%d\n", ans); continue; }
		sort(t + 1, t + n + 1, cmp);
		for (int i = 1; i <= s[k] - m; i++)
			ans -= t[i].d;
		printf("%d\n", ans);
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
