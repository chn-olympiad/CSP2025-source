#include<bits/stdc++.h>
using namespace std;
constexpr int MAXN = 100;
int n, m, a1, a[MAXN], cnt;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) cin >> a[i];
	a1 = a[1];
	sort(a + 1, a + n * m + 1);
	reverse(a + 1, a + n * m + 1);
	for(int i = 1; i <= n; i++) {
		if(i % 2) for(int j = 1; j <= m; j++) {
			if(a[++cnt] == a1) {
				cout << i << ' ' << j << endl;
				return 0;
			}
		}
		else for(int j = m; j; j--) {
			if(a[++cnt] == a1) {
				cout << i << ' ' << j << endl;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
