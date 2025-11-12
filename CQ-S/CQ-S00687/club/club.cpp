#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

struct node {
	int t[3];
	int mav, miv, mid;
} a[N];

int T;
int n;
int f;

bool cmp(node x, node y) {
	if(x.mav == y.mav && x.mav == f) {
		return x.t[x.mav] - x.t[x.mid] > y.t[y.mav] - y.t[y.mid];
	}
	return x.mav == f;
}

void solve() {
	scanf("%d", &n);
	
	int p[3] = {0, 0, 0};
	for(int i = 1; i <= n; i++) {
		scanf("%d%d%d", &a[i].t[0], &a[i].t[1], &a[i].t[2]);
		int ma = max(a[i].t[0], max(a[i].t[1], a[i].t[2]));
		if(ma == a[i].t[0]) a[i].mav = 0;
		if(ma == a[i].t[1]) a[i].mav = 1;
		if(ma == a[i].t[2]) a[i].mav = 2;
		int mi = min(a[i].t[0], min(a[i].t[1], a[i].t[2]));
		if(mi == a[i].t[0]) a[i].miv = 0;
		if(mi == a[i].t[1]) a[i].miv = 1;
		if(mi == a[i].t[2]) a[i].miv = 2;
		a[i].mid = 3 - a[i].mav - a[i].miv;
		p[a[i].mav]++;
	}
	
	f = -1;
	if(p[0] > n / 2) f = 0;
	if(p[1] > n / 2) f = 1;
	if(p[2] > n / 2) f = 2;
	
	if(f == -1) {
		int res = 0;
		for(int i = 1; i <= n; i++) {
			res += a[i].t[a[i].mav];
		}
		printf("%d\n", res);
		return;
	}
	
	sort(a + 1, a + 1 + n, cmp);
	
	int res = 0;
	p[0] = p[1] = p[2] = 0;
	for(int i = 1; i <= n; i++) {
		if(p[a[i].mav] == n / 2) {
			res += a[i].t[a[i].mid];
			p[a[i].mid]++;
		} else {
			res += a[i].t[a[i].mav];
			p[a[i].mav]++;
		}
	}
	printf("%d\n", res);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	scanf("%d", &T);
	while(T--) {
		solve();
	}
	
	return 0;
}
