#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
int a[N][3], p[N], b[N];
vector<int> tmp[3];

void solve()
{
	int n, i, j, x;
	ll sum = 0;
	scanf("%d", &n);
	tmp[0] = tmp[1] = tmp[2] = {};
	for(i = 1; i <= n; i++)
	{
		scanf("%d%d%d", a[i], a[i] + 1, a[i] + 2);
		p[i] = 0;
		for(j = 1; j < 3; j++)
			if(a[i][j] > a[i][p[i]])
				p[i] = j;
		sum += a[i][p[i]];
		b[i] = 0;
		for(j = 0; j < 3; j++)
			if(j != p[i])
				b[i] = max(b[i], a[i][j]);
		b[i] = a[i][p[i]] - b[i];
		tmp[p[i]].emplace_back(b[i]);
	}
	x = -1;
	for(j = 0; j < 3; j++)
		if(tmp[j].size() > n / 2)
			x = j;
	if(x == -1)
	{
		printf("%lld\n", sum);
		return ;
	}
	nth_element(tmp[x].begin(), tmp[x].begin() + (tmp[x].size() - n / 2), tmp[x].end());
	for(i = 0; i < tmp[x].size() - n / 2; i++)
		sum -= tmp[x][i];
	printf("%lld\n", sum);
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--)
		solve();
	return 0;
}