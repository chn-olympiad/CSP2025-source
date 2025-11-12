#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long T, n, ans, num[5], cntn, sum;
bool check[N];
struct node {
	long long a, id, from;
}x[N], y[N], z[N], e[N * 3];
bool cmp(node pos1, node pos2) {
	return pos1.a > pos2.a;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		cin >> n;
		sum = n;
		cntn = 0;
		ans = 0;
		memset(check, 0, sizeof(check));
		memset(num, 0, sizeof(num));
		for (int i = 1; i <= n; i++) {
			cin >> x[i].a >> y[i].a >> z[i].a;
			x[i].id = y[i].id = z[i].id = i;
			x[i].from = 1;
			y[i].from = 2;
			z[i].from = 3;
			e[i * 3 - 2] = x[i];
			e[i * 3 - 1] = y[i];
			e[i * 3] = z[i];
		}
		if (n == 2) {
			cout << max(x[1].a + y[2].a, max(x[1].a + z[2].a, max(y[1].a + x[2].a, max(y[1].a + z[2].a, max(z[1].a + x[2].a, z[1].a + y[2].a)))));
			continue;
		}
		sort(e + 1, e + 3 * n + 1, cmp);
		while (sum--) {
			node maxn = e[++cntn];
			while (check[maxn.id] || num[maxn.from] == n / 2)
				maxn = e[++cntn];
			ans += maxn.a;
			check[maxn.id] = 1;
			num[maxn.from]++;
		}
		cout << ans << endl;
	}
	return 0;
}
