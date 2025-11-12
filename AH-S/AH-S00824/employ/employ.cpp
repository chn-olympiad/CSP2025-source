#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
long long a[510],f[510],ss[510];
long long mod=998244353;
int vis[510],p[510];
int sum[510];
long long ans;
long long jie(long long x)
{
	long long k=1;
	for(int i=2;i<=x;i++)
	{
		k*=i;
		k%=mod;
	}
	return k;
}
void check()
{
	int fail=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(fail>=a[p[i]])
		{
			fail++;
			continue;
		}
		if(s[i-1]=='0')
		{
			fail++;
		}
		else
		{
			cnt++;
		}
	}
	if(cnt>=m) ans++;
	ans%=mod;
	return ;
}
void dfs(int step)
{
	if(step==n+1)
	{
		check();
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			p[step]=i;
			dfs(step+1);
			p[step]=0;
			vis[i]=0;
		}
	}
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i];
	}
	if(m==n)
	{
		if(s.find('0')==string::npos)
		{
			cout<<1;
		}
		else cout<<0;
		return 0;
	}
	if(s.find('0')==string::npos)
	{
		long long ans=1;
		for(int i=1;i<=n;i++)
		{
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	if(m==1)
	{
		if(s.find('1')==string::npos) cout<<0;
		else
		{
			long long k=1;
			for(int i=1;i<n;i++)
			{
				k*=i;
				k%=mod;
			}
			for(int i=1;i<=n;i++)
			{
				f[a[i]]++;
			}
			for(int i=n;i>=1;i--)
			{
				ss[i]=ss[i+1]+f[i];
			}
			long long old=0;
			for(int i=0;i<s.size();i++)
			{
				if(s[i]=='1')
				{
					ans+=((ss[i+1]*k)%mod-(jie(old)*ss[i+1]%mod)+mod)%mod;
					ans+=mod;
					ans%=mod;
					old=ss[i+1];
				}
			}
		}
		cout<<ans;
		return 0;
	}
	dfs(1);
	cout<<ans;
    return 0;
}
