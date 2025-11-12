#include <bits/stdc++.h>
#define long long int;
using namespace std;
int n,m;
const int mod=998244353;
const int N=6e3;
int a[N],c[N];
int book[N];
int ans;
void dfs(int step,int len,int maxn)
{
	if(step>m)
	{
		if(len>maxn*2)
		{
			ans++;
			ans%=mod;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(book[i]==0&&i>c[step-1])
		{
			book[i]=1;
			c[step]=i;
			dfs(step+1,len+a[i],max(maxn,a[i]));
			book[i]=0;
			c[step]=0;
		}
	}
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=3;i<=n;i++)
	{
		m=i;
		dfs(1,0,0);
	}
	cout<<ans%mod;
	return 0;
}
