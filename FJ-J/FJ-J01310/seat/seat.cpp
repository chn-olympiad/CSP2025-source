#include <iostream>
#include <algorithm>
using namespace std;
int a[110], n, m;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n*m;i++)
		cin >> a[i];
	int r = a[1];
	sort(a+1, a+n*m+1, greater<int>());
	int pos;
	for (int i = 1;i <= n*m;i++)
		if (a[i] == r) {
			pos = i;
			break;
		}
	if (pos % n == 0)
		cout << pos/n << " " << ((pos/n%2)?n:1);
	else
		cout << pos/n+1 << " " << (((pos/n+1)%2)?pos%n:(n-pos%n));
	return 0;
}
