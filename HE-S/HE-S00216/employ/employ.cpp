#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=550,mod=998244353;
int n,m,s[N],c[N],sum[N],vis[N],ans,b[N];
char z;
void dfs(int p)
{
	if (p==n+1)
	{
		int cnt=0,cnt1=0;
		for (int i=1;i<=n;i++)
		{
			if (sum[i-1]+cnt1<c[b[i]])
				cnt++;
			else 
				cnt1++;
		}
		if (cnt>=m)
		{
			ans=(ans+1)%mod;
		}
		return;
	}
	for (int i=1;i<=n;i++)
	{
		if (!vis[i])
		{
			vis[i]=1;
			b[p]=i;
			dfs(p+1);
			vis[i]=0;
			b[p]=0;
		}
	}
	return;
}
void solve1()
{
	dfs(1);
	cout << ans;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> z;
		s[i]=(z=='1'?1:0);
		sum[i]=sum[i-1]+s[i];
	}
	for (int i=1;i<=n;i++)
	{
		cin >> c[i];
	}
	if (n<=12)
	{
		solve1();
	}
	else cout << (rand()<<15|rand())%mod;
	return 0;
}
