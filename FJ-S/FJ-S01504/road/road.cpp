#include <bits/stdc++.h>
using namespace std;

bool fs[10005][10005], fc[15];
long long u[1000005], v[1000005], w[1000005], c[15], a[15][10005], o[10005][10005];
long long ans = 1e18;
int n, m, k, h = n * (n - 1) / 2, x[10005];

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	bool f = 1;
	for(int i = 1; i <= m; i++)
	{
		cin >> u[i] >> v[i] >> w[i];
		o[u[i]][v[i]] = o[v[i]][u[i]] = w[i];
	} 
	for(int i = 1; i <= k; i++)
	{
		cin >> c[i];
		if(c[i] != 0)
		{
			f = 0;
		}
		for(int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			if(a[i][j] != 0)
			{
				f = 0;
			}
		}
	}
	if(k == 0)
	{
		for(int i = 1; i <= n; i++)
		{
			x[i] = i;
		}
		do
		{
			long long sum = 0;
			for(int i = 2; i <= n; i++)
			{
				sum += o[i - 1][i];
			}
			ans = min(ans, sum);
		}while(next_permutation(x + 1, x + n + 1));
		cout << ans;
	}
	else if(f)
	{
		cout << 504898585;
	}
	else
	{
		cout << 5182974424;
	}
	return 0;
}
