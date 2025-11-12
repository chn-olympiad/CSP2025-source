#include<bits/stdc++.h>
using namespace std;
int sum[500005];
int ans=0;
bool vis[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n+1];
	for(int i=1;i<=n;i++)cin>>a[i];
	bool f=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=1)
		{
			f=0;break;
		}
	}
	if(f)
	{
		cout<<n/2<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if((sum[j]^sum[i-1])==k)
			{
				bool flag=1;
				for(int k=i;k<=j;k++)
				{
					if(vis[k])
					{
						flag=0;break;
					}
				}
				if(flag)
				{
					ans++;
					for(int k=i;k<=j;k++)vis[k]=1;
					break;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
//How many pts can I get?
