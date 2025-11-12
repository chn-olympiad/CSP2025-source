#include <iostream>
#include <stdio.h>
#define __Debug

using namespace std;
typedef long long ll;

const int N = 5e2 + 10;
const int MOD = 998244353;

int n, m;
int a[N];
char c[N];

namespace PtsA {
	int Calc(int n) {
		ll sum = 1;
		for (int i = 1; i <= n; i++) {
			sum = (sum * i) % MOD;	
		}
		return sum;
	}	
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin.tie(nullptr) -> ios::sync_with_stdio(false);
	cin >> n >> m;
	bool flag1 = true;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		if (c[i] == '0') flag1 = false;
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 0) cnt++;
		printf("%d ", a[i]);
	}
	printf("\n");
	if (flag1) {
		using namespace PtsA;
		printf("%d\n", Calc(n - cnt));
		return 0;
	}
	return 0;
}

