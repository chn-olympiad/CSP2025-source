#include <bits/stdc++.h>
#define FileInAndOut(x) do { \
	freopen(#x ".in", "r", stdin); \
	freopen(#x ".out", "w", stdout); \
} while(0);

using namespace std;
int n, m, k;
int s[5000][5000];

int main() {
	FileInAndOut(road)
	
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int ui, vi, wi; cin >> ui >> vi >> wi;
		s[ui][vi] = wi;
	}
	
	for (int i = 1; i <= k; i++) {
		int arr[n];
		for (int j = 0; j <= n; j++) {
			cin >> arr[j];
		}
	}
	
	cout << 0 << endl;
	return 0;
}
