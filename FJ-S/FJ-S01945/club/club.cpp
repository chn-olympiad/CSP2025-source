#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
using namespace std;
const int N = 1e5 + 5;
using pii = pair<int, int>;
int T, n; struct node { int a, b, c; } p[N]; map<int, int> mp;
bool cmpa(node n1, node n2) { return n1.a > n2.a; }
bool cmpb(node n1, node n2) { return n1.b > n2.b; }
bool cmpc(node n1, node n2) { return n1.c > n2.c; }
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		mp.clear();
		for (int i = 1; i <= n; i++)
			scanf("%d%d%d", &p[i].a, &p[i].b, &p[i].c);
		sort(p + 1, p + n + 1, cmpa);
		sort(p + 1, p + n + 1, cmpb);
		sort(p + 1, p + n + 1, cmpc);
		pii las_ma = mk(0, 0), las_mb = mk(0, 0);
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			vector<pii> vec;
			vec.pb(mk(p[i].a, 0));
			vec.pb(mk(p[i].b, 1));
			vec.pb(mk(p[i].c, 2));
			sort(vec.begin(), vec.end());
			reverse(vec.begin(), vec.end());
			if (mp[vec[0].second] + 1 <= (n >> 1))
			{
				mp[vec[0].second]++;
				ans += vec[0].first;
				las_ma = vec[0];
				las_mb = vec[1];
			}
			else
			{
				if (vec[1].first == 0 && ans - las_ma.first + las_mb.first + vec[0].first > ans)
				{
					ans -= las_ma.first;
					ans += las_mb.first;
					ans += vec[0].first;
					mp[las_ma.second]--;
					mp[las_mb.second]++;
					mp[vec[0].second]++;
					las_ma = vec[0];
					las_mb = vec[1];
				}
				else
				{
					ans += vec[1].first;
					mp[vec[1].second]++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;             
}