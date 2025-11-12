#include <bits/stdc++.h>
#define FileInAndOut(x) do { \
	freopen(#x ".in", "r", stdin); \
	freopen(#x ".out", "w", stdout); \
} while(0);
using namespace std;

int main() {
	FileInAndOut(employ)
	
	int n, m; cin >> n >> m;
	string u; cin >> u;
	int arr[n + 1];
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	cout << m % 998244353 << endl;
	return 0;
}
