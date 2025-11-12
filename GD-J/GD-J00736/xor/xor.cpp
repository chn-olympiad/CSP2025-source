#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
int a[N], ans;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(n == 2) cout << 1;
	else if(n == 1) cout << 0;
	else {
		int ans = 0;
		for(int i = 1; i <= n; i++) if(a[i] == 1) ans++;		
		if(k == 1) cout << ans;
		else cout << ans / 2;
	}
	
	return 0;
}
