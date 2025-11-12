#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
const int N = 1e5 + 5;
struct node {
	int a, b, c;
	int mx, md, mn, ch, id;
	void input() {
		scanf("%lld%lld%lld", &a, &b, &c);
		mx = max(max(a, b), c);
		mn = min(min(a, b), c);
		md = a + b + c - mx- mn;
		ch = mx - md;
		if(mx == a) id = 1;
		if(mx == b) id = 2;
		if(mx == c) id = 3;
	}
	void add(int u, int v) {
		if(u == 1) a += v;
		if(u == 2) b += v;
		if(u == 3) c += v;
	}
} stu[N],stu2[N];
bool cmp(node a, node b) {
	return a.ch > b.ch;
}
void Solve() {
	node cnt;
	cnt.a = cnt.b = cnt.c = 0;
	int n, flag = 0;
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++) {
		stu[i].input();
		cnt.add(stu[i].id, 1);
		if((cnt.a > n / 2 || cnt.b > n / 2 || cnt.c > n / 2) && !flag) flag = stu[i].id;
	}
	if(!flag) {
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			ans += stu[i].mx;
		}
		printf("%lld\n", ans);
	} else {
		int cur = 0, ans = 0;
		for(int i = 1; i <= n; i++) {
			if(stu[i].id == flag) stu2[++cur] = stu[i];
			else ans += stu[i].mx;
		}
		sort(stu2 + 1, stu2 + cur + 1, cmp);
		for(int i = 1; i <= n / 2; i++) {
			ans += stu2[i].mx;
		}
		for(int i = n / 2 + 1; i <= cur; i++) {
			ans += stu2[i].md;
		}
		printf("%lld\n", ans);
	}
	
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	scanf("%lld", &T);
	while(T--) Solve();
	return 0;
}
