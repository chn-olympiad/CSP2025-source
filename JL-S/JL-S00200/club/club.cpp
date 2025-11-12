#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> PII;
const int N = 100010;

int T, n, g;
int a[N][4], s[N][4];
PII t[4];

inline void solve()
{
	int res = 0;
	priority_queue<PII, vector<PII>, greater<PII>> h[4];
	scanf("%d", &n), g = n / 2;
	for (int i = 1; i <= n; i ++ )
	{
		for (int j = 1; j <= 3; j ++ )
			scanf("%d", &a[i][j]), t[j] = {a[i][j], j};
		sort(t + 1, t + 4);
		s[i][1] = t[3].second;
		s[i][2] = t[2].second;
		s[i][3] = t[1].second; 
	}
	for (int i = 1; i <= n; i ++ )
	{
		// for (int j = 1; j <= 3; j ++ )
		// 	cout << s[i][j] << ' ';
		// cout << endl;
		int fi = s[i][1], se = s[i][2], nw = a[i][fi] - a[i][se];
		if (h[fi].size() < g) h[fi].push({nw, i}), res += a[i][fi];
		else
		{
			int w = h[fi].top().first, x = h[fi].top().second;
			if (nw <= w) h[se].push({nw, i}), res += a[i][se];
			else
			{
				h[s[x][1]].pop(), res -= a[x][s[x][1]];
				h[s[x][2]].push({w, x}), res += a[x][s[x][2]];
				h[fi].push({nw, i}), res += a[i][fi];
				// cout << res << '@' << endl;
			}
		}
	}
	printf("%d\n", res);
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T -- ) solve();
	return 0;
}