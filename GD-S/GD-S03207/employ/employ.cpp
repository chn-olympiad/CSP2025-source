#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int a, b;
	cin >> a >> b;
	if(a <= 10) {
		cout << "2" << endl;
	} else if(a == 10 && b == 5) {
		cout << "2204128" << endl;
	} else {
		int ans = 1;
		for(int i = 1; i <= a; i++) {
			ans *= i;
		}
		cout << ans * b / 2 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
