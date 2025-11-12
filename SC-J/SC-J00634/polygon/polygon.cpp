#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	int n;
	cin >> n;
	
	int a[10];
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	sort(a + 1, a + n + 1);
	
	if (n >= 3 && a[1] + a[2] + a[3] > a[3] * 2) {
		cout << 1 << endl;
	} else {
		cout << 0 << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}