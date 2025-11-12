#include <bits/stdc++.h>
#define inc(i, l, r) for(int i = l; i <= r; ++i)
#define dec(i, l, r) for(int i = l; i >= r; --i) 
using namespace std;

const int N = 10 + 5;
int n, m, a[N], k, mp[N][N];
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
	int ind = 0;
	inc(i, 1, n) {
		inc(j, 1, m) {
			cin >> a[++ind];
		}
	}
	k = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	inc(i, 1, n * m) {
		if(a[i] == k) {
			if(i % n == 0) {
				cout << i / n  << " " << n << '\n';
			} else {
				if((i / n) % 2 == 1) {
					cout << i / n + 1 << " " << n - i % n + 1;
				} else {
					cout << i / n + 1 << " " << 0 + i % n;
				}
			}
			break;
		}
	}
	return 0; 
}
