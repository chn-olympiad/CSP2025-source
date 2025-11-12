#include <bits/stdc++.h>
using namespace std;
int n, m, in[105], r_mark, r_p, c, r;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) {
		cin >> in[i];
		in[i] = 0 - in[i];
	}
	r_mark = in[1];
	sort(in + 1, in + n * m + 1);
	for(int i = 1; i <= n * m; i++) {
		if(in[i] == r_mark) {
			r_p = i;
			break;
		}
	}
	if(r_p % n == 0)	c = r_p / n;
	else	c = r_p / n + 1;
	if(c % 2 == 1)	r = r_p % n;
	else	r = n - r_p % n + 1;
	cout << c << ' ' << r;	
	return 0;
}
