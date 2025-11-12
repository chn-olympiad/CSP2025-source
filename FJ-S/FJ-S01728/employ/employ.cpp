#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int M = 510;
int fl[M];
int n,m,ans;
string s;
int c[M],cnt;
int id[M];
int vis[M];
int dfs(int pos, int gv, int cs)
{
	int res = 0;
	int g = '1' - s[id[pos]];
	gv += id[pos] - id[pos-1] - 1;
	if(cs <= gv) g = 1;
	gv += g;
	
	if(id[pos]-gv >= m) return fl[n-pos];
	if(n-gv < m || cnt == pos) return 0;
	
	for(int i=0; i<=n; i++)
	{
		if(!vis[i]) continue;
		vis[i]--;
		res = (res + (vis[i]+1)*dfs(pos+1,gv,i))%mod;
		vis[i]++;
	}
	return res;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	s = " " + s;
	for(int i=1; i<=n; i++)
	{
		if(s[i] == '1')
		{
			id[++cnt] = i;
		}
	}
	bool flag = 1;
	for(int i=1; i<=n; i++)
	{
		cin >> c[i];
		vis[c[i]]++;
	}
	fl[1] = fl[0] = 1;
	for(int i=2; i<=n; i++) fl[i] = (fl[i-1] * i) % mod;
	for(int i=0; i<=n; i++)
	{
		if(vis[i] == 0) continue;
		vis[i]--;
		ans = (ans + (vis[i]+1)*dfs(1,0,i))%mod;
		vis[i]++;
	}
	cout << ans;
	return 0;
}
