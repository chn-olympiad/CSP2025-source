#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 505;
int n,m,c[N];
ll ans;
string s;
int vis[N];
void dfs(int p,int r)
{
	if(p>n) 
	{
		if(n-r>=m)
			ans = (ans+1)%998244353;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		vis[i] = 1;
		if(s[p] == '0' || r>=c[i]) r++;
		dfs(p+1,r);
		vis[i] = 0;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	s = "F"+s;
	for(int i=1;i<=n;i++)
		cin >> c[i];
	dfs(1,0);
	cout << ans;
	return 0;
}
