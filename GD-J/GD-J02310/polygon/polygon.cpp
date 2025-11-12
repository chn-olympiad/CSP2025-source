#include<bits/stdc++.h>
using namespace std;
long long a[1000000],num,n;
long long cf(int g)
{
	int s=1;
	for(int i=1;i<=g;i++)s*=2;
	return s%998244353;
}
long long ss2(int h,int e)
{
	long long u=0;
	for(int i=e-1;i>=1;i--)
	{
		if(a[e]+a[i]>h)u+=cf(i-1);
		if(a[e]+a[i]==h)u+=cf(i-1)-1;
	}
	return u%998244353;
}
long long ss1(int x,int q)
{
	int y=0;
	for(int i=q;i>=2;i--)
	{
		y+=ss2(x,i);
	}
	return y%998244353;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
     scanf("%lld",&n);
     for(int i=1;i<=n;i++)
       scanf("%lld",&a[i]);
       sort(a+1,a+n+1);
       for(int i=3;i<=n;i++)
       {
       	num+=ss1(a[i],i-1);
	   }
	   printf("%lld",num%998244353);
	return 0;
} 
