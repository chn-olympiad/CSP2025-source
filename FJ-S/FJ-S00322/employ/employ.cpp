#include<cstdio>
#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int n,m,c[501],a[501],b[501],ans=1,mod=998244353,d[501];
char ch[501];
inline void solve1()
{
	for(int i=2;i<=n;i++)
		ans=(ans*i)%mod;
	cout<<ans;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	std::cin.tie(0)->sync_with_stdio(false);
	cin>>n>>m;
	cin>>ch+1;
	int res=0;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i],a[i]=(ch[i]-'0')^1,b[i]+=a[i-1];
		if(c[i]==0) res++;
	}
	sort(c+1,c+n+1);
	int l=1;
	for(int i=1;i<=n;i++)
	{
		while(b[i]-a[i]>=c[l]&&l<=n) ++l;
		d[i]=n-l+1;
	}
	if(res>n-m)
	{
		cout<<0;
		return 0;
	}
	if(b[n]==0)
	{
		solve1();
		return 0;
	}
	if(m==n)
	{
		for(int i=1;i<=n;i++)
			if(d[i]<n-i+1)
			{
				cout<<0;
				return 0;
			}
		res=0;
		for(int i=1;i<n;i++)
		{
			if(a[i]==a[i+1]) res++;
			else
			{
				res+=1;
				while(res--)
					ans=(ans*res)%mod;
			}	
		}
		if(res)
		{
			res+=1;
			while(res--)
				ans=(ans*res)%mod;
		}	
		cout<<ans;
		return 0;
	}
}
