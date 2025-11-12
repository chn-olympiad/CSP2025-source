#include<bits/stdc++.h>
using namespace std;
int n, m, t, ans;
struct e {int u, v;}a[105];
bool cmp (e x, e y) {return x.u > y.u;}
int main () {
//	freopen ("seat3.in", "r", stdin);
//	freopen ("seat1.out", "w", stdout);
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
	cin >> n >> m;
	t = n * m;
	for (int i = 1; i <= t; i++) cin >> a[i].u, a[i].v = i;
	sort (a + 1, a + t + 1, cmp);
	for (int i = 1; i <= t; i++) if (a[i].v == 1) ans = i;
//	for (int i = 1; i <= t; i++) cout << a[i].u << " " << a[i].v << endl;
//	cout << ans << endl;
	if (ans % n == 0) {
		cout << (ans / n) << " ";
		if ((ans / n) % 2) cout << n;
		else cout << 1;
	}
	else {
		cout << ((ans / n) + 1) << " ";
		if (((ans / n) + 1) % 2) cout << (ans % n);
		else cout << (n - (ans % n) + 1);
	} 
	return 0;
}

