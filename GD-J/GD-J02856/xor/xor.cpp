#include <bits/stdc++.h>
#define fin for (int i = 1; i <= n; i++)
#define fjm for (int j = 1; j <= m; j++)
using namespace std;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1);
	bool aaa = 1;
	int cnt = 0;
	fin {
		cin >> a[i];
		if (a[i] == 0) aaa = 0;
		if (a[i] == 1) cnt ++;
	}
	if (aaa == 0 && k == 1) cout << cnt << endl;
	else if (aaa == 0 && k == 0) cout << n - cnt + cnt / 2 << endl;
	else if (aaa == 1) cout << n / 2 << endl;
	return 0;
} 
