#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
int n, k, ans;
int a[500005];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0); 
	
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] = a[i] ^ a[i - 1];
	}
	
	int r = 0;
	int l = n;
	
	for(int len = 0; len <= n; len++){
		for(int i = 1; i <= n; i++){
			int j = i - len;
			if(len - i >= 0) continue;
			if(i <= r && i >= l) continue;
			if(j <= r && j >= l) continue;
			if(i > r && j < l) continue;  

			if(a[i] ^ a[j] < k){
				ans++;
				r = max(i, r);
				l = min(i, l);
				break;
			}
		}
	}
	
	cout << ans;
	return 0;
} 
