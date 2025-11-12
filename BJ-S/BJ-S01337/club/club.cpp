#include <bits/stdc++.h>
using namespace std;

int maxi[100005], cnt[5], x[100005];

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		int ans = 0;
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; i++)
		{
			pair<int, int> a[5];
			scanf("%d %d %d", &a[1].first, &a[2].first, &a[3].first);
			a[1].second = 1, a[2].second = 2, a[3].second = 3;
			sort(a + 1, a + 4);
			ans += a[3].first;
			maxi[i] = a[3].second;
			cnt[a[3].second]++;
			x[i] = a[3].first - a[2].first;
		}
		vector<int> v;
		int flag = 1, id;
		for (int i = 1; i <= n; i++)
		{
			if (cnt[maxi[i]] > n / 2) flag = 0, id = maxi[i], v.push_back(x[i]);
		}
		if (flag)
		{
			printf("%d\n", ans);
			continue;
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < cnt[id] - n / 2; i++) ans -= v[i];
		printf("%d\n", ans);
	}
	return 0;
}
