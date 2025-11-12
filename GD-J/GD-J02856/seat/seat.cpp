#include <bits/stdc++.h>
#define fin for (int i = 1; i <= n; i++)
#define fjm for (int j = 1; j <= m; j++)
using namespace std;
bool cmp(int a, int b) {
	return a > b;
}
vector<int> a;
int r, ansx, ansy, n, m;
void dfs(int pos, int x, int y) {
	if (a[pos] == r) {
		ansx = x;
		ansy = y;
		return ;
	}
	if (x % 2 == 1 && y != m) {
		dfs(pos + 1, x, y + 1); 
	}
	else if (x % 2 == 1 && y == m) {
		dfs(pos + 1, x + 1, y);
	}
	else if (x % 2 == 0 && y != 1) {
		dfs(pos + 1, x, y - 1);
	}
	else if (x % 2 == 0 && y == 1) {
		dfs(pos + 1, x + 1, y);
	}
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	a.resize(n * m + 1);
	for (int i = 1; i <= n * m; i++) cin >> a[i];
	r = a[1];
	sort(a.begin() + 1, a.end(), cmp);
	dfs(1, 1, 1);
	cout << ansx << ' ' << ansy << endl; 
	return 0;
} 
