#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], stu, pts;
bool cmp(int p, int q) {
	return p > q;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	stu = n * m;
	for(int i = 1; i <= stu; i++)
		cin >> a[i];
	pts = a[1];
	sort(a + 1, a + stu + 1, cmp);
	for(int i = 1; i <= stu; i++) 
		if(a[i] == pts) {
			int c, r;
			if(!(i % n)) r = n;
			else r = i % n;
			c = (i + n - 1) / n;
			if(!(c % 2)) r = n + 1 - r;
			cout << c << " " << r;
			return 0;
		}
}