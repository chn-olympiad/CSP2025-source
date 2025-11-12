#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
using namespace std;

#define MAX_VAL 1048576
#define MAX_N 500000
int n, k, a[MAX_N + 5], tong[MAX_VAL + 5], lst, ans;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	memset(tong, -1, sizeof(tong));
	tong[0] = 0;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		a[i] = a[i] ^ a[i - 1];
		if (tong[a[i] ^ k] != -1) 
			if (tong[a[i] ^ k] + 1 > lst) {
				lst = i;
				ans++;
			}
		tong[a[i]] = i;
	}
	printf("%d", ans);
	return 0;
}

