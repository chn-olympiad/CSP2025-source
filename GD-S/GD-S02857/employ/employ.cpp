#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n,m,c[505],a[505],ans;
bool vis[505];
string s;
bool check()
{
	int cnt = 0,l = 0;
	for(int i = 1; i <= n; i++)
	{
		if(s[i-1] == '1' && l < c[a[i]]) cnt++;
		else l++;
	}
	return cnt >= m;
}
void dfs(int step)
{
	if(step > n)
	{
		ans += check();
		ans %= mod;
		return;
	}
	for(int i = 1; i <= n; i++)
	{
		if(vis[i]) continue;
		vis[i] = true;
		a[step] = i;
		dfs(step+1);
		vis[i] = false;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= n; i++)
	{
		cin >> c[i];
	}
	dfs(1);
	cout << ans%mod << endl;
	return 0;
}
