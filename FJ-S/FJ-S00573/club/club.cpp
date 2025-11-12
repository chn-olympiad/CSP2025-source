#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
int t;
int n;
int ton[N];
struct node {
	int val, id;
} a[N][4], c[N];
int vis[N];
bool cmp(node x, node y) {
	return x.val > y.val;
}
vector<pair<int, int > > v;
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		memset(ton, 0, sizeof ton);
		for (int i=1; i<=n; i++) {
			cin >> a[i][1].val >> a[i][2].val >> a[i][3].val;
			a[i][1].id = 1;
			a[i][2].id = 2;
			a[i][3].id = 3;
			sort(a[i] + 1, a[i] + 4, cmp);
			ton[a[i][1].id]++;
			v.push_back(make_pair(a[i][1].id, i));
		}
		int idx = 0;
		for (int i=1; i<=3; i++) {
			if (ton[i] > n / 2) {
				idx = i;
			}
		}
		if (idx != 0) {
			int sum = 0;
			int tot = 0;
			for (int i=0; i<v.size(); i++) {
				int idd = v[i].first;// 进入哪个部门
				int bh = v[i].second;// 编号
				if (idd == idx) {
					c[++tot].val = a[bh][1].val;
					c[tot].id = bh;
//					printf("a[bh][idd].val:%d bh:%d idd:%d\n", a[bh][1].val, bh, v[i].first);
//					printf("a[bh][1].val:%d a[bh][2].val:%d a[bh][3].val:%d\n", a[bh][1].val, a[bh][2].val, a[bh][3].val);
				}
			}
			sort(c + 1, c + tot + 1, cmp);
			for (int i=1; i<=n / 2; i++) {
				sum += c[i].val;
				vis[c[i].id]++;// 标记已经加入某一部门
			}
			for (int i=1; i<=n; i++) a[i][1].val = 0;
			memset(ton, 0, sizeof ton);
			for (int i=1; i<=n; i++) {
				sort(a[i] + 1, a[i] + 4, cmp);
				ton[a[i][1].id]++;
			}
			int maxn = -1e9, cid = 0;
			for (int i=1; i<=3; i++) {
				if (i != idx) {
					if (maxn < ton[i]) {
						maxn = ton[i];
						cid = i;
					}
				}
			}
			for (int i=0; i<v.size(); i++) {
				if (v[i].first == idx) continue;
				else sum += a[v[i].second][1].val;
				int bh = v[i].second;
//				printf("a[bh][idd].val:%d bh:%d idd:%d\n", a[bh][1].val, bh, v[i].first);
//				printf("a[bh][1].val:%d a[bh][2].val:%d a[bh][3].val:%d\n", a[bh][1].val, a[bh][2].val);
			}
			cout << sum << '\n';
		} else {
			int sum = 0;
			for (int i=0; i<v.size(); i++) {
				int bh = v[i].second;// 编号
				sum += a[bh][1].val;
//				printf("a[bh][2].val:%d a[bh][3].val:%d\n", a[bh][2].val, a[bh][3].val);
//				printf("bh:%d idd:%d\n", bh, idd);
			}
			cout << sum << '\n';
		}
	}
	return 0;
}
/*


*/
