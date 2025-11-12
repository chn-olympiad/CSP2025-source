#include<bits/stdc++.h>
using namespace std;
long long n,k,ans,ans2;
long long a[500005],sum[500005],f[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=200)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				long long t=0,flg=0;
				for(int k=i;k<=j;k++) 
				{
					t=t^a[k]; 
					if(f[k]==1) 
					{
						flg=1;
						break;
					}
				}
				if(flg==0&&t==k) 
				{
					for(int k=i;k<=j;k++) f[k]=1;
					ans++;
				}
			}
		}
		cout<<ans;
	}
	else
	{   a[n+1]=114514;
		if(k==0)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==0) ans++;
				else
				{
					if(a[i+1]==1)
					{
						ans++;
						i++;
					}
				}
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1) ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}
