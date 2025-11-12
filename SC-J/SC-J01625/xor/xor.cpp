#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005],ps[200005];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,l=0,ans=0;cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i],ps[i]=ps[i-1]^a[i];
	if(n<=10000) 
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=l+1;j<=i;j++)
			{
				if((ps[i]^ps[j-1])==k)
				{
					l=i;
					ans++;
					break;
				}
			}
		}
		cout<<ans;
	}
	else
	{
		if(k>1)cout<<0;
		else if(k==0)
		{
			for(int i=1;i<=n;i++)
				if(a[i]==0)ans++;
			int cnt=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1)cnt++;
				else cnt=0;
				if(cnt==2)
				{
					ans++;
					cnt=0;
				}
			}
			cout<<ans;
		}
		else
		{
			for(int i=1;i<=n;i++)
				if(a[i]==1)ans++;
			cout<<ans;
		}
	}
	return 0;
}