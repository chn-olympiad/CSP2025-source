#include <bits/stdc++.h>
using namespace std;

int n, a[5010], ans;
bool f[5010];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	sort(a + 1, a + n + 1, cmp);
	
	if (n == 3) {
		if ((a[1] + a[2] + a[3]) > (a[3] * 2)) {
			cout << 1;
			return 0;
		}
		else
			cout << 0;
	}
	
	return 0;
} 
