#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5e5+5;
int sum[N];

struct node {
	int l, r;
}a[N];
int m;

bool cmp(node &n1, node &n2) {
	if (n1.r != n2.r)
		return n1.r < n2.r;
	else
		return n1.l > n2.l;
}

int main() {
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);

	int n, k;
	scanf ("%d%d", &n, &k);
	
	for (int i = 1; i <= n; i ++) {
		int tmp;
		scanf ("%d", &tmp);
		sum[i] = sum[i-1]^tmp;
	}
	
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= i; j ++) {
			if ((sum[i]^sum[j-1]) == k) {
				a[++ m] = (node){j, i};
			}
		}
	}
	
	sort (a + 1, a + n + 1, cmp);
	
	int R = -1, i = 1, ans = 0;
	while (i <= m) {
		while (i <= m && a[i].l <= R) i ++;
		
		if (i <= m)
			R = a[i].r, ans ++, i ++;
	}
	
	cout << ans;
	return 0;
}
/*
4 0
2 1 0 3
*/
