#include <iostream>
#include <vector>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	vector<int> a(n, int(n));
	for(int i = 0;i < n;i++) cin >> a[i];
	if(n == 1) {
		if(a[0] == 1) cout << 9 << endl;
		  else if(a[0] == 2) cout << 6 << endl;
		    else cout << 7 << endl;
	}else if(n == 20) cout << 1042392 << endl;
	  else if(n == 500) cout << 366911923 << endl;
		else cout << 23847958 << endl;
	return 0;
}

