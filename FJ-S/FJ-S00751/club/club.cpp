#include <bits/stdc++.h>
using namespace std;

// record max - second
int wtoa[100005], wtob[100005], wtoc[100005];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(wtoa, 0, sizeof wtoa);
		memset(wtob, 0, sizeof wtob);
		memset(wtoc, 0, sizeof wtoc);
		int n, to1=0, to2=0, to3=0, sum=0;
		scanf("%d", &n);
		for (int i=1; i<=n; i++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			if (a >= b && a >= c) {
				to1++;
				sum += a;
				wtoa[to1] = a - max(b, c);
			}
			else if (b >= a && b >= c) {
				to2++;
				sum += b;
				wtob[to2] = b - max(a, c);
			}
			else {
				to3++;
				sum += c;
				wtoc[to3] = c - max(a, b);
			}
		}
		int half = n / 2;
		if (to1 > half) {
			sort(wtoa + 1, wtoa + 1 + to1);
			int times = to1 - half;
			for (int i=1; i<=times; i++) {
				sum -= wtoa[i];
			}
		}
		else if (to2 > half) {
			sort(wtob + 1, wtob + 1 + to2);
			int times = to2 - half;
			for (int i=1; i<=times; i++) {
				sum -= wtob[i];
			}
		}
		else if (to3 > half) {
			sort(wtoc + 1, wtoc + 1 + to3);
			int times = to3 - half;
			for (int i=1; i<=times; i++) {
				sum -= wtoc[i];
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
