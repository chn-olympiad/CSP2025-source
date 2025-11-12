#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int n;
long long k, a[maxn], b[maxn], ans, vis[maxn][2];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	b[0] = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = b[i - 1] ^ a[i];
		//if(a[i] == k) ans++, vis[i] = 1;
	}
	for(int le = 1; le <= n; le++) {
		for(int i = 1; i <= n - le + 1; i++) {
			int j = i + le - 1;
			
			if(vis[i][1] || vis[i][0]) {
				continue;
			}
			if(vis[j][0]) {
				vis[j - 1][0] = 1;
			}
			if(vis[j][1]) {
				vis[i][0] = 1;
				i = j;
				continue;
			}
			
			long long p = b[j] ^ b[i - 1];
			if(p == k) {
				ans++;
				for(int l = i; l <= j; l++) vis[l][1] = 1;
				i = j;
			}
		}
	}
	cout << ans;
	return 0;
}
