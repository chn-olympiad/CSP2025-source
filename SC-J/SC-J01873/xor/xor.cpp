#include<bits/stdc++.h>
#define AC return 0
#define ll unsigned long long // Alert!
const int MAXN = 5e5 + 5;
const int MAXD = 1e8;
using namespace std;

int n, k, cnt = 0, l = 0, r = 0, ncnt = 0, a[40], b[40];
ll an[MAXN];

// WHY THERE IS SOMEONE ENJOYING HIS SNACKS
// CCF or OIers, PLS DO STH

// low efficiency but i do not care
// i don't even know whether if this is corect LOL
void get_binary_a (ll x) {
	for (int i = 0; i < 21; i++) a[i] = 0;
	for (int i = 20; i >= 0; i--) {
		ll y = (ll)pow(2, i);
		if (y > x) continue;
		if (!(x % y)) a[i]++, x -= y;
	}
	return;
}

void get_binary_b (ll x) {
	for (int i = 0; i < 21; i++) b[i] = 0;
	for (int i = 20; i >= 0; i--) {
		ll y = (ll)pow(2, i);
		if (y > x) continue;
		if (!(x % y)) b[i]++, x -= y;
	}
	return;
}

ll convert_binary (int x[]) {
	ll res = 0;
	for (int i = 0; i < 21; i++) if (x[i]) res += pow(2, i);
	return res;
}

int binary_converted (ll x, ll y) {
	get_binary_a(x);
	get_binary_b(y);
	int res[40] = {0};
	for (int i = 0; i < 21; i++) res[i] += a[i] ^ b[i];
	return convert_binary(res);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> an[i];
	ll current = an[0];
	while (l < n) { // two pointers
		//cout << "l = " << l << ", r= " << r << ", current =" << current << '\n';
		ncnt++;
		if (ncnt >= MAXD) break; // RP++
		if (current == (ll)k) l = r + 1, r = l, current = an[l], cnt++;
		else {
			r++;
			if (r == n) {
				l++, r = l;
				current = an[l];
				continue;
			}
			current = binary_converted(current, an[r]);
		}
	}
	cout << cnt;
	AC;
}