#include<bits/stdc++.h>
using namespace std;

int n, m, a, d, c, r, q;
int ans = 1;

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m >> a;
	while (cin >> d) if (d > a) ans++;
	c = (ans - 1) / n + 1;
	if (ans % n == 0) q = n;
	else q = ans % n;
	if (c % 2 == 1) r = q;
	else r = n - q + 1;
	cout << c << " " << r << "\n";
	return 0;
}
