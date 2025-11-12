#include <iostream>
#include <stdio.h>

using namespace std;

const long long kMod = 998244353;
long long ans = 1;
int n, m, a[510];
string str;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
    cin >> n >> m >> str;
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		ans = ans * i % kMod;
	}
	cout << ans;
	return 0;
}
