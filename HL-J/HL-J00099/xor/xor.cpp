#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int n, a[N], k, s[N], ans;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i-1] ^ a[i];
	}
	int l = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = l+1; j <= i; j++) {
			if ((s[i] ^ s[j-1]) == k) {
				ans++;
				l = i;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}

