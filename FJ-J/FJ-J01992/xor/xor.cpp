#include <bits/stdc++.h>

#define LL long long

using namespace std;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n[500005], t, k;
	cin>>t>>k;
	for (int i = 0; i < t; i++) cin>>n[i];
	int sum = 0;
	//  1 2 3 4
	// [0 1 2 3] // index
	bool d[t + 5] = {false};
	for (int i = 0; i < t; i++) {
		for (int j = 0; j <= t - 1 - i; j++) {
			LL v = n[j];
			for (int k = 1; k <= i; k++) {
				v ^= n[j + k];
			}
			if (v == k) {
				bool flag = true;
				for (int k = j; k <= j + i; k++) {
					if (!d[k]) {
						d[k] = true;
					} else {
						flag = false;
					}
				}
				if (flag) sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}

