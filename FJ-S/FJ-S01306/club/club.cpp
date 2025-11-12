#include <bits/stdc++.h>
using namespace std;

int T, n;
int a[100010][3];
int f[3];
vector <int> v;

int calc(int i) {
	if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2]) return 0;
	if (a[i][1] >= a[i][0] && a[i][1] >= a[i][2]) return 1;
	return 2;
}

int midd(int i) {
	int x = 0, y = 1, z = 2;
	if (a[i][x] > a[i][y]) swap(x, y);
	if (a[i][y] > a[i][z]) swap(y, z);
	if (a[i][x] > a[i][y]) swap(x, y);
	return y;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
//	freopen("club5.in", "r", stdin);
	cin >> T;
	for ( ; T-- ; ) {
		scanf("%d", &n);
		memset(f, 0, sizeof(f));
		int ans = 0;
		for (int i = 1 ; i <= n ; i++) {
			for (int j = 0 ; j < 3 ; j++)
				scanf("%d", &a[i][j]);
			int op = calc(i);
			++f[op], ans += a[i][op];
		}
		int op = -1;
		for (int i = 0 ; i < 3 ; i++)
			if (f[i] > n / 2) op = i;
		if (op == -1) printf("%d\n", ans);
		else {
//			cout << op << " " << f[op] << " ";
			v.clear();
			for (int i = 1 ; i <= n ; i++)
				if (calc(i) == op)
					v.push_back(a[i][op] - a[i][midd(i)]);
			sort(v.begin(), v.end());
			for (int i = 0 ; i < f[op] - n / 2 ; i++)
				ans -= v[i];
			printf("%d\n", ans);
		}
	}
	return 0;
}
