#include<bits/stdc++.h>
using namespace std;
long long a[5001];
bool cmp(long long x,long long y)
{
	return x>y;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,i,j,k,ans=0;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	if(n<=2) cout<<0;
	else
	if(n==3)
	{
		if(a[1]<a[2]+a[3]) ans++;
		if(a[2]<a[1]+a[3]) ans++;
		if(a[3]<a[1]+a[2]) ans++;
		cout<<ans;
	}
	else
	if(a[1]==1 or a[1]==a[n])
	{
		for(i=3;i<=n;i++)
		{
			long long sum=1;
			for(j=n;j>i;j--)
				sum=sum*j;
			ans+=sum;
		}
		cout<<ans;
	}
	else
	if(n<=20)
	{
		for(i=1;i<=n-2;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				for(k=j+1;k<=n;k++)
				{
					if((a[j]+a[k])<a[i])
					{
						ans++;
						ans=ans%998224353;
					}
				}
			}
		}
		cout<<(ans*3)%998224353;
	}
	return 0;
}
