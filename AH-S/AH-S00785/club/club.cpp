#include <bits/stdc++.h>
#define rep(i,x,y) for (int i = x; i <= y; i++)
#define per(i,x,y) for (int i = x; i >= y; i--)
using namespace std;
const int N = 1e5 + 10;
struct Temp{
	int a, b;
};
struct node{
	int a, x, b, y;
	int v;
}a[N];
int n, t, cnt[4], ans;
bool cmp(const node &x, const node &y) {
	return x.v > y.v;
}
bool cmp2(const Temp &x, const Temp &y) {
	return x.a < y.a;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	Temp tmp[4];
	while(t--) {
		memset(cnt, 0, sizeof(cnt));
		ans = 0;
		scanf("%d", &n);
		rep(i, 1, n) {
			scanf("%d%d%d", &tmp[1].a, &tmp[2].a, &tmp[3].a);
			tmp[1].b = 1; tmp[2].b = 2; tmp[3].b = 3;
			sort(tmp+1, tmp+1+3, cmp2);
			a[i].a = tmp[3].a; a[i].x = tmp[3].b; a[i].b = tmp[2].a; a[i].y = tmp[2].b;
			a[i].v = tmp[3].a-tmp[2].a;
		}
		sort(a+1, a+1+n, cmp);
		rep(i,1,n) {
			if (cnt[a[i].x] >= n/2) {
				cnt[a[i].y]++;
				ans += a[i].b;
			}
			else {
				cnt[a[i].x]++;
				ans += a[i].a;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
