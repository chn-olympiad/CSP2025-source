#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>

#define ll long long
#define rint register int

using namespace std;
using namespace __gnu_pbds;

const int N=500+10,mod=998244353;

int n,m;
string s;
int c[N];

int qpow(int a,int b,int p)
{
	int res=1,temp=a;
	while(b)
	{
		if(b&1)
		{
			res=1ll*res*temp%p;
		}
		
		temp=1ll*temp*temp%p;
		b>>=1;
	}
	
	return res;
}


int p[N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m>>s;
	s=" "+s;
	
	for(rint i=1;i<=n;++i)
	{
		cin>>c[i];
	}
	
	bool flag=1;
	
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='0')
		{
			flag=0;
		}
	}
	
	if(flag||n>18)
	{
		ll ans=1;
		for(rint i=1;i<=n;++i)
		{
			ans=1ll*i*ans%mod;
		}
		cout<<ans;
	}
	
	else
	{
		for(rint i=1;i<=n;++i)
		{
			p[i]=i;
		}
		
		
		ll ans=0;
		do
		{
			int fail=0;
			for(rint i=1;i<=n;++i)
			{
				if(s[i]=='0')
				{
					++fail;
				}
				
				else if(fail>=c[p[i]])
				{
					++fail;
				}
			}
			
			
			if(n-fail>=m)
			{
				++ans;
			}
		}while(next_permutation(p+1,p+n+1));
		
		cout<<ans;
	}
}