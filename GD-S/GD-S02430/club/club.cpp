#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
//1  club
struct node{
	int a1, a2, a3;
}a[100010];
int t, n, f1[20010], b1, b2, b3;
int n2 () {
	int q1 = a[1].a1 + a[2].a2;
	int q2 = a[1].a1 + a[2].a3;
	int q3 = a[1].a2 + a[2].a1;
	int q4 = a[1].a2 + a[2].a3;
	int q5 = a[1].a3 + a[2].a1;
	int q6 = a[1].a3 + a[2].a2;
	int max1 = max(q1, q2);
	int max2 = max(q3, q4);
	int max3 = max(q5, q6);
	int maxn = max(max1, max(max2, max3));
	return maxn;
}
bool cmp (node x, node y) {
	return x.a1 > y.a1;
}
int main () {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		memset(f1, 0, sizeof f1);
		int flag1 = 1, cccnt = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
			cccnt += a[i].a1 + a[i].a2 + a[i].a3;
			if (!(a[i].a2 == a[i].a3 && a[i].a2 == 0)) {
				flag1 = 0;
			}
		}
		int mid = n / 2, maxx = -1e18;
		sort(a + 1, a + n + 1, cmp);
		//
		if (flag1 == 1) {
			int ccnt = 0;
			for (int i = 1; i <= mid; i++) ccnt += a[i].a1;
			printf("%d", ccnt);
			continue;
		}
		if (cccnt == 0) {
			printf("0");
			continue;
		}
		if (n == 2) {
			printf("%d\n", n2());
			continue;
		}
		//
		int sss = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (f1[j] >= a[i].a1 + sss) {
					if (b1 < mid) {
						++b1;
						sss = a[i].a1 + sss;
						f1[j] = sss;
					}
				}else if (f1[j] >= a[i].a2 + sss) {
					if (b2 < mid) {
						++b2;
						sss = a[i].a2 + sss;
						f1[j] = sss;
					}
				}else if (f1[j] >= a[i].a3 + sss) {
					if (b3 < mid) {
						++b3;
						sss = a[i].a3 + sss;
						f1[j] = sss;
					}
				}
			}
			
		}
		int maxn1 = -1e18;
		for (int i = 1; i <= n; i++) {
			maxn1 = max(maxn1, f1[i]);
		}
		printf("%d\n", maxn1);
	}
	return 0;
}
