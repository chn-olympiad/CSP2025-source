#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m;
int a[505];
int s[505];
string x;
bool flag;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>x;
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		if(x[i]=='0')
		{
			flag=1;
		}
	}
	if(m==n)
	{
		if(flag)
		{
			cout<<0;
			return 0;
		}
		else
		{
		s[0]=1;
		for(int i=1;i<n;i++)
		{
			s[i]=i*s[i-1]%mod;
		}
		printf("%lld",s[m]);
		return 0;
		}
	}
	if(!flag)
	{
		s[0]=1;
		for(int i=1;i<n;i++)
		{
			s[i]=i*s[i-1]%mod;
		}
		printf("%lld",s[m]);
		return 0;
	}
	return 0;
}
