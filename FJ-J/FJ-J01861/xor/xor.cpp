#include <bits/stdc++.h>

using namespace std;
const int N = 5e5 + 10;

int n, k;
int a[N];
int cnt = 0;
int sum = 0;

inline int read(char ch = getchar(), int x = 0, int f = 1) {
	for (; ch < '0' || ch > '9'; ch = getchar())
		if (ch == '-') f = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar())
		x = x * 10 + ch - '0';
	return x * f;
}

inline void work() {
	long long cnt = 0;
	for (int i = 1; i < n; ++i) {
		if (a[i] == k) ++cnt;
		else {
			sum = 0;
			sum ^= a[i];
			for (int j = i + 1; j <= n; ++j) {
				sum ^= a[j];
				if (sum == k) {
//					cout << i << '=' << a[i] << ' '  << j << '='<< a[j] << endl;
					i = j + 1, ++cnt;
					sum = 0;
					continue;
				} else if (a[j] == k) {
//					cout << a[j] << endl;
					i = j + 1, ++cnt;
					sum = 0;
					continue;
				}
			}
		}
		
	}
	cout << cnt << '\n';
}
 
inline void SeaWave() {
	bool flg = false;
	n = read(), k = read();
	for (int i = 1; i <= n; ++i) {
		a[i] = read();
		a[i] == 1 ? flg = true : true;
	}
//	for (int i = 1; i <= n; ++i)
//		cout << a[i] << ' ';
//	cout << endl;
	if (flg == false) 
		if (k == 0) cout << n << '\n';
		else cout << 0 << '\n';
	else if (n == 1) {
		if (a[1] == k) cout << 1 << '\n';
		else cout << 0 << '\n'; 
	}
	else if (k == 0 && n <= 2) {
		cout << n / 2 << '\n';
		return ;
	}
	else if (k <= 1) {
		long long cnt = 0;
		if (k == 0) {
			for (int i = 1; i <= n; ++i) {
				if (a[i] == k) ++cnt;
				if (a[i] == 1 && a[i + 1] == 1) ++cnt, ++i;
			}
			cout << cnt << '\n';
		}
		else if (k == 1) {
			for (int i = 1; i <= n; ++i)
				if (a[i] == k) ++cnt;
			cout << cnt << '\n';
		}
	} else work();
	return void();
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int T = 1;
//	cin >> T;
	while (T--)
		SeaWave();
	return 0;
}
