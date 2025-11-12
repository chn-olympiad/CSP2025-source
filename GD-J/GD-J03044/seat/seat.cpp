#include<bits/stdc++.h>
using namespace std;
const int N = 107;
int a[N];
bool cmp(int x, int y) { return x > y; }
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.in", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n*m; ++i) cin >> a[i];
	int p = a[1];
	sort(a+1, a+1+n*m, cmp);
	int x = 1, y = 1, top = 1;
	while(a[top] != p) {
		if ((y % 2 == 1 && x == n) || (y % 2 == 0 && x == 1)) y++;
		else {
			if (y % 2 == 0) x--;
			else x++;
		}
		top++;
	}
	cout << y << " " << x;
	return 0;
}
