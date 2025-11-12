#include<bits/stdc++.h>
using namespace std;
int n[10001];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string a;
	cin >> a;
	int j = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			n[j] = a[i] - '0';
			j++;
		}
	}
	sort(n, n + j);
	for (int i = j - 1; i >= 0; i--) {
		cout << n[i];
	}
	return 0;
}
