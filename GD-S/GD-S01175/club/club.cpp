#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 1e5 + 6;
int cnt[4], a[N][4];
int choices[N];
priority_queue<int, vector<int>, greater<int>> q;

void test() {
	while (!q.empty()) q.pop();
	memset(cnt, 0, sizeof(cnt));
	memset(a, 0, sizeof(a));
	memset(choices, 0, sizeof(choices));

	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		int pos = -1, mx = -1;
		for (int j = 1; j <= 3; j++) {
			if (mx < a[i][j]) {
				pos = j, mx = a[i][j];
			}
		}
		ans += mx;
		cnt[pos]++;
		choices[i] = pos;
	}

	int overGroup = -1;
	for (int i = 1; i <= 3; i++) {
		if (cnt[i] > (n >> 1)) overGroup = i;
	}

	if (overGroup == -1) {
		printf("%d\n", ans);
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (choices[i] == overGroup) {
			int mx = -1;
			for (int j = 1; j <= 3; j++) {
				if (j != overGroup) {
					mx = max(mx, a[i][j]);
				}
			}
			int val = a[i][overGroup] - mx;
			q.push(val);
			// printf("pushed = %d\n", val);
		}
	}

	int qn = q.size();
	for (int i = (n >> 1) + 1; i <= qn; i++) {
		ans -= q.top();
		q.pop();
	}
	printf("%d\n", ans);
	return;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--) test();
	return 0;
}

/*
15:13
若无 > n/2，皆大欢喜。
最多只有一个部门会 > n/2，考虑让他跳槽。
否则，设立优先队列，
找到变化量（前 - 后）最小的(且未满, never exists)的那个部门跳槽。
做一次即可，因为不会再出现 > n/2 的情况了。
15:34 end!!!!!
*/