#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4+5;
int n,k,a[maxn],sum[maxn][maxn],cnt,f[maxn][maxn];
pair<int,int> pos[maxn];

bool cmp(pair<int,int> x, pair<int,int> y)
{
	return x.first < y.first;
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
		{
			sum[i][j] = (sum[i][j-1] xor a[j]);
			if (sum[i][j] == k)
			{
				pos[++cnt].first = i;
				pos[cnt].second = j;
			}
		}
	sort(pos+1,pos+cnt+1,cmp);
	for (int i = 1; i <= cnt; i++)
	{
		for (int j = 1; j <= n; j++)
			f[i][j] = f[i-1][j];
		for (int j = pos[i].second; j <= n; j++)
		{
			f[i][j] = max(f[i-1][j],f[i-1][pos[i].first-1]+1);
		}
	}
	cout << f[cnt][n] << endl;
	return 0;
}
