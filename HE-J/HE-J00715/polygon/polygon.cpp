#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353,N = 5e3 + 10;
int n,ans;
int a[N];
int jc[N];
void dfs(int x,int cnt,int ma,int s)
{
	if(x == n + 1)
	{
		if(s <= ma * 2)
		{
			return ;
		}
		if(cnt >= 3)
		{
			ans ++;
			ans %= mod;
		}
		return ;
	}
	dfs(x + 1,cnt,ma,s);
	dfs(x + 1,cnt + 1,max(ma,a[x]),s + a[x]);
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}
	dfs(1,0,-1,0);
	cout << ans << '\n';
	return 0;
}
