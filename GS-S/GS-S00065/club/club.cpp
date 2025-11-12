#include<bits/stdc++.h>
using namespace std;

struct Info {
	int a1, a2, a3;
	int ma, mx, d1, d2;
}a[100001];
int t, n, top1, top2, top3, k;
long long ans = 0;

bool cmp1(Info x, Info y) {
	return x.ma > y.ma;
}

void solve() {
	scanf("%d", &n);
	k = n / 2;
	top1 = top2 = top3 = 0;
	ans = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &a[i].a1, &a[i].a2, &a[i].a3);
		if (a[i].a1 >= a[i].a2) {
			if (a[i].a3 > a[i].a1) {
				a[i].ma = a[i].a3, a[i].d1 = 3;
				a[i].mx = a[i].a1, a[i].d2 = 1;
			}else if (a[i].a3 <= a[i].a1 && a[i].a3 > a[i].a2) {
				a[i].ma = a[i].a1, a[i].d1 = 1;
				a[i].mx = a[i].a3, a[i].d2 = 3;
			}else {
				a[i].ma = a[i].a1, a[i].d1 = 1;
				a[i].mx = a[i].a2, a[i].d2 = 2;		
			}
		}else {
			if (a[i].a3 > a[i].a2) {
				a[i].ma = a[i].a3, a[i].d1 = 3;
				a[i].mx = a[i].a2, a[i].d2 = 2;
			}else if (a[i].a3 > a[i].a1 && a[i].a3 <= a[i].a2) {
				a[i].ma = a[i].a2, a[i].d1 = 2;
				a[i].mx = a[i].a3, a[i].d2 = 3;
			}else {
				a[i].ma = a[i].a2, a[i].d1 = 2;
				a[i].mx = a[i].a1, a[i].d2 = 1;	
			}			
		}
	}
	sort(a + 1, a + n + 1, cmp1);
	for (int i = 1; i <= n; i++) {
		if ((a[i].d1 == 1 && top1 == k) || (a[i].d1 == 2 && top2 == k) || (a[i].d1 == 3 && top3 == k)) {
			ans += a[i].mx * 1ll;
			if (a[i].d2 == 1)
				top1++;
			else if (a[i].d2 == 2)
				top2++;
			else
				top3++;
		}else {
			ans += a[i].ma * 1ll;
			if (a[i].d1 == 1)
				top1++;
			else if (a[i].d1 == 2)
				top2++;
			else
				top3++;			
		}
	}
	printf("%lld\n", ans);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}
