#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e6 + 5;
const int mod = 998244353;
ll n, m;
string s;
ll a[maxn], b[maxn];
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	s = '0' + s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = i;
	}
	ll ans = 0;
	do {
		ll sum = 0;
		ll y = 0;
		for (int i = 1; i <= n; i++) {
			int j = b[i];
			if(sum >= a[j]) {
				sum++;
				continue;
			}
			if(s[i] == '1') {
				y++;
			}else {
				sum++;
			}
		}
		if(y >= m) ans++, ans %= mod;
	}while(next_permutation(b + 1, b + 1 + n));
	cout << ans;
	return 0;
} 
