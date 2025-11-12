#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
long long a[N];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	long long s = a[1], xiabiao = 0;
	sort(a + 1, a + 1 + n*m, greater<int>());
	for (int i = 1; i <= n * m; i++) {
		if (s == a[i]) {
			xiabiao = i;
			break;
		}
	}
	double flt = 1.0 * xiabiao / n;
	long long num = ceil(flt);
	if (num % 2 == 1) {
		if (xiabiao % n == 0) cout << num << " " << n + xiabiao % n;
		else cout << num << " " << xiabiao % n;
	} else {
		if(xiabiao % n == 0) cout << num << " " << xiabiao % n + 1;
		else cout << num << " " << n - xiabiao % n + 1;
	}
}