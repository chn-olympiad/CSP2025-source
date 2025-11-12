#include <iostream>
using namespace std;
#define int long long

const int N = 5e2 + 10,mod = 998244353;
int n,m,a[N],c[N],p[N],ans;
bool vis[N];	

inline int check()
{
	int cnt = 0,cp = 0;
	for(int i = 1;i <= n;i ++)
	{
		int x = p[i];
		if (cnt >= c[x] || !a[i])
		{
			cnt ++;
			continue;
		}
		else cp ++;
	}
	return (cp >= m);
}

inline void dfs(int step)
{
	if (step > n)
	{
		ans += check();
		return ;
	}
	for(int i = 1;i <= n;i ++)
	{
		if (vis[i]) continue;
		vis[i] = 1;
		p[step] = i;
		dfs(step + 1);
		vis[i] = 0;
	}
}

signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)
	{
		char ch;
		cin >> ch;
		a[i] = (ch - '0');
	}
	for(int i = 1;i <= n;i ++) cin >> c[i];
	dfs(1);
	cout << ans << endl;
	return 0;
}

/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
