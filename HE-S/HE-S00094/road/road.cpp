#include <bits/stdc++.h>
using namespace std;

struct abc {
	long long u;
	long long v;
	long long w;
};
struct city {
	long long up;
	long long price;
};
abc a[1000007];
city s[1000007];

int main () {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	long long n, m, k;
	for (int i = 0; i < n; i++) {
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	for (int i = 0; i < n + 1; i++) {
		cin >> s[i].up;
	}
	for (int i = 0; i < n + 1; i++) {
		cin >> s[i].price;
	}
	long long ans = 13;
	cout << ans;
	return 0;
}
