#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e6 + 1, inf = 1e9 + 7;
struct node
{
	int x, y, z;
}a[N];
bool cmp(node x, node y)
{
	return x.z < y.z;
}
int n, m, k, ans = 0, minn, f[N], F[N], c[11][N];
int find(int x)
{
	if(x == f[x])
	{
		return x;
	}
	return f[x] = find(f[x]);
}
void merge(int xx, int yy)
{
	int x = find(xx), y = find(yy);
	f[x] = f[y];
}
signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		a[i].x = x, a[i].y = y, a[i].z = w;
	}
/*	for(int i = 1; i <= k; i++)
	{
		cin >> c[i][0];
		//cout << c[i][0] << "\n";
		for(int j = 1; j <= n - k; j++)
		{
			cin >> c[i][j];
			a[++m].x = j, a[m].y = n - k + i, a[m].z = c[i][j];
		}
	}*/
	sort(a + 1, a + 1 + m, cmp);
	int cnt = 0;
	for(int i = 1; i <= m; i++)
	{
		if(F[a[i].x] && F[a[i].y])
		{
			continue;
		}
		cnt++;
		F[a[i].x] = 1;
		ans += a[i].z;
		if(cnt == n - 1)
		{
			break;
		}
	}
	cout << ans;
}
