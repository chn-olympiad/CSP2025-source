#include <bits/stdc++.h>
#define el "\n"
#define sp " "
#define r0 return 0
#define F(i, a, b, c) for (int i = a; i <= b; i += c)

using namespace std;

typedef long long ll;
typedef string str;

int n, m;
struct Info {
	int v;
	int id;
} a[200];
int b[20][20];

inline bool cmp(Info x, Info y) {
	return x.v > y.v;
}

signed main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	F(i, 1, n * m, 1) {
		cin >> a[i].v;
		a[i].id = i;
	}
	std::sort(a + 1, a + n * m + 1, cmp);
	int x = 1, y = 1;
	F(i, 1, n * m, 1) {
		b[x][y] = a[i].id;
		if (y & 1) {
			x++;
			if (x == n + 1) {
				x--;
				y++;
			}
		} else {
			x--;
			if (x == 0) {
				x++;
				y++;
			}
		}
	}
	F(i, 1, n, 1) {
		F(j, 1, m, 1) {
			if (b[i][j] == 1) {
				cout << j << sp << i << el;
				r0;
			}
		}
	}
	r0;
}

