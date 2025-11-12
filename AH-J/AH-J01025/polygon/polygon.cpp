#include<bits/stdc++.h>
using namespace std;
int a[5010],b[5010];
long long s=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int i,j,k,n;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	b[1]=a[1];
	b[2]=b[1]+a[2];
	for(i=3;i<=n;i++)
	{
		b[i]=b[i-1]+a[i];
	}
	for(i=3;i<=n-1;i++)
	{
		for(j=i;j<=n;j++)
		{
			for(k=j-i;k<=j-1;k++)
			{
				if(b[j]-a[k]-b[k-i]>a[j]*2&&k!=0)
				{
					s=(s+1)%998244353;
				}
			}
		}
	}
	if(b[n]>a[n]*2)
	{
		s=(s+1)%998244353;
	}
	cout<<s%998244353;
	return 0;
}
