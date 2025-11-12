#include <bits/stdc++.h>

#define ll long long
#define x first
#define y second
#define vec vector
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define MAXN 1000005

template <typename T> void read (T &x) {
	x = 0; T f = 1; char ch = getchar ();
	while (!isdigit (ch)) { if (ch == '-') f = -1; ch = getchar (); }
	while (isdigit (ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar ();
	x *= f;
}

template <typename T, typename ...Arp> void read (T &x, Arp & ...arp) {
	read (x), read (arp...);
}

int n, m, cnt = 1;
int a[MAXN];

signed main () {
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	read (n, m);
	
	read (a[1]);
	for (int i = 2; i <= n * m; ++i) {
		read (a[i]), cnt += (a[i] > a[1]);
	}

	int c = (cnt - 1) / n + 1;	
	cnt %= n; if (!cnt) cnt = n;	
	printf ("%d %d\n", c, ((c & 1) ? cnt : n - cnt + 1));
	return 0;
}

/*
2 2
99 100 97 98

1 2

3 3
94 95 96 97 98 99 100 93 92

2 2
98 99 100 97
*/
