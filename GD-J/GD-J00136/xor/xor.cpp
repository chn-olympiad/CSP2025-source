#include<bits/stdc++.h>
using namespace std;
int n, k, ans;
int num[500005];

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++) {
		cin >> num[i];
	}
	if(k == 1) {
		for(int i = 1 ; i <= n ; i++) {
			if(num[i] == 1) ans++;
		}
	}else if(k == 0) {
		for(int i = 1 ; i <= n ; i++) {
			if(num[i] == 0) {
				ans++;
			}
			else if(i < n) {
				if(num[i] ^ num[i + 1] == 0) {
					ans++;
					i++;
				}
			}
		}
	}
	else {
		for(int i = 1 ; i <= n ; i++) {
			int xo = num[i];
			if(xo == k) {
				ans++;
				i++;
			}
			for(int j = i + 1 ; j <= n ; j++) {
				xo = xo ^ num[j];
				if(xo == k) {
					ans++;
					i = j + 1;
					break;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
	
