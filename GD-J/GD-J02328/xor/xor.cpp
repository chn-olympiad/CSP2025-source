#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;
int n, k;
int a[N];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	bool all_one = true;
	int one_cnt = 0, zero_cnt = 0;
	int eq_k = 0, ans = 0, dx = 0; 
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] == 1) {
			one_cnt++;
		} else {
			if(a[i] != 0) {
				all_one = false;
			} else {
				zero_cnt++;
			}
		}
		if(a[i] == k) {
			eq_k++;
		} else {
			a[++dx] = a[i];
		}
	}
	if(all_one) {
		if(k == 1) {
			cout << one_cnt;
		} else {
			cout << one_cnt / 2 + zero_cnt;
		}
		return 0;
	}
	int parts = 0, last = 0;
	
	for(int s = 1; s <= dx - 1; s++) {
		int tpt = 0;
		for(int i = s; i <= dx - 1; i++) {
			last = a[i];
			for(int j = i + 1; j <= dx; j++) {
				last ^= a[j];
				if(last == k) {
					i = j;
					tpt++;
					break;
				}
			}
		}
		parts = max(parts, tpt);
	}
	ans = eq_k + parts;
	cout << ans;
	return 0;
}
