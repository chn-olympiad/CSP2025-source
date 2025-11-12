#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int T, n, mxa[N], mxb[N], mxc[N], a, b, c;
struct node {int a, b, c;} p[N];
bool cmp(int x, int y) {return p[x].a - max(p[x].b, p[x].c) > p[y].a - max(p[y].b, p[y].c);}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n, a = b = c = 0;
		memset(mxa, 0, sizeof(mxa)), memset(mxb, 0, sizeof(mxb)), memset(mxc, 0, sizeof(mxc));
		for (int i = 1; i <= n; i++) {
			cin >> p[i].a >> p[i].b >> p[i].c;
			if (p[i].a == max(p[i].a, max(p[i].b, p[i].c))) mxa[++a] = i;
			else if (p[i].b == max(p[i].a, max(p[i].b, p[i].c))) mxb[++b] = i;
			else if (p[i].c == max(p[i].a, max(p[i].b, p[i].c))) mxc[++c] = i;
		}
		if (b > n / 2) {
			swap(a, b), swap(mxa, mxb);
			for (int i = 1; i <= n; i++) swap(p[i].a, p[i].b);
		}
		if (c > n / 2) {
			swap(a, c), swap(mxa, mxc);
			for (int i = 1; i <= n; i++) swap(p[i].a, p[i].c);
		}
		if (a > n / 2) {
			sort(mxa + 1, mxa + a + 1, cmp);
			for (int j = n / 2 + 1; j <= a; j++) {
				if (p[mxa[j]].b > p[mxa[j]].c) mxb[++b] = mxa[j];
				else mxc[++c] = mxa[j];
			}
			a = n / 2;
		}
		int ans = 0;
		for (int i = 1; i <= a; i++) ans += p[mxa[i]].a;
		for (int i = 1; i <= b; i++) ans += p[mxb[i]].b;
		for (int i = 1; i <= c; i++) ans += p[mxc[i]].c;
		cout << ans << '\n';
	}
	return 0;
}