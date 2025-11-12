#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
const int N = 1e5 + 10;
int maxn;
int a1[N], b1[N], c1[N];
int n;
int ans[N];

struct people
{
	int num;
	int id;
}a[N], b[N], c[N];

bool cmp(people x, people y)
{
	if(x.num != y.num) return x.num > y.num;
	return x.id < y.id;
}

void dfs(int u, int na, int nb, int nc, int sum)
{
	if(u > n)
	{
		maxn = max(maxn, sum);
		return;
	}
	for(int i = 1;i <= 3;i ++)
	{
		if(na != 0 && a1[u] != 0) dfs(u + 1, na - 1, nb, nc, sum + a1[u]);
		if(nb != 0 && b1[u] != 0) dfs(u + 1, na, nb - 1, nc, sum + b1[u]);
		if(nc != 0 && c1[u] != 0) dfs(u + 1, na, nb, nc - 1, sum + c1[u]);
	}
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//后面只加cin跟cout!!!
	int T;
	cin >> T;
	while(T --)
	{
		cin >> n;
		if(n <= 15)
		{
			for(int i = 1;i <= n;i ++)
			{
				cin >> a1[i] >> b1[i] >> c1[i];
			}
			dfs(1, n / 2, n / 2, n / 2, 0);
			cout << maxn << endl;
			maxn = 0;
		}
		else
		{
			for(int i = 1;i <= n;i ++)
			{
				cin >> a[i].num >> b[i].num >> c[i].num;
				a[i].id = i, b[i].id = i, c[i].id = i;
			}
			sort(a + 1, a + n + 1, cmp);
			sort(b + 1, b + n + 1, cmp);
			sort(c + 1, c + n + 1, cmp);
			for(int i = 1;i <= n / 2;i ++)
			{
				int NUM = a[i].num, ID = a[i].id;
				ans[ID] = max(ans[ID], NUM);
			}
			for(int i = 1;i <= n / 2;i ++)
			{
				int NUM = b[i].num, ID = b[i].id;
				ans[ID] = max(ans[ID], NUM);
			}
			for(int i = 1;i <= n / 2;i ++)
			{
				int NUM = c[i].num, ID = c[i].id;
				ans[ID] = max(ans[ID], NUM);
			}
			ll res = 0;
			for(int i = 1;i <= n;i ++) res += ans[i];
			cout << res << endl;
			memset(ans, 0, sizeof(ans));
		}
	}
	return 0;
}
