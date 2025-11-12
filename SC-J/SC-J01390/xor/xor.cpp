#include <bits/stdc++.h>

using namespace std;

int n, m;
int main() {
	freopen ("xor.in", "r",stdin);
	freopen ("xor.out", "w",stdout);
	cin >> n >> m;
	int maxn = -1;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		maxn = max(maxn, x);
	}
	cout << maxn << endl;
	return 0; 
}