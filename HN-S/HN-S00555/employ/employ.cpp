#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 505,mod =998244353;
int n,m,a[N],box[N],ans = 0;
string s;
bool vis[N];

void dfs(int steps,int cnt)
{
	if(steps > n)
	{
		if(cnt >= m) ans++;
		return;
	}
	for(int i = 1;i <= n;i++)
	{
		if(vis[i]) continue;
		vis[i] = 1;
		box[steps] = i;
		if(a[i] > steps-cnt-1 && s[steps] == '1') dfs(steps+1,cnt+1);
		else dfs(steps+1,cnt);
		vis[i] = 0;
	}
	return;
}

signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> s;
	s = " "+s+" ";
	for(int i = 1;i <= n;i++) cin >> a[i];
	dfs(1,0);
	cout << ans%mod;
	return 0;
}
