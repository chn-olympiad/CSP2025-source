// AH-J01016

#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const LL N = 15;

LL cnt[N];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (auto i : s) {
		if (isdigit(i)) cnt[i - 48]++;
	}
	for (LL i = 9; i >= 0; i--) {
		while (cnt[i]--) printf("%lld", i);
	}
	return 0;
}
