#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	long long mod = 998244353;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int res = 0;
	for (int i = 1; i <= (n - 2) ; ++i) {
		res = res + i; 
		res = res % mod;
	}
	
	cout << res;
	fclose(stdin);
	fclose(stdout);
	return 0;
}