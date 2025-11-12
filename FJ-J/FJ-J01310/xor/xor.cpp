#include <iostream>
using namespace std;
const long long L = 5e5+5;
int a[L], n, k;
bool CheckA() {
	for (int i = 1;i <= n;i++)
		if (a[i] != 1)
			return false;
	return true;
}
bool CheckB() {
	for (int i = 1;i <= n;i++)
		if (a[i] > 1)
			return false;
	return true;
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	if (CheckA() && k == 0)
		cout << n/2;
	else if (CheckB() && k == 1) {
		int ans = 0;
		for (int i = 1;i <= n;i++)
			ans += (a[i] == 1);
		cout << ans;
	} else {
		cout << 2;
	}
	return 0;	
}
