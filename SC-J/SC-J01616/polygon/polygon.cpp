#include<iostream>
#include<cstdio>
using namespace std;
int n,maxn;
long long ans,cnt;
int a[5050];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<n-1;i++)
	{
		cnt=0,maxn=0;
		for(int j=i+1;j<n;j++)
		{
			for(int l=j+1;l<=n;l++)
			{
				cnt=a[i]+a[j]+a[l];
				maxn=max(a[i],a[j]);
				maxn=max(maxn,a[l]);
				if(cnt>2*maxn)
				ans++;
			}
		}
	}
	for(int i=1;i<n-2;i++)
	{
		cnt=0,maxn=0;
		for(int j=i+1;j<n-1;j++)
		{
			for(int l=j+1;l<n;l++)
			{
				for(int k=l+1;k<=n;k++)
				{
					cnt=a[i]+a[j]+a[l]+a[k];
					maxn=max(a[i],a[j]);
					maxn=max(maxn,a[l]);
					maxn=max(maxn,a[k]); 
					if(cnt>2*maxn)
					ans++;
				}
			}
		}
	}
	for(int i=1;i<n-3
	;i++)
	{
		cnt=0,maxn=0;
		for(int j=i+1;j<n-2;j++)
		{
			for(int l=j+1;l<n-1;l++)
			{
				for(int k=l+1;k<n;k++)
				{
					for(int m=k+1;m<=n;m++)
					{
						cnt=a[i]+a[j]+a[l]+a[k]+a[m];
						maxn=max(a[i],a[j]);
						maxn=max(maxn,a[l]);
						maxn=max(maxn,a[k]);
						maxn=max(maxn,a[m]);
						if(cnt>2*maxn)
						ans++;
					}
					
				}
			}
		}
	}
	cout<<ans%998244353;
	return 0;
}