#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int a[N], t[N];
bool f[260];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	int n, k, ans = 0;
	cin >> n >> k ;
	
	for(int i = 1;i <= n;i++) {
		cin >> a[i] ;
		t[i] = t[i - 1] xor a[i];
	}
	
	f[0] = 1;
	for(int i = 1;i <= n;i++) {
		int ne = k xor t[i];
		if(f[ne]) {
			ans++;
			for(int j = 0;j <= 259;j++) {
				f[j] = 0;
			}
		}
		f[t[i]] = 1;
	}
	cout << ans ;
	
	return 0;
}
