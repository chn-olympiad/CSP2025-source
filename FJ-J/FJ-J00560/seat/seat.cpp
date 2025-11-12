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

#define MAX_N 10
#define MAX_M 10
int n, m, a[MAX_N * MAX_M + 5], mb;

bool cmp(int x, int y) {
	return x > y;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++) scanf("%d", &a[i]);
	mb = a[1];
	sort(a + 1, a + 1 + n * m, cmp);
	for (int i = 1; i <= n * m; i++) 
		if (a[i] == mb) {
			mb = i;
			break;
		}
	int tmp = mb / n;
	mb %= n;
	if (mb == 0) {
		mb += n;
		tmp--;
	}
	if (tmp % 2 == 1) printf("%d %d", tmp + 1, n - mb + 1);
	else printf("%d %d", tmp + 1, mb);
	return 0;
}

