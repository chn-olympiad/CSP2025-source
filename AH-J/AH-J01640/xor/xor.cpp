#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],maxn=-1,cnt;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
		if(a[i]==1)cnt++;
	}
	if(n==1)
	{
		if(k!=a[1])cout<<0;
		else cout<<1;
		return 0;
	}
	if(maxn==0)
	{
		if(k==0)cout<<n;
		else cout<<0;
		return 0;
	}
	if(cnt==n)
	{
		if(k<=1)
		{
			if(k==1)cout<<n;
			else cout<<n/2;
		}
		else cout<<0;
	}
	else if(maxn<=1)
	{
		if(k<=1)
		{
			if(k==1)cout<<cnt;
			else
			{
				long long florr=1,ans;//woaiwanflorr
				for(int i=1;i<=n;i++)
				{
					if(a[i]==a[i+1]&&a[i]==1)
					{
						florr++;
					}
					else
					{
						ans+=florr/2;
						florr=1;
					}
				}
				cout<<ans+n-cnt;
			}
		}
		else cout<<0;
	}
	else
	{
		cout<<n/2;
	}
}
//30pts 能拿2=么qwq
