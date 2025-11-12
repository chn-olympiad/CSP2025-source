#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;
int n, m, tot, a[105];

bool cmp(const int &x, const int &y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	tot = n * m;
	for (int i = 1; i <= tot; i++) cin >> a[i];
	int x = a[1], y = -1;
	sort(a + 1, a + tot + 1, cmp);
	for (int i = 1; i <= tot; i++) {
		if (a[i] == x) {
			y = i;
			break;
		}
	}
	int h = 0, l = 1;
	while (y--) {
		if (h == n && l % 2 != 0) l++, h = n;
		else if (h == 1 && l % 2 == 0) l++, h = 1;
		else if (l % 2 != 0) h++;
		else h--;
	}
	cout << l << " " << h;
	return 0;
}

