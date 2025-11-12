#include <bits/stdc++.h>
using namespace std;
struct Node {
	int id, val;
}a[100010];
bool cmp(Node a, Node b) {return a.val > b.val;}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) for (int j = 1; j <= n; j++) cin >> a[i * n + j].val, a[i * n + j].id = i * n + j;
	sort(a + 1, a + 1 + n * m, cmp);
	int x;
	for (int i = 1; i <= n * m; i++) if (a[i].id == 1) x = i;
	int y = x / n + 1, z = x % n;
	if (!z) y--, z = n;
	if (y & 1) cout << y << " " << z;
	else cout << y << " " << n - z + 1;
}
