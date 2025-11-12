#include<bits/stdc++.h>
using namespace std;

int n, k;
int a[1000005];

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
	}
	
	bool on = true;
	bool on2 = true;
	
	int cnt_1 = 0;
	
	for (int i = 1; i <= n; i ++) {
		if (a[i] != 1) {
			on = false;
		} 
		if (a[i] != 0 && a[i] != 1) {
			on2 = false;
		}
		
		cnt_1 += a[i];
	}
	
	// 情况1 
	if (on) {
		if (k == 1) {
			cout << n << endl;
		} else if (k == 0) {
			cout << n / 2 << endl;
		} else {
			cout << 0 << endl;
		}
	}
	// 情况2 
	else if (on2) {
		if (k == 1) {
			cout << cnt_1 << endl;
		} else if (k == 0) {
			bool on_a = false;
			int cnt_0 = 0;
			for (int i = 1; i <= n; i ++) {
				if (a[i] == 1 && a[i + 1] == 1) {
					a[i + 1] = 0;
					cnt_0 ++;
				}
			}
			cout << n - cnt_1 + cnt_0 << endl;
		} else {
			cout << 0 << endl;
		}
	} else {
		int cnt = 0;
		int x = 0;
		for (int i = 1; i <= n; i ++) {
			x ^= a[i];
			if (x == k) {
				cnt ++;
				x = 0;
			}
		}
		cout << cnt << endl;
	}
	
	return 0;
}


