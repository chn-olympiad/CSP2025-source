#include <bits/stdc++.h>
#define filein(x) freopen(x".in", "r", stdin)
#define file(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout);
#define files(x) freopen(x".in", "r", stdin), freopen(x".ans", "w", stdout);
template <typename T>
inline T& chkmax(T& a, const T& b){if (a < b) a = b; return a;}
template <typename T>
inline T& chkmin(T& a, const T& b){if (a > b) a = b; return a;}
using namespace std; // my guiding star.
using ll = long long;
using pii = pair<int, int>;
const int N = 1e5 + 5;
int n, a[N][4], id[N][4], candi[N];
int main()
{
	file("club");
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i=1; i<=n; i++)
		{
			scanf("%d%d%d", a[i] + 1, a[i] + 2, a[i] + 3); id[i][1] = 1; id[i][2] = 2; id[i][3] = 3;
			stable_sort(id[i] + 1, id[i] + 1 + 3, [&](int x, int y){return a[i][x] > a[i][y];});
		}
		int cnt[4] = {};
		for (int i=1; i<=n; i++) ++cnt[candi[i] = id[i][1]];
		int p = 1;
		if (cnt[2] > cnt[p]) p = 2;
		if (cnt[3] > cnt[p]) p = 3;
		if (cnt[p] > n / 2)
		{
			vector<pii> v;
			for (int i=1; i<=n; i++)
				if (candi[i] == p) v.emplace_back(a[i][id[i][1]] - a[i][id[i][2]], i);
			stable_sort(v.begin(), v.end());
			int o = cnt[p] - n / 2;
			for (int i=0; i<o; i++) candi[v[i].second] = id[v[i].second][2];
		}
		int ans = 0;
		for (int i=1; i<=n; i++) ans += a[i][candi[i]];
		printf("%d\n", ans);
	}
	return 0;
}
