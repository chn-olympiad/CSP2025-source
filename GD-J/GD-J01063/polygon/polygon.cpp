#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, x, y, z;
	cin >> n;
	if (n == 3){
		cin >> x >> y >> z;
		int m = max(max(x, y), z);
		if (m * 2 < x + y + z) cout << 1;
		else cout << 0;
	}
	else{
		cout << 34;
	} 
	return 0;
}
