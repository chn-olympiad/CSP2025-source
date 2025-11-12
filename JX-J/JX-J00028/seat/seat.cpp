#include <bits/stdc++.h>
using namespace std;
int n, m;
struct stu{
	int id, w;
}a[110];
bool cmp(stu x, stu y) {
	return x.w > y.w;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int q = n * m;
	for(int i = 1; i <= q; i++) cin >> a[i].w, a[i].id = i;
	
	sort(a + 1, a + n * m + 1, cmp);
	int c = 0, r = 0;
	for(int i = 1; i <= q; i++) {
		if(a[i].id == 1) {
			c = i / n + i % n;
			if(c % 2) r = n - (c * n - i);
			else r = c * n - i + 1;
			cout << c << ' ' << r;
			break;
		}
	}
	return 0;
}
