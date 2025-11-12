#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

long long n, m, a[100], mp[10][10], c, r, fir, f;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 0; i < n * m; i++)
		cin >> a[i];
	fir = a[0];
	sort(a, a + n*m, greater<int>());
	for(int i = 0; i < m; i++) {
		if(i % 2) {
			for(int j = n - 1; j >= 0; j--) {
				mp[j][i] = a[f];
				if(a[f] == fir) {
					cout << i + 1 << " " << j + 1;
					return 0;
				}
				f++;
			}
		} else {
			for(int j = 0; j < n; j++) {
				mp[j][i] = a[f];
				if(a[f] == fir) {
					cout << i + 1 << " " << j + 1;
					return 0;
				}
				f++;
			}
		}
	}
	return 0;
} 