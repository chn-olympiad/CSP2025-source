#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,N=510;
long long ans=0,a[N],c[N];
char s[N];
bool vis[N];
int n,m;
void dfs(int now)
{
	if(now>=n)
	{
		int cnt=0,ret=0;
		for(int i=0;i<n;i++)
		{
			if(cnt>=c[a[i]]||s[i]=='0')
			{
				cnt++;
				continue;
			}
			ret++;
		}
		if(ret>=m) ans=(ans+1)%mod;
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(vis[i]) continue;
		vis[i]=true;
		a[now]=i;
		dfs(now+1);
		vis[i]=false;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++) cin>>c[i];
	bool boo=true;
	for(int i=0;i<n;i++)
	{
		if(s[i]!='1') boo=false;
	}
	if(boo)
	{
		ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=(ans*i)%mod;
		}
		cout<<ans;
		return 0;
	}
	
	dfs(0);
	cout<<ans;
	return 0;
}

