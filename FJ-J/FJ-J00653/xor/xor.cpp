#include<bits/stdc++.h>
using namespace std;
//40 pts
int qa[500050];
int biao[500050];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> qa[i];
		qa[i] ^= qa[i - 1];
	}
	long long ans = 0;
	for(int l = 1; l <= n; l++) {
		for(int i = l; i <= n; i++) {
//			while(biao[i] != 0 && i <= n - l + 1) {
//				i += biao[i];
//			}
//			for(int j = 1; j <= n; j++) {
//				cout << "biao[" << j << "] = " << biao[j];
//			}
//			#define debug(x) cout << "\t" << #x << " = " <<x;
//			debug(l)
//			debug(ans)
//			debug(i)
//			cout << endl; 1111111
			bool flag = false;
			for(int j = i - l + 1; j <= i; j++) {
				if(biao[j]) {
					flag = true;
					break;
				}
			}
			if(flag) continue;
			if((qa[i - l] ^ qa[i]) == k) {
				ans++;
//				biao[i] = l;
				for(int j = i - l + 1; j <= i; j++) {
					biao[j] = 1;
				} 
			}
		}
	}
	cout << ans;
	return 0;
}
