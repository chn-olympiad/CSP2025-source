#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	cout << n / 2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}