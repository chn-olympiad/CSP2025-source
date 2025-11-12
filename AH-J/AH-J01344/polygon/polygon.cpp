#include<bits/stdc++.h>
using namespace std;
long long n,a[10001],flag=0,k=0,ans;
int cmp(int a,int b)
{
	return a>b;
}
int jx(int a)
{
	long long s=1;
	if(a==0) return 1;
	for(int i=1;i<=a;i++)
	{
		s=s*i;
	}
	return s;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i];
		if(a[i]==1) flag++;
	}
	sort(a+1,a+n+1,cmp);
	if(flag==n)
	{
		for(int i=3;i<=n;i++)
		{
			k=(k+jx(n)/(jx(i)*jx(n-i)))%998244353;
		}
		ans=k%998244353;
		cout<<ans;
		return 0;
	}
	if(n==3)
	{
		if(a[3]>=a[1]+a[2]) cout<<0;
		else cout<<1;
		return 0;
	}
	else
	{
		for(int i=3;i<=n;i++)
		{
			k+=jx(n)/(jx(i)*jx(n-i))%998244353;
		}
		ans=k%998244353;
		cout<<ans;
		return 0;
	}
    return 0;
}
