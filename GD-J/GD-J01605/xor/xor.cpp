#include<bits/stdc++.h>
using namespace std;
long long ans,n,p,a[100010],vis[100010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&p);
	for(long long i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(long long i=0;i<=n;i++)
	{
		for(long long j=1;j<=n-i;j++)
		{
			int sum=a[j],l=j,r=j+i;
			for(long long k=l+1;k<=r;k++)
			{
				if(vis[k]==1)
				{
					sum=-999999;
					break;
				}
				sum^=a[k];
			}
			if(sum==p)
			{	
				bool flag=true;
				for(long long k=l+1;k<=r;k++)
				{
					if(vis[k]==1)
					{
						ans--;
						flag=false;
						break;
					}
				}
				if(flag==true)
				{
					vis[l]=true;
					//cout<<l<<' '<<r<<endl;
					for(long long k=l+1;k<=r;k++)vis[k]=1;
				}
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
