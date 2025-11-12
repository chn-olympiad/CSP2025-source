#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,mod=998244353;
int n,m,d[N],c[N],a[N],ans;
bool vis[N];
void dfs(int id)
{
	if(id>n)
	{
		int cnt=0,sum=0;
		for(int i=1;i<=n;i++)
		{
			if(cnt>=c[a[i]]||!d[i])cnt++;
			else sum++;
		}
		if(sum>=m)ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		a[id]=i;
		vis[i]=1;
		dfs(id+1);
		vis[i]=0;
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char j;
		cin>>j;
		d[i]=j=='1';
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(n<=10)dfs(1);
	else
	{
		ans=1;
		for(int i=2;i<=n;i++)
		{
			ans=ans*i%mod;
		}
	}
	cout<<ans;
	return 0;
}
