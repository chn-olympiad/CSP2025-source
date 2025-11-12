#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int T;
int n;
struct ss {
	int a1,a2,a3;
	int mx;
}a[N];
bool cmp(ss x, ss y) {
	return x.a1 >= y.a1;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdin);
	cin >> T;
	while (T -- ) {
		cin >> n;
		int A1, A2, A3, aa3, aa2, aa1;
		A1 = A2 = A3 = 0;
		aa1 = aa2 = aa3 = 0;
		for (int i = 1; i <= n; i ++ ) cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
		bool st = 0;
		for (int i = 1; i <= n; i ++ ) {
			if (a[i].a2 != 0 || a[i].a3 != 0) {
				break;
				st = 1;
			}
		}
		if (st == 0) {
			sort(a + 1, a + n + 1, cmp);
			int sum = 0;
			for (int i = 1; i <= n; i ++ ) sum += a[i].a1;
			cout << sum << endl;
		}
		for (int i = 1; i <= n; i ++ ) {
			if (a[i].a1 >= a[i].a2 && a[i].a1 >= a[i].a3) A1 ++ ,aa1 += a[i].a1;
			else if (a[i].a2 >= a[i].a1 && a[i].a2 >= a[i].a3) A2 ++ ,aa2 += a[i].a2;
			else if (a[i].a3 >= a[i].a2 && a[i].a3 >= a[i].a1) A3 ++ ,aa3 += a[i].a3;
		}
		//cout << A1 << ' ' << A2 << ' ' << A3 << endl; 
		if (A1 <= n/2 && A2 <= n/2 && A3 <= n/2) cout << aa1 + aa2 + aa3 << endl;
		//
	//	else {
	//		if(A1 > n/2) 
	//	}
	}
	return 0;
}
