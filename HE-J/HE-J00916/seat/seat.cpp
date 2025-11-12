#include <iostream>
#include <cstdio> 
#include <cmath>
using namespace std;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, a1;
	cin >> n >> m >> a1;
	int place = 1;
	for (int i = 1; i < n * m; i++){
		int a;
		cin >> a;
		if (a > a1)place++;
	}
	if (int(ceil(place * 1.0 / n)) % 2 == 1)cout << ceil(place * 1.0 / n) << ' ' << place % (2 * n);
	else cout << ceil(place * 1.0 / n) << ' ' << ceil(place * 1.0 / n) * n - place + 1;
	return 0;
} 
