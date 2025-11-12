#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int t, n, Max;
struct node {
	int a1, a2, a3, more;
}a[N], first[N], second[N], third[N];
vector<node> v;

bool cmp1 (node x, node y) {
	if (x.a1 >= y.a1)
		return true;
	return false;
}

bool cmp2 (node x, node y) {
	if (x.a2 >= y.a2)
		return true;
	return false;
}

int main () {
	freopen ("club.in", "r", stdin);
	freopen ("club.out","w",stdout);
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf ("%d%d%d", &a[i].a1, &a[i].a2, &a[i].a3);
			if (a[i].a1 > a[i].a2 && a[i].a1 > a[i].a3)
				a[i].more = 1;
			else if (a[i].a2 > a[i].a1 && a[i].a2 > a[i].a3)
				a[i].more = 2;
			else
				a[i].more = 3;
		}
		int One = 0, Two = 0;
		for (int i = 1; i <= n; i++)
			if (a[i].more == 1)
				One++;
			else
				Two++;
		if (One > n / 2) {
			sort (a + 1, a + n + 1, cmp1);
			for (int i = 1; i <= n / 2; i++)
				Max += a[i].a1;
			for (int i = n / 2 + 1; i <= n; i++)
				Max += a[i].a2;
		} else if (Two > n / 2) {
			sort (a + 1, a + n + 1, cmp2);
			for (int i = 1; i <= n / 2; i++)
				Max += a[i].a2;
			for (int i = n / 2 + 1; i <= n; i++)
				Max += a[i].a1;
		}
		//~ for (int i = 1; i <= n; i++)
			//~ printf ("%d %d %d %d\n", a[i].a1, a[i].a2, a[i].a3, a[i].more);
		printf ("%d\n", Max);
	}
	return 0;
}
