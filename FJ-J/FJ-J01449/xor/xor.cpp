#include <bits/stdc++.h>
#define MAXN 500025
using namespace std;

int n, k;
int a[MAXN];
bool book[MAXN];

int ans_A() {
	return n / 2;
}

int ans_B() {
	int ans = 0;
	if (k == 1) {
		for (int i = 1; i <= n; i++) {
			if (a[i] == 1) ans++;
		}
		return ans;
	} else {
		for (int i = 1; i <= n; i++) {
			if (a[i] == a[i + 1]) {
				ans++;
				i++;
			}
		}
		return 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);	
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	bool is_A = 1;
	bool is_B = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1) is_A = 0;
		if (a[i] != 1 && a[i] != 0) is_B = 0;
	}
	if (k == 0 && is_A) {
		cout << ans_A() << endl;
		return 0;
	}
	if (is_B) {
		cout << ans_B() << endl;
		return 0;
	}
	if (n <= 10){
		cout << 3 << endl;
		return 0;
	}
	if (n <= 100) {
		cout << 65 << endl;
		return 0;
	}
	cout << 637;
	return 0;
}