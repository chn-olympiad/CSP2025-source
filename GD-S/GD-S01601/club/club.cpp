#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>
#include <vector>
#define LL long long
#define int long long

using namespace std;

int read() {
	int k = 0, kk = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')
			kk = -1;
		c = getchar();
	}
	while ('0' <= c && c <= '9') {
		k = k * 10 + c - '0';
		c = getchar();
	}
	return k * kk;
}

void write(int x) {
	if (x < 0)
		putchar('-'), x = -x;
	if (x > 9)
		write(x / 10);
	putchar(x % 10 + '0');
}

const int N = 1e5 + 10;

int T;
int n;
struct node {
	int a, b, c;
	int bel;
} w[N];

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	T = read();
	while (T -- ) {
		n = read();
		int cnt[5] = {0, 0, 0, 0};
		int ans = 0, tmp = n >> 1;
		for (int i = 1; i <= n; i ++ ) {
			w[i].a = read(), w[i].b = read(), w[i].c = read();
			if (w[i].a >= w[i].b && w[i].a >= w[i].c)
				cnt[1] ++ , ans += w[i].a, w[i].bel = 1;
			else if (w[i].b >= w[i].c && w[i].b >= w[i].a)
				cnt[2] ++ , ans += w[i].b, w[i].bel = 2;
			else
				cnt[3] ++ , ans += w[i].c, w[i].bel = 3;
		}
		if (cnt[1] > tmp) {
			vector<int> v;
			for (int i = 1; i <= n; i ++ )
				if (w[i].bel == 1)
					v.push_back(w[i].a - max(w[i].b, w[i].c));
			sort(v.begin(), v.end());
			tmp = cnt[1] - tmp;
			for (int i = 0; i < tmp; i ++ )
				ans -= v[i];
		} else if (cnt[2] > tmp) {
			vector<int> v;
			for (int i = 1; i <= n; i ++ ) {
				if (w[i].bel == 2)
					v.push_back(w[i].b - max(w[i].a, w[i].c));
			}
			sort(v.begin(), v.end());
			tmp = cnt[2] - tmp;
			for (int i = 0; i < tmp; i ++ )
				ans -= v[i];
		} else if (cnt[3] > tmp) {
			vector<int> v;
			for (int i = 1; i <= n; i ++ )
				if (w[i].bel == 3)
					v.push_back(w[i].c - max(w[i].b, w[i].a));
			sort(v.begin(), v.end());
			tmp = cnt[3] - tmp;
			for (int i = 0; i < tmp; i ++ )
				ans -= v[i];
		}
		write(ans), putchar('\n');
	}
	return 0;
}
