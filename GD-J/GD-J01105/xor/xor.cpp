#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXN 500005
ll n,k,a[MAXN],d[MAXN],vis[MAXN];

bool is_A = true,is_B = true;

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		if(a[i] != 1 || k != 0) is_A = false; //特判A条件
		if(a[i] > 1 || k > 1) is_B = false;   //特判B条件 
		d[i] = a[i] ^ d[i-1];
	}
	
	if(is_A) {
		cout << ((n-1)*(n-2))/2;
		return 0;
	}
	if(is_B) {
		int ans = 0;
		if(k == 0) {
			for(int i = 1;i <= n;i++) {
				if(a[i] == 0) ans++;
				else if(a[i] + a[i+1] == 2) {
					ans++;
					i++;
				}
			}
		}
		if(k == 1) {
			for(int i = 1;i <= n;i++) {
				if(a[i] == 1) ans++;
				else if(a[i] + a[i+1] + a[i+3] == 3) {
					ans++;
					i+=2;
				}else if(a[i]+a[i+1] == 1) {
					ans++;
					i++;
				}
			}
		}
		cout << ans;
		return 0;
	}
	
	int ans = 0;
	for(int i = 1;i <= n;i++) {
		for(int j = i;j >= 1;j--) {
			if(vis[i]) continue;
			if((d[i] ^ d[j-1]) == k) {
				for(int k = j;k <= i;k++) vis[k] = true;
				ans++;
				break;
			}
		}
	}
	cout << ans;
	return 0;
	
} 
