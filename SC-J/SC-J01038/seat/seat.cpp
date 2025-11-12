#include<bits/stdc++.h>
using namespace std;
#define LL long long
bool cmp(int a, int b) {
	return a > b;
}
int stu[120];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, xiaoming, zw;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) cin >> stu[i];
	xiaoming = stu[1];
	sort(stu + 1, stu + n*m + 1, cmp);
	for (int i = 1; i <= n * m; i++) if (stu[i] == xiaoming) zw = i;
//	cout<<zw;
	if (zw % n == 0) cout << zw / n;
	else cout << zw / n + 1;
	cout  << ' ';
	if (zw % n == 1) {
		if ((zw / n  + 1) % 2 == 0) {
			if (zw % n == 0) cout << 1;
			else cout << n - zw % n + 1;//zw % n + n - 1
		} else {
			if (zw % n == 0) cout << n;
			else cout << zw % n ;
		}
	} else {
		if ((zw / (n + 1) + 1) % 2 == 0) {
			if (zw % n == 0) cout << 1;
			else cout << n - zw % n + 1;
		} else {
			if (zw % n == 0) cout << n;
			else cout << zw % n ;
		}
	}
	return 0;
}