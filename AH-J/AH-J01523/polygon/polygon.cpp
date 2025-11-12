#include<bits/stdc++.h>
using namespace std;
long long n,a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	long long maxn=-1,t=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>maxn)maxn=a[i];
		t+=a[i];
	}
	if(maxn==1)
	{
		long long tt=0;
		for(int i=n-2;i>=1;i--)
		{
			for(int j=i;j>=1;j--)
			{
				tt+=j;
			}
		}
		printf("%lld",tt%998224353);
		return 0;
	}
	else if(n==3)
	{
		
		if(t>2*maxn){printf("1");return 0;}
		else {printf("0");return 0;}
	}
	return 0;
}
