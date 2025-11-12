#include<iostream>
using namespace std;
int main() {
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	int n;
	cin >> n;
	long long k = 1;
	for (int i = 4; i <= n; i++) k = k * 4 % 998244353;
	cout << k;
	return 0;
}
