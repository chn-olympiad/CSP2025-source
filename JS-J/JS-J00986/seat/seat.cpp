#include <algorithm>
#include <iostream>
using namespace std;

int n, m;
int a[105], s[15][15], r;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> m;
	for (int i=0; i<n*m; ++i) {
		cin >> a[i];
	}
	r = a[0];//put XiaoR's grade
	sort(a, a+n*m, greater<int>());
	int k = 0;//k for the kth grade
	for (int i=0; i<m; ++i) {
		//i for lie, j for hang
		if (i & 1) {
			//j from n-1 to 0
			for (int j=n-1; j>=0; --j) {
				s[j][i] = a[k++];
				if (s[j][i] == r) {
					cout << i+1 << ' ' << j+1;
					return 0;
				}
			}
		} else {
			//j from 0 to n-1
			for (int j=0; j<n; ++j) {
				s[j][i] = a[k++];
				if (s[j][i] == r) {
					cout<< i+1 << ' '  << j+1;
					return 0;
				}
			}
		}
	}
	return 0;
}
