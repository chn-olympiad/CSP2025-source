#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; i ++)
#define per(i, r, l) for (int i = r; i >= l; i --)
#define int long long
/*
既然大伙都不知道，那我就整个活吧！
郑蕴怡小姐，我曾经喜欢你！ 
*/ 
using namespace std;

const int maxn = 4e5 + 5;
int T;
int n;
int a[maxn][3], cnt[3];
priority_queue <pair<int, int> > q[3];

signed main() {
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	/**/
	cin >> T;
	while (T --) {
		scanf("%lld", &n);
		int ans = 0, li = (n / 2);
		rep(i, 0, 2) {
			cnt[i] = 0;
			while (!q[i].empty()) q[i].pop();
		}
		rep(i, 1, n) {
			rep(j, 0, 2) 
				scanf("%lld", &a[i][j]);
			int fi = 0, se = 1;
			rep(j, 1, 2) {
				if (a[i][j] > a[i][fi] || (a[i][j] == a[i][fi] && cnt[j] <= cnt[fi])) 
					se = fi, fi = j;
				else if (a[i][j] > a[i][se] || (a[i][j] == a[i][se] && cnt[j] <= cnt[se])) 
					se = j;	
			}
			if (cnt[fi] >= li) {
				auto [v, id] = q[fi].top();
				if (v + a[i][fi] > a[i][se]) {
					q[fi].pop(), q[fi].push({a[i][se] - a[i][fi], se});
					ans += v + a[i][fi];
				} else ans += a[i][se], cnt[se] ++;
			} else ans += a[i][fi], q[fi].push({a[i][se] - a[i][fi], se}), cnt[fi] ++;
		}
		cout << "ans : " << ans << '\n';
	}
} 

