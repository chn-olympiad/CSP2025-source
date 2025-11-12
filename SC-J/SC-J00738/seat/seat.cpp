#include <iostream>
#include <bits/stl_algo.h>

using namespace std;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	{
		ios::sync_with_stdio()
;		long long n, m, o;
		cin >> n >> m;
		o = n*m;
		int a[o + 3];
		for (int i = 1; i <= o; i++) {
			cin >> a[i];

		}
		int xm = a[1];
		int loc;
		stable_sort(a, a + o + 2);
		int k = 0;
		for (int i = o; i >= 1; i--) {

			if (a[i] == xm) {
				loc = k;
			}
			k++;

		}
		//clog<<"loc:"<<loc<<endl;
		int tt = 1;

		for (int i = 1; i <= m;) {
			for (int j = 1; j <= n; j++) {
				if (tt == loc)cout << i << ' ' << j;
				tt += 1;
			}
			i++;
			for (int j = n; j >= 1; j--) {
				if (tt == loc)cout << i << ' ' << j;
				tt += 1;
			}
			i++;
		}
	}
	return 0;
}