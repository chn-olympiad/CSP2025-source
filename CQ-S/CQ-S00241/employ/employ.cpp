#include <bits/stdc++.h>
using namespace std;
int n, m, a[1000005], ans, o, f[1000005], b[1000005];
string s;
void fun(int x) {
	if (x == n + 1) {
		ans++;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!f[i] && a[i] > o && a[i] >= b[x - 1]) {
//			cout << x << " " << i << endl;
			f[i] = 1;
			if (s[x - 1] == '0') {
				o++;
			}
			b[x] = a[i];
			fun(x + 1);
			f[i] = 0;
			o--;
		}
	}
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	fun(1);
	cout << ans;
	return 0;
}
