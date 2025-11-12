#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 110;

int a[N], id[N];
PII res[N];

bool cmp(int p, int q) {return a[p] > a[q];}

void solve()
{
	int n, m; scanf("%d%d", &n, &m);
	int sum = n * m;
	for (int i = 1; i <= sum; i ++ ) {scanf("%d", &a[i]); id[i] = i;}
	sort(id + 1, id + 1 + sum, cmp);
	int x = 1, y = 1, op = 1;
	for (int i = 1; i <= sum; i ++ )
	{
		res[id[i]] = {x, y};
		y += op;
		if (y < 1 || y > n) x ++ , y -= op, op = -op;
	}
	printf("%d %d\n", res[1].first, res[1].second);
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int T = 1;
	while (T -- ) solve();
	return 0;
}
