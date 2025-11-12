#include <bits/stdc++.h>
#define int long long

using namespace std;
int n, k, a[500010], s[500010], len[500010], nxt[500010];
vector<pair<int, int>> v;
inline void spe() {
	for(int i = 1; i <= n; i++) 
		if(a[i] != 1) 
			return ;
	cout << n / 2 << '\n';
	exit(0);
}
inline void spe2() {
	for(int i = 1; i <= n; i++) {
		if(a[i] != 0 and a[i] != 1) 
			return ;
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] == k)
			cnt++;
	}
	cout << cnt << '\n';
	exit(0);
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) 
		cin >> a[i];
	spe();
	spe2();
	for(int i = 1; i <= n; i++) {
		s[i] = s[i - 1] ^ a[i];
	}
	memset(len, 127, sizeof len);
	for(int i = 1; i <= n; i++) {
		int j;
		for(j = i; j <= n; j++) {
			if(!(s[j] ^ s[i - 1] ^ k))
				break;
		}
		if(j != n + 1)
			len[i] = j - i + 1;
	}
	for(int i = 1; i <= n; i++) {
		int pos = n + 1, mn = 1ll << 62;
		for(int j = i; j <= n; j++) {
			int val = len[j] + j - i - 1;
			if(val < mn) {
				pos = j;
				mn = val;
			}
		}
		nxt[i] = pos + len[pos] - 1;
	}
	int cnt = 0;
	bool flag = false;
	for(int i = 1; i <= n; ) {
		if(i == nxt[i]) {
			flag = true;
			if(i == 1)
				cnt++, i++;
			else 
				i++;
		}
		else {
			if(nxt[i] <= n) 
				cnt++;
			i = nxt[i];
		}
	}
	cout << cnt + 1 << '\n';
	return 0; 
}