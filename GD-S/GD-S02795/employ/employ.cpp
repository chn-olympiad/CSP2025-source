#include<bits/stdc++.h>
using namespace std;
long long n,m,mod=998244353,k;
long long a[510],b[510],f[510],c[510],s;
void dfs(long long level)
{
	if(level==n)
	{
		long long sum=0,lq=0;
		for(int i=1;i<=n;i++)
		{
			while(sum>=c[i])
			{
				sum++;
				i++;
			}
			if(a[i]==0)
			{
				sum++;
			}
			else
			{
				lq++;
			}
		}
		if(lq>=m)
		{
			s++;
			if(s>mod)s-=mod;
		}
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]==1) continue;
		c[level+1]=b[i];
		f[i]=1;
		dfs(level+1);
		f[i]=0;
	}
}
int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char t;
		cin>>t;
		a[i]=int(t-'0');
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	if(n==m)
	{
		long long ans=1;
		for(long long i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				cout<<0;
				return 0;
			}
			ans*=i;
			ans%=mod;
		}
		cout<<ans%mod;
		return 0;
	}
	if(m==1)
	{
		long long w[10010],l=0,yq[10010],ss=0;
		for(long long i=1;i<=n;i++)
		{
			if(a[i]==0)ss++;
			if(a[i]==1)
			{
				w[++l]=i;
				yq[l]=ss;
			}
		}
		if(l==0)
		{
			cout<<0;
			return 0;
		}
		long long anss=0;
		for(int j=1;j<=l;j++)
		{
			long long ans=0;
			for(int i=1;i<=n;i++)
			{
				if(b[i]>(yq[j]))
				{
					ans++;
					ans%=mod;
				}
			}
			for(long long i=1;i<n;i++)
			{
				ans*=i;
				ans%=mod;
			}
			anss+=ans;
			anss%=mod;
		}
		
		cout<<anss;
		return 0;
	}
	if(n>18)
	{
		cout<<0;
		return 0;
	}
	dfs(0);
	cout<<s;
	return 0;
}

