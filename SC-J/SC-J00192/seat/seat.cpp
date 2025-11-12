#include <bits/stdc++.h>
using namespace std;
const int maxn = 10;
struct node {
	int pos;
	int val;
};
int n,m;
node a[maxn * maxn + 5];
bool comp(const node& x,const node& y) {
	return x.val > y.val;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d",&n,&m);
	for (int i = 1;i <= n * m;i ++) {
		scanf("%d",&a[i].val);
		a[i].pos = i;
	}
	sort(a + 1,a + n * m + 1,comp);
	int t = 0;
	for (int i = 1;i <= n * m;i ++) {
		if (a[i].pos == 1) {
			t = i;
			break;
		}
	}
	int tx = t / n,ty = 0;
	int rest = t - (tx * n);
	if (t % n != 0) {
		tx ++;
		if (tx % 2 == 1) {
			ty = rest;
		} else {
			ty = n - rest + 1;
		}
	} else {
		if (tx % 2 == 1) {
			ty = n;
		} else {
			ty = 1;
		}
	}
	
	printf("%d %d",tx,ty);
	return 0;
}
/*
2 2
99 100 97 98
2 2
98 99 100 97
3 3
94 95 96 97 98 99 100 93 92
*/