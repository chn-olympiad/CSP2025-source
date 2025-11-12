#include <iostream>
using namespace std;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	int n, k;
	cin >> n >> k;
	if (k == 0) {
		// A
		int cnt1 = 0, cnt0 = 0, v;
		for (int i = 0; i < n; i++) {
			cin >> v;
			if (v == 1) cnt1++;
			if (v == 0) cnt0++;
		}
		cout << (cnt1 >> 1) + cnt0;	
	} else if (k == 1) {
		// B
		int cnt1 = 0, v;
		for (int i = 0; i < n; i++) {
			cin >> v;
			if (v == 1) cnt1++;
		}
		cout << cnt1;	
	} else cout << 0;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
