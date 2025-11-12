#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 1e5 + 5;

int t, n, half, ans;
int cnt[4];

struct node {
	int num[4];
} a[MAXN];

int tag[MAXN];

struct Small {
	int x;
	
	Small(int _x = 0) : x(_x) {}
	
	bool operator < (const Small &s) const {
		return x > s.x;
	}
};

priority_queue<Small> q;
int g[4];

int main(void) {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		cnt[1] = cnt[2] = cnt[3] = 0;
		ans = 0;
		while (q.size())
			q.pop();
		scanf("%d", &n);
		half = n / 2;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= 3; ++j)
				scanf("%d", &a[i].num[j]);
			int id = 1;
			for (int j = 2; j <= 3; ++j)
				if (a[i].num[j] > a[i].num[id])
					id = j;
			cnt[id]++;
			ans += a[i].num[id];
			tag[i] = id;
		}
		int eid = 0;
		if (cnt[1] > half)
			eid = 1;
		else if (cnt[2] > half)
			eid = 2;
		else if (cnt[3] > half)
			eid = 3;
		if (!eid) {
			printf("%d\n", ans);
			continue;
		}
		for (int i = 1; i <= n; ++i)
			if (tag[i] == eid) {
				g[1] = a[i].num[1];
				g[2] = a[i].num[2];
				g[3] = a[i].num[3];
				sort(g + 1, g + 4);
				q.push(g[3] - g[2]);
			}
		while (cnt[eid] > half) {
			int d = q.top().x;
			q.pop();
			ans -= d;
			--cnt[eid];
		}
		printf("%d\n", ans);
	}
	return 0;
}
