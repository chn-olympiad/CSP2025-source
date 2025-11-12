#include <bits/stdc++.h>
using namespace std;
int a[5010];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int maxv=0,ans=0;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			for(int k=j+1;k<n;k++)
			{
				maxv=max(a[i],a[j]);
				maxv=max(maxv,a[k]);
				if(a[i]+a[j]+a[k]>2*maxv)
				{
					ans++;
				}
				for(int q=k+1;q<n;q++)
				{
					maxv=max(maxv,a[q]);
					if(a[i]+a[j]+a[k]+a[q]>2*maxv)
					{
						ans++;
					}
					for(int w=q+1;w<n;w++)
					{
						maxv=max(maxv,a[w]);
						if(a[i]+a[j]+a[k]+a[q]+a[w]>2*maxv)
						{
							ans++;
						}
					}
				}
			}
		}
	}
	cout<<ans%998244353;
	return 0;
}
