#include<bits/stdc++.h>
using namespace std;
int n, m;
struct NODE {
	int gr, num;
} node[105];
bool cmp(NODE a, NODE b) {
	return a.gr > b.gr;
}
void dfs(int r, int c, int nu, bool dir) {
	if (node[nu].num == 1) {
		cout << c << " " << r;
		exit(0);
	}
	//cout << r << " " << c << " " << nu << " " << dir << "\n";
	if (c % 2 == 1 && r == n) {
		c++;
		dfs(r, c, ++nu, !dir);
	} else if (c % 2 == 0 && r == 1) {
		c++;
		dfs(r, c, ++nu, !dir);
	}
	if (dir == 0) {
		r++;
		dfs(r, c, ++nu, dir);
	} else if (dir == 1) {
		r--;
		dfs(r, c, ++nu, dir);
	}
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> node[i].gr;
		node[i].num = i;
	}
	sort(node + 1, node + n*m + 1, cmp);
	dfs(1, 1, 1, 0);
	return 0;
}