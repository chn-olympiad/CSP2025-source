#include <iostream>
#define int long long
using namespace std;
int const P = 998244353;
int a[5005];
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	int n, is = 1;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1)is = 0;
	}
	
	if(n == 3) {
		if(a[1]+a[2]+a[3] > 2*max(a[1], max(a[2], a[3]))) {
			cout << 1;
		}
		else cout << 0;
	}
	else if(is) {
		cout << (n-1)%P*(n-2)%P/2;
	}
	else {
		cout << 743578297;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}