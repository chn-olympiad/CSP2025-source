#include <bits/stdc++.h>
using namespace std;
const int N = 230;
int main () {
	int n, k, a [N];
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a [i];
		if (a [i] == k) cout << "1";
		else if (k == 2 || k == 3) cout << "2";
		else cout << 3;
	}
	
	return 0;
}
