#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 500; 
struct node {
	int val, id;
	friend bool operator < (node a, node b) {
		return a.val > b.val;
	}
} num[N][4], snum[N][4];
int bj[N], cnt[4], scnt[4];
int sd[N];
bool cmp(const int a, const int b) {
	return a > b;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
//		cout << "yes" << endl;
		long long ans = 0;
		int maxx = 0, idd = 0;
		cnt[1] = cnt[2] = cnt[3] = 0;
		for (int i = 1; i <= n; i++) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);		
			num[i][1] = (node) {a, 1};
			num[i][2] = (node) {b, 2};
			num[i][3] = (node) {c, 3};
			sort(num[i] + 1, num[i] + 3 + 1);
			ans += num[i][1].val;
			bj[i] = num[i][1].id;
			cnt[num[i][1].id]++;
			if (cnt[num[i][1].id] > maxx) {
				maxx = cnt[num[i][1].id];
				idd = num[i][1].id;
			}
		}
		if (maxx <= n / 2) {
			printf("%lld\n", ans);
			continue;
		} else {
			int cz = maxx - n / 2;
			for (int i = 1; i <= 3; i++) {
				if (i != idd) {
					scnt[i] = n / 2 - cnt[i];
				}
			}
			int tot = 0;
			for (int i = 1; i <= n; i++) {
				if (bj[i] == idd) {
					for (int j = 2; j <= 3; j++) {
						num[i][j].val = num[i][j].val - num[i][1].val;
					}
					if (num[i][2].val < num[i][3].val) {
						swap(num[i][2], num[i][3]);
					}
					sd[++tot] = num[i][2].val;
				}
			}
			sort(sd + 1, sd + tot + 1, cmp);
			for (int i = 1; i <= cz; i++) {
				ans += sd[i];
			}
			cout << ans << endl;
			memset(bj, 0, sizeof(bj));
		}
	}
	return 0;
}
