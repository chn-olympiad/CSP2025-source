#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e2 + 5;
const int mod = 998244353;

int n,m,c[N],sum;
ll num;
string s;
bool vis[N];

ll dfs(int step,int ans)
{
	if (step>n)
	{
		if (ans>=m)return 1;
		return 0;
	}
	ll sum = 0;
	for (int i = 1;i <= n;i++)
	{
		if (vis[i])continue;
		vis[i]=1;
		if (step-ans-1>=c[i]||s[step]=='0')
			sum=(sum+dfs(step+1,ans))%mod;
		else sum=(sum+dfs(step+1,ans+1))%mod;
		vis[i]=0;
	}
	return sum;
}
void gc()
{
	cin >> n >> m;
	cin >> s;
	for (int i = 1;i <= n;i++)
	{
		cin >> c[i];
		if (c[i]==0)sum++;
	}
	if (n-sum<m)
	{
		cout << 0;
		return;
	}
	bool flag = 1;
	int len = s.length();
	s = " "+s;
	for (int i = 1;i <= len;i++)
		if (s[i]!='1')flag=0;
	if (flag)
	{
		ll ans=1;
		for (int i = 1;i <= n;i++)
			ans=ans*i%mod;
		cout << ans%mod;
	}
	else
		cout << dfs(1,0)%mod;
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	gc();
	return 0;
}
