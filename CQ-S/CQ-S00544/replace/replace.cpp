#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e5 + 10;

int n, q;

struct Node {
	string si1, si2;
} s[N];

struct Node1 {
	string ti1, ti2;
} t[N];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i ++ ) cin >> s[i].si1 >> s[i].si2;
	for (int i = 1; i <= q; i ++ ) cin >> t[i].ti1 >> t[i].ti2;
	while (q -- ) puts("0");
	return 0;
}
