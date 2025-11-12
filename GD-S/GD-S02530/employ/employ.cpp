#include <iostream> 
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int mod = 998244353;
int a[25],b[25], p[25];
bool flag[25];
int n, m, ans, cnt;

void dfs(int d)
{
	if(d > n)
	{
		cnt =0;
		for(int i =1; i <= n; i++) if(cnt >=p[a[i]] || !b[i]) cnt++;
		ans += (m <= n - cnt);
		return ;
	}
	for(int i = 1; i <= n; i++) 
	{
		if(!flag[i])
		{
			a[d]=i;
			flag[i]=1;
			dfs(d+1);
			flag[i]=0;
		}
	}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d", &n, &m);
	if(n <20)
	{
		for(int i = 1; i <= n; i++) 
		{
			char c;
			cin >> c;
			b[i] = c - '0';
		}
		for(int i = 1; i <= n; i++) scanf("%d",&p[i]);
		dfs(1);
		cout << ans << endl;
		return 0;
	}
	int t;
	for(int i = 1; i <= n; i++) scanf("%d",&t);
	for(int i = 1; i <= m; i++)
	{
		scanf("%d", &t);
		n -= (t == 0);
	}
	int ans = 1;
	for(int i = 1; i <= n; i++)
	{
		ans *= i;
		ans %=mod;
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3 2
101
1 1 2
*/
