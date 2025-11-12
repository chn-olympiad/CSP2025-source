#include<bits/stdc++.h>
using namespace std;
int n, m;
struct Node {
	int cheng;
	int w;
} a[110];
int cnt = 1;
bool cmp(Node x, Node y) {
	if (x.cheng != y.cheng)
		return x.cheng > y.cheng;
	else {
		return x.w < y.w;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i].cheng;
		a[i].w = i;
	}
	sort(a + 1, a + 1 + n * m, cmp);
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j <= m; j++) {
				if (a[cnt].w == 1) {
					cout << i << ' ' << j;
					return 0;
				}
				cnt++;
			}
		} else {
			for (int j = m; j >= 1; j--) {
				if (a[cnt].w == 1) {
					cout << i << ' ' << j;
					return 0;
				}
				cnt++;
			}
		}
	}
	return 0;
}