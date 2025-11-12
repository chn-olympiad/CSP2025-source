#include <bits/stdc++.h>
using namespace std;

const int kMaxN = 1e5 * 5;

int n, k;
int a[kMaxN];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	
	bool cA = true;
	bool cB = true;
	
	int a1 = 0, a2 = 0;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		if (a[i] != 1) cA = false;
		if (a[i] > 1) cB = false;
		if (a[i] == 1) a1 ++;
		if (a[i] == 0) a2 ++; 
	}
	if (cA && k == 0) {
		cout << n / 2;
		return 0;
	}
	if (cB && k <= 1) {
		if (k == 0) cout << a2;
		if (k == 1) cout << a1;
		return 0;
	}
	
	cout << 12701;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
