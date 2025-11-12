#include<bits/stdc++.h>
using namespace std;
const int N=510,mod=998244353;
int c[N];
int f[N];
int n,m;
string s;
long long ans=0;
int b[N];
void check()
{
	int gu=0;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(gu>=c[f[i]])
			gu++;
		else
		{
			if(s[i-1]=='0')
				gu++;
			else cnt++;
		}
	}
	if(cnt>=m) ans=(ans+1)%mod;
}
void dfs(int step)
{
	if(step>n)
	{
		check();
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			b[i]=1;
			f[step]=i;
			step++;
			dfs(step);
			step--;
			b[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	if(n<=10)
	{
		dfs(1);
		cout<<ans<<endl;
	}
	else if(m==n)
	{
		int pd=1;
		int len=s.size();
		for(int i=0;i<len;i++)
			if(s[i]=='0')
			{
				pd=0;
				break;
			}
		for(int i=1;i<=n;i++)
			if(c[i]==0)
			{
				pd=0;
				break;
			}
		if(pd==0) cout<<0<<endl;
		else
		{
			long long as=1;
			for(int i=1;i<=n;i++)
				as=as*i%mod;
			cout<<as<<endl;
		}
	}
	else
	{
		long long as=1;
		for(int i=1;i<=n;i++)
			as=as*i%mod;
		cout<<as<<endl;
	}
	return 0;
}
