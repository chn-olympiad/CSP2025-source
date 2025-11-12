#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5;
struct node {
	ll val[3];
	ll id[3];
	ll d,npos;
	bool operator < (const node& x) const {
		return d > x.d;
	}
};
int T;
int n;
node a[maxn + 5];
bool comp(const ll& x,const ll& y) {
	return x > y;
}
int lim = 0;
ll ans = 0ll;
priority_queue<node> q[3];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while (T --) {
		for (int i = 0;i <= 2;i ++) while (!q[i].empty()) q[i].pop();
		ans = 0ll;
		scanf("%d",&n);
		lim = n / 2;
		for (int i = 1;i <= n;i ++) {
			scanf("%lld %lld %lld",&a[i].val[0],&a[i].val[1],&a[i].val[2]);
			if (a[i].val[0] >= a[i].val[1] && a[i].val[0] >= a[i].val[2]) {
				a[i].id[0] = 0;
				if (a[i].val[1] >= a[i].val[2]) a[i].id[1] = 1,a[i].id[2] = 2;
				else a[i].id[1] = 2,a[i].id[2] = 1;
			} else if (a[i].val[1] >= a[i].val[0] && a[i].val[1] >= a[i].val[2]) {
				a[i].id[0] = 1;
				if (a[i].val[0] >= a[i].val[2]) a[i].id[1] = 0,a[i].id[2] = 2;
				else a[i].id[1] = 2,a[i].id[2] = 0;
			} else if (a[i].val[2] >= a[i].val[0] && a[i].val[2] >= a[i].val[1]) {
				a[i].id[0] = 2;
				if (a[i].val[0] >= a[i].val[1]) a[i].id[1] = 0,a[i].id[2] = 1;
				else a[i].id[1] = 1,a[i].id[2] = 0;
			}
			sort(a[i].val,a[i].val + 3,comp);
			node tnode = a[i];
			tnode.d = tnode.val[0] - tnode.val[1];
			tnode.npos = 0;
			q[tnode.id[tnode.npos]].push(tnode);
			ans += tnode.val[0];
		}
		while ((int)q[0].size() > lim || (int)q[1].size() > lim || (int)q[2].size() > lim) {
			if ((int)q[0].size() > lim) {
				node t = q[0].top(); q[0].pop();
				ans -= t.d;
				t.npos ++;
				if (t.npos <= 1) t.d = t.val[t.npos] - t.val[t.npos + 1];
				q[t.id[t.npos]].push(t);
			}
			if ((int)q[1].size() > lim) {
				node t = q[1].top(); q[1].pop();
				ans -= t.d;
				t.npos ++;
				if (t.npos <= 1) t.d = t.val[t.npos] - t.val[t.npos + 1];
				q[t.id[t.npos]].push(t);
			}
			if ((int)q[2].size() > lim) {
				node t = q[2].top(); q[2].pop();
				ans -= t.d;
				t.npos ++;
				if (t.npos <= 1) t.d = t.val[t.npos] - t.val[t.npos + 1];
				q[t.id[t.npos]].push(t);
			}
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}
/*
1
2
10 9 8
4 0 0

*/