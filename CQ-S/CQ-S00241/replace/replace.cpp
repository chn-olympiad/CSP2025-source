#include <bits/stdc++.h>
using namespace std;
int n, m;
struct st{
	string x, y;
}a[1000005];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].y;
	}
	string l, r;
	for (int i = 1; i <= m; i++) {
		cin >> l >> r;
		int ans = 0;
		for (int j = 1; j <= n; j++) {
			if (l == a[j].x && r == a[j].y) {
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

