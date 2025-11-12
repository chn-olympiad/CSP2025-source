//t2 seat
#include<iostream>
#include<algorithm>
#define rf(a, b, c) for(int b = (a); b <= (c); b++)
using namespace std;
int n, m, a[1000], rk, k, r, c;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	rf(1, i, n * m) cin >> a[i];
	k = a[1];
	sort(a + 1, a + n * m + 1);
	rk = lower_bound(a + 1, a + n * m, k) - a;
	rk = n * m - rk;
	c = rk / m + 1;
	r = rk % n + 1;
	if(c % 2 == 0) r = n - r + 1;
	cout << c << " " << r;
	return 0;
}
