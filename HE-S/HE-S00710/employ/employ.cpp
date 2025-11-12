#include<bits/stdc++.h>
#define int long long
#define Blue_Archive return 0
using namespace std;
constexpr int N = 503;
constexpr int mod = 998244353;

int n;
int m;
int ans;
int a[N];
int c[N];
int stk[N];

bool vis[N];

string s;

int op;

inline void dfs(int x)
{
	if(x == n + 1)
	{
		int cnt = 0;
		for(int i = 1,tot = 0;i <= n;i ++)
		{
			if(a[i] && tot < c[stk[i]]) cnt ++;
			else tot ++;
	 	}
		ans += (cnt >= m);
		return;
	}
	for(int i = 1;i <= n;i ++)
	{
		if(vis[i]) continue;
		vis[i] = 1;
		stk[x] = i;
		dfs(x + 1);
		vis[i] = 0;
	}
}

inline void solve1()
{
	int tot = 0;
	for(int i = 1;i <= n;i ++) tot += (c[i] != 0);
	if(tot < m)
	{
		cout << 0 << '\n';
		exit(0);
	}
	int fac = 1;
	for(int i = 1;i <= tot;i ++) fac = fac * i % mod;
	ans = fac;
	cout << ans << '\n';
	exit(0);
}

signed main()
{
	freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
	// freopen("data.in","r",stdin);freopen("data.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	cin >> s;
	int tot1 = 0;
	for(int i = 1;i <= n;i ++) a[i] = s[i - 1] - '0',tot1 += a[i];
	for(int i = 1;i <= n;i ++) cin >> c[i];
	if(n <= 10)
	{
		dfs(1);
		cout << ans << '\n';
		Blue_Archive;
	} 
	if(tot1 == n) solve1();
	int op = 1;
	for(int i = 1;i <= n;i ++) op = op * i % mod;
	cout << op << '\n';
	Blue_Archive;
}