#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
const int maxn = 510;
int n, m, s[maxn], c[maxn], b[maxn], p[maxn], ans, Tm;
void solve()
{
	Tm++;
	int cnt = 0, sum = 0;
	for(int i=1;i<=n;i++)
	{
		int u = p[i];
		if(s[i]==0 || cnt>=c[u])
			cnt++;
		else
			sum++;
	}
	if(sum>=m) ans=(ans+1)%mod;
}
void dfs(int cur)
{
	if(Tm*n>500000000)
		return;
	if(cur>n)
	{
		solve();
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			p[cur] = i;
			b[i] = 1;
			dfs(cur+1);
			b[i] = 0;
		}
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	string S;
	cin>>S;
	for(int i=1;i<=n;i++)
		s[i] = S[i-1]-'0';
	for(int i=1;i<=n;i++)
		cin>>c[i];
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
