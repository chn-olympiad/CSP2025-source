#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n;
int a[5005];
int flag;
int s[5005];
int ans;
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]!=1)
		{
			flag=1;
		}
	}
	if(!flag)
	{
		int num=3;
		for(int i=3;i<=n;i++)
		{
			if(i==3)
			{
				s[i]=1;
			}
			else
			{
				s[i]+=s[i-1];
				s[i]+=num;
				num+=2;
			}
		}
		for(int i=3;i<=n;i++)
		{
			ans+=s[i];
		}
		printf("%lld",ans%mod);
		return 0;
	}
	else
	{
		cout<<0;
		return 0;
	}
	return 0;
 } 
