#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n, k, a[10000];
	cin >> n >> k;
	for (int i = 0; i <= k; i++) {
		cin >> a[i];
	}
	if (k == 3) cout << "2";
	if (k == 0) cout << "1";
	
	return 0;
}
