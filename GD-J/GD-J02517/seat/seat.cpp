#include <iostream>
#include <vector>
using namespace std;

int popss(vector<long> inum) {
	bool yes;
	int R = 0;
	for(int i = 0;i < inum.size() - 1;i++) {
		yes = true;
		for(int j = 1;j < inum.size();j++) {
			if(inum[j] > inum[j - 1]) {
				if(R == j) R = j - 1;
				  else if(R == j - 1) R = j;
				swap(inum[j], inum[j - 1]);
				yes = false;
			}
		}
		if(yes) break;
	}
	return R;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	int n, m, R;
	cin >> n >> m;
	vector<long> a(n * m, 0);
	for(int i = 0;i < n * m;i++) cin >> a[i];

	R = popss(a);
	cout << R / n + 1 << ' ';
	if((R / n) % 2) cout << n - (R % n);
	  else cout << R % n + 1;
	return 0;
}

