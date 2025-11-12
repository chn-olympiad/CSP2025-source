#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, k, a[N], s[N];
int lm[N], mlm[N], ans;
//m是每个数往后异或可以最先得到k的右端点
//mlm是每个数后面所有数往后异或可以最先得到k的右端点 
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout); 
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i], s[i] = s[i - 1] ^ a[i];
	memset(lm, 0x3f, sizeof(lm));
	memset(mlm, 0x3f, sizeof(mlm));
	for(int i = 1; i <= n; i++) {
		if(a[i] == k) {
			lm[i] = i;
			continue;
		}
		for(int j = i + 1; j <= n; j++) {
			if((s[i - 1] ^ s[j]) == k) {
				lm[i] = j;
				break;
			}
		}
	}
	for(int i = n; i >= 1; i--) mlm[i] = min(mlm[i + 1], lm[i]);
	int at;
	for(at = 1; at <= n;) {
		if(mlm[at] != 0x3f3f3f3f) ans++;
		at = mlm[at] + 1;
	}
	cout << ans << endl;
	return 0;
}