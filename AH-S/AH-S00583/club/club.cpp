#include<iostream>
#include<algorithm>
using namespace std;
int t, n, Ans;
struct node {
	int m1, m2;
	bool operator < (node b) {
		return m1 - m2 < b.m1 - b.m2;
	}
} A[100005], B[100005], C[100005];
int C1, C2, C3;
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> n;
		Ans = C1 = C2 = C3 = 0;
		for (int i = 1; i <= n; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			if (a >= b && a >= c) {
				A[++C1] = {a, max(b, c)};
				Ans += a;
			} else if (b >= a && b >= c) {
				B[++C2] = {b, max(a, c)};
				Ans += b;
			} else {
				C[++C3] = {c, max(a, b)};
				Ans += c;
			}
		}
		if (C1 > n / 2) {
			sort(A + 1, A + C1 + 1);
			for (int i = 1; i <= C1 - n / 2; i++) {
				Ans -= A[i].m1 - A[i].m2;
			}
		}
		if (C2 > n / 2) {
			sort(B + 1, B + C2 + 1);
			for (int i = 1; i <= C2 - n / 2; i++) {
				Ans -= B[i].m1 - B[i].m2;
			}
		}
		if (C3 > n / 2) {
			sort(C + 1, C + C3 + 1);
			for (int i = 1; i <= C3 - n / 2; i++) {
				Ans -= C[i].m1 - C[i].m2;
			}
		}
		cout << Ans << '\n';
	}
	return 0;
}
//               一路走好
//             王狗灏、来中杨
//              ^   ^   ^
//                & & &
//                | | |
//                \ | /
//                 |||
//                 |||
//                 |||
//            -------------
//T1, too water.
//OK  100pts
