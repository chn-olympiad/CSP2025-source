#include <bits/stdc++.h>
using namespace std;
long a[5010];
long A(int x,int y)
{
	if(y==1)
	{
		return x;
	}
	return A(x-1,y-1)*x;
}
long C(int x,int y)
{
	if(y==1)
	{
		return x;
	}
	if(y>x/2)
	{
		return C(x,x-y);
	}
	return A(x,y)/A(y,y);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long n,max_=0,ans=0;
	scanf("%ld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%ld",&a[i]);
		max_=max(max_,a[i]);
	}
	if(max_==1)
	{
		for(int i=3;i<=n;i++)
		{
			ans+=C(n,i);
		}
		printf("%ld",ans%998244353);
	}
	
	
	return 0;
}