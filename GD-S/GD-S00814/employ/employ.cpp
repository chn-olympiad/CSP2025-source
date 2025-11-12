#include<iostream>
using namespace std;

bool f[100010];
int a[100010];
int p[100010];
bool flag[100010];
int n, m, ans;
char str[100010];

int dfs(int u)
{
	if(u > n)
	{
		int j = 0;
		for(int i = 1; i <= n; i++)
		{
			if(a[p[i]] <= j || f[i] == 0) j++;
		}
		if(n - j >= m) ans = (ans + 1) % 998244353;
	}
	for(int i = 1; i <= n; i++)
	{
		if(!flag[i])
		{
			flag[i] = true;
			p[u] = i;
			dfs(u + 1);
			flag[i] = false;
		}
	}
}

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	scanf("%s", str + 1);
	for(int i = 1; i <= n; i++)
	{
		f[i] = str[i] - '0';
		scanf("%d", &a[i]);
	}
	dfs(1);
	printf("%d\n", ans);
	return 0;
}
//no mind to think
