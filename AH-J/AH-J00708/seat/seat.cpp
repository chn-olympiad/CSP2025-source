#include <bits/stdc++.h>
using namespace std;
struct node{
	int g, id;
}a[1010];
int cmp(node x, node y) {
	return x.g > y.g;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out","w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i].g;
		a[i].id = i;
	}
	sort(a + 1, a + 1 + n * m, cmp);
	int q = 0;
	for (int i = 1; i <= n * m; i++) {
		if(a[i].id == 1) q = i;
	}
	int x = 0, y = 0;
	for (int i = 1; i <= q; i++) {
		if(x == 0 && y == 0) {
			x++, y++;
			continue;
		}
		if(y % 2 == 1) {
			if(x == n) y++;
			else x++;
		}
		else {
			if(x == 1) y++;
			else x--;
		}
	}
	cout << y << " " << x;
	return 0;
}
//#Shang4Shan3Ruo6Shui4
