#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	
	freopen("seat.in", "r", stdin);
	freopen("seat.ans", "w", stdout);
	
	int e[150];
	int n, m, r;
	cin >> n >> m;
	for (int i=1;i<=n*m;++i) {
		cin >> e[i];
	}
	r = e[1];
	sort(e+1, e+1+n*m, greater<int>());
	for (int i=1;i<=n*m;++i) {
		if (r==e[i]) {
			cout << i;
			int lie = (i-1)/n+1;
			int hang = lie&1?(i-1)%n+1:m-(i-1)%m;
			cout << lie << ' ' << hang;
			break;
		}
	}
	
	return 0;
} 
