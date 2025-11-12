#include<bits/stdc++.h>
using namespace std;
long long a[105];
bool cmp(long long x, long long y) {
	return x > y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for (long long i = 1; i <= n * m; i ++){
		cin >> a[i];
	}
	long long xr = a[1];
	sort(a + 1, a + 1 + n * m, cmp);
	long long id;
	for (long long i = 1; i <= n * m; i ++) {
		if (a[i] == xr) {
			id = i;
		}
	}
	long long an1 = id % (2 * n);
	long long an2 = (id - an1) / n + 1;
	if (an1 == 0) {
		an1 = n;
	}
	else if (an1 > n) {
		an1 = 2 * n - an1 + 1;
		an2 += 1;
	}
	cout << an2 << " " << an1 << '\n';
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
2 2
99 100 97 98
2 2
98 99 100 97
*/