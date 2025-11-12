#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, m;
struct T { int a, id; } t[N];
bool cmp(T x, T y) { return x.a > y.a; }
int x[N], y[N], cnt;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> t[i].a; t[i].id = i;
	} sort(t + 1, t + n * m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		if(i & 1) {
			for (int j = 1; j <= n; j++) x[++ cnt] = j, y[cnt] = i;
		}
		else { 
			for (int j = n; j >= 1; j--) x[++ cnt] = j, y[cnt] = i;
		}
	}
	for (int i = 1; i <= n * m; i++) {
		if(t[i].id == 1) {
			cout << y[i] << " " << x[i];
			return 0;
		}
	}
	return 0;
}
