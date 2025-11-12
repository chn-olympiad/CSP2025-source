#include<bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 10;
int a[N];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	int ans1 = 0;
	int first_value = a[0];
	if(k == 1) {
		for(int i = 0; i < n; i++) {
			if(a[i] == 1) {
				
			}
			if(a[i] != first_value) {
				ans++;
				first_value = a[i+1];
				continue;
			}
		}
		for(int i = 0; i < n; i++) {
			if(a[i] == 1) {
				ans1++;
			}
		}
	}
	if(k == 0) {
		for(int i = 0; i < n; i++) {
			if(a[i] != first_value) {
				ans++;
				first_value = a[i];
			}
		}
		ans++;
//		for(int i = 0; i < n; i++) {
//			if(a[i] == 0) {
//				ans1++;
//			}
//		}
		for(int i = 0; i < n; i++) {
			if(a[i] == 0) {
				ans1++;
			} else {
				ans1++;
				int j = i;
				while(true) {
					if(a[j] == 0) {
						i = j;
						break;
					}
					j++;
				}
			}
		}
	}
	cout << max(ans, ans1);
	
	return 0;
}
//100 1
//1 0 1 1 0 0 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 1 1 1 0 0 1 1 1 1 0 1 0 1 1 1 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 1 0 1 0 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 1 0 1 1 0 1 1 1 1 0 1 1 0 1 0 1 1 0 0 0 0 1
