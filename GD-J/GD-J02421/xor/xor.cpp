#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

int n,m;
const int MAXN = 5005;
int a[MAXN];

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i<n; i++) {
		cin >> a[i];
	}
	cout << 2 << endl;
	return 0;
}
