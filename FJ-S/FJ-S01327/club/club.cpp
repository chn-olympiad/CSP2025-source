#include <bits/stdc++.h>
using namespace std;

pair<int, int> calc(array<int, 3> a)
{
	pair<int, int> b[3];
	for(int i = 0; i < 3; i++)
		b[i].first = a[i], b[i].second = i;
	sort(b, b + 3, greater<pair<int, int>>());
	return {b[0].second, b[1].second};
}

const int N = 2e5 + 8;
array<int, 3> a[N];
int c[N], dt[N];

void solve()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
	int cnt[3] {};
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		auto pr = calc(a[i]);
		int mi = pr.first, ci = pr.second;
		cnt[c[i] = mi]++;
		dt[i] = -a[i][mi] + a[i][ci];
		ans += a[i][mi];
	}
	for(int t = 0; t < 3; t++)
	{
		if(cnt[t] <= n / 2)
			continue;
		vector<int> v;
		for(int i = 1; i <= n; i++)
		{
			if(c[i] == t)
				v.push_back(dt[i]);
		}
		sort(v.begin(), v.end(), greater<int>());
		for(int i = 0; i < (cnt[t] - n / 2); i++)
			ans += v[i];
	}
	printf("%d\n", ans);
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--)
		solve();
	return 0;
}