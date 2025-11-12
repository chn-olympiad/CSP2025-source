#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[1000005];
ll cnt[105];
bool cmp(ll x, ll y) {
	return x > y;
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", a);
	ll len = strlen(a);
	for (ll i = 0; i < len; i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			cnt[a[i] - '0']++;
		}
	}
	for (ll i = 9; i >= 0; i--) {
		for (ll j = 1; j <= cnt[i]; j++) {
			printf("%lld", i);
		}
	}
	return 0;
}