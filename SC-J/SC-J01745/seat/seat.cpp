#include<bits/stdc++.h>
using namespace std;
int n, m;
struct hh {
	int f, s;
} a[200];
bool cmp(hh a, hh b) {
	return a.f > b.f;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i].f;
		a[i].s = i;
	}
	sort(a + 1, a + 1 + m*n, cmp);
	int top = 0;
	while (a[++top].s != 1) {

	}
	int c = top / n;
	int r = (top - 1) % n + 1;
	if (top/n*n!=top) c++;
	if (c % 2 == 0) r = n - r + 1;
	cout << c << " " << r;
	return 0;
}