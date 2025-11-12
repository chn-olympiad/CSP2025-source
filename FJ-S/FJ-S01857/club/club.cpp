#include <bits/stdc++.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

#define MAX_N ((int) 1e5)

int n, a[MAX_N + 1][3];

int cnt[3], hope[MAX_N + 1];

std::priority_queue<int> q;

main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	int t; scanf("%d", &t);

	while (t --> 0) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
		
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int best = max(a[i][0], max(a[i][1], a[i][2])); ans += best;
			if (best == a[i][0]) cnt[hope[i] = 0]++;
			else if (best == a[i][1]) cnt[hope[i] = 1]++;
			else cnt[hope[i] = 2]++;
		}
		
		int tar = -1;
		if (cnt[0] > n / 2) tar = 0;
		if (cnt[1] > n / 2) tar = 1;
		if (cnt[2] > n / 2) tar = 2;
		
		if (tar == -1) {
			printf("%d\n", ans);
			cnt[0] = cnt[1] = cnt[2] = 0;
			continue;
		}
		
		for (int i = 1; i <= n; i++)
			if (hope[i] == tar) {
				int best = a[i][tar]; a[i][tar] = 0;
				q.push(max(a[i][0], max(a[i][1], a[i][2])) - best);
			}
		
		int k = cnt[tar] - n / 2;
		while (k --> 0) ans += q.top(), q.pop();
		
		printf("%d\n", ans);
		
		while (q.size()) q.pop();
		cnt[0] = cnt[1] = cnt[2] = 0;
	}
	
	return 0;
}
