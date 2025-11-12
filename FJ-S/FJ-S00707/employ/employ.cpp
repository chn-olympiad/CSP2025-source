#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+5;
const ll mod=998244353;
ll n,m,a[N],t,b[N],v[N],ans,w[N],a1[N],b1[N];
string s;
void dfs(int x)
{
	if(x==n)
	{
		int p=0,d=0;
		for(int i=1;i<=n;i++)
		{
			if(p>=a[b[i]])
			{
				p++;
				if(p>n-m)
				{
					break;
				}
				continue;
			}
			if(s[i-1]=='0')
			{
				p++;
				if(p>n-m)
				{
					break;
				}
			}
			else
			{
				d++;
				if(d>=m)
				{
					break;
				}
			}
		}
		if(d>=m)
		{
			ans++;
		}
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(v[i]==0)
		{
			b[x+1]=i;
			v[i]=1;
			dfs(x+1);
			v[i]=0;
		}
	}
}
ll ef(ll x)
{
	ll l=1,r=n,ans=0;
	while(l<=r)
	{
		ll mid=(l+r)/2;
		if(a[mid]>=x)
		{
			ans=mid;
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	return ans;
}
ll ef2(ll x)
{
	ll l=1,r=n,ans=0;
	while(l<=r)
	{
		ll mid=(l+r)/2;
		if(a[mid]<x)
		{
			ans=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	return ans;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	w[1]=1;
	for(int i=2;i<=n;i++)
	{
		w[i]=w[i-1]*i%mod;
	}
	ll num=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=10)
	{
		dfs(0);
		cout<<ans;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		num+=s[i]-'0';
	}
	if(m>num)
	{
		cout<<0;
		return 0;
	}
	if(m==n)
	{
		if(num!=n)
		{
			cout<<0;
			return 0;
		}
		sort(a+1,a+n+1);
		if(a[1]==0)
		{
			cout<<0;
			return 0;
		} 
		ans=1;
		for(int i=1;i<=n;i++)
		{
			ans*=i;
			ans=ans%mod;
		}
		cout<<ans;
		return 0;
	}
	if(m==1)
	{
		sort(a+1,a+n+1); 
		ll p=0;
		b1[0]=1;
		for(int i=0;i<n;i++)
		{
			if(s[i]-'0'==1)
			{
				ll k=ef2(i+1);
				if(k==0)
				{
					cout<<w[n];
					return 0;
				}
				a1[++p]=k-(p-1);
				b1[p]=b1[p-1]*a1[p]%mod;
			}
		}
		p=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]-'0'==1)
			{
				ll k=ef(i+1);
				ll res=(n-k+1);
				res=res*b1[p]%mod*w[n-p-1]%mod;
				ans=(ans+res)%mod;
//				cout<<res<<' ';
				p++;
			}
		}
		cout<<ans;
		return 0;
	}
	if(num==n)
	{
		ans=1;
		sort(a+1,a+n+1);
		int p=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=0)
			{
				p=i;
				break;
			} 
		}
		if(p-1>n-m)
		{
			cout<<0;
			return 0;
		}
		for(int i=1;i<p;i++)
		{
			ans*=i;
			ans=ans%mod;
		}
		for(int i=p;i<=n;i++)
		{
			ans*=n-p+1;
		}
		cout<<ans;
		return 0;
	}
	else
	{
		cout<<114514;
		return 0;
	}
	return 0;
}
