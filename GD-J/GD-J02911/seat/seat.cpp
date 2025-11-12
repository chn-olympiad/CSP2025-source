#include <bits/stdc++.h>
using namespace std;

int n, m, t, a, d = -1;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, 1};
vector <int> s;
bool cmp(int aa, int bb) {
	return aa > bb;
}
void dfs(int x, int y) {
	if (s[t] == a) {
		cout << y << ' ' << x;
		return ;
	}
	if (x > n || x < 1 || y > m || y < 1) return ;
	if (x == n || x == 1) d = (d + 1) % 4;
	t++;
	dfs(x + dx[d], y + dy[d]);
	return;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= (n * m); i++) {
		cin >> a;
		s.push_back(a);
	}
	a = s[0];
	sort(s.begin(), s.end(), cmp);
	dfs(1, 1);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
