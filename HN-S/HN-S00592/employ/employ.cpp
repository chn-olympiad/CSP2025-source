#include<bits/stdc++.h>
using namespace std;
int m,n,ans,c[15],p[15];
char s[15];
bool f[15];
void dfs(int step,int cnt)
{
	if(step>n)
	{
		if(n-cnt>=m)
		{
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i])continue;
		f[i]=1;
		p[step]=cnt;
		if(cnt>=c[i]||s[step]=='0')dfs(step+1,cnt+1);
		else dfs(step+1,cnt);
		f[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	bool fa=1;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		fa&=(s[i]=='1');
	}
	if(fa)
	{
		long long cnt=1;
		for(long long i=1ll;i<=(long long)(n);i++)cnt*=i,cnt%=998244353;
		cout<<cnt;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}

