#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair <int, int>
#define endl "\n"

const int N = 105;
int a[N];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, m, s;
	cin >> n >> m;
	
	cin >> a[1];
	s = a[1];
	for (int i = 2; i <= n * m; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + n*m + 1, cmp);
	
	int pos = 1;
	for (int i = 1; i <= m; ++i) {
		if (i % 2 == 1) {
			for (int j = 1; j <= n; ++j) {
//				cout << i << "," << j << ":" << a[pos] << endl;
				if (a[pos] == s) {
					cout << i << " " << j;
					return 0;
				}
				++pos;
			}
		} else {
			for (int j = n; j >= 1; --j) {
				if (a[pos] == s) {
					cout << i << " " << j;
					return 0;
				}
				++pos;
			}
		}
	}
	
	return 0;
}
