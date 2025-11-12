#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 20;

int T, n;
struct stu {
	int d[5], id1, id2;
	bool operator < (stu x) const {
		return d[id2] < x.d[x.id2];
	}
} a[N];
//struct stud {
//	int d[5], id1, id2;
//	bool operator < (stu x) const {
//		return d[id2] < x.d[x.id2];
//	}
//};
int cnt[5];
bool cmp1 (pair <int, int> x, pair <int, int> y) {
	return x.first > y.first;
}
bool cmp2 (stu x, stu y) {
	return x.d[x.id1] > y.d[y.id1];
}
int qaq;
void dfs (int x, int sum) {
	if (x > n) {
		qaq = max (qaq, sum);
		return ;
	}
//	cout << x;
	for (int i = 1; i <= 3; i ++)
		if (cnt[i] < n / 2) {
			cnt[i] ++;
			dfs (x + 1, sum + a[x].d[i]);
			cnt[i] --;
		}
}
void solve () {
	cin >> n;
	cnt[1] = cnt[2] = cnt[3] = 0;
	if (n <= 10) {
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= 3; j ++)
				cin >> a[i].d[j];
		qaq = 0;
		dfs (1, 0);
		cout << qaq << '\n';
	} 
	else {
		for (int i = 1; i <= n; i ++) {
			pair <int, int> qwq[5];
			for (int j = 1; j <= 3; j ++) {
				cin >> a[i].d[j];
				qwq[j].first = a[i].d[j];
				qwq[j].second = j;
			}
			sort (qwq + 1, qwq + 3 + 1, cmp1);
			a[i].id1 = qwq[1].second;
			a[i].id2 = qwq[2].second;	
		}
		sort (a + 1, a + n + 1, cmp2);
//		for (int i = 1; i <= n; i ++)
//			cout << a[i].d[a[i].id1] << " ";
//		cout << '\n';
		int ans = 0;
		priority_queue <stu> pri[4];
		for (int i = 1; i <= n; i ++) {
			if (cnt[a[i].id1] < n / 2) {
				cnt[a[i].id1] ++;
				ans += a[i].d[a[i].id1];
				pri[a[i].id1].push (a[i]);
			}
			else {
				if (pri[a[i].id1].size ()) {
					stu f = pri[a[i].id1].top ();
					if (f.d[f.id2] + a[i].d[a[i].id1] > f.d[a[i].id1] + a[i].d[a[i].id2]) {
	//					if (i == 7) cout << f.d[f.id1] << " " << f.d[f.id2] << " TEST\n";
						pri[a[i].id1].pop ();
						pri[a[i].id1].push (a[i]);
						pri[f.id2].push (f);
						ans -= f.d[a[i].id1], ans += f.d[f.id2] + a[i].d[a[i].id1];
						cnt[f.id2] ++;
						continue;
					}
				}
				cnt[a[i].id2] ++;
				ans += a[i].d[a[i].id2];
				pri[a[i].id2].push (a[i]);
			}
			
		}
		cout << ans << '\n';
	}
}
signed main () {
	ios::sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	cin >> T;
	while (T --)
		solve ();
	return 0;
}
/*
1
10
2038 9963 19722
2020 14533 18961
3518 14615 17976
6188 13424 16615
16441 5313 10926
2423 15344 16322
1910 6224 16178
8375 10557 5444
958 3195 9953
8769 509 4394
*/
