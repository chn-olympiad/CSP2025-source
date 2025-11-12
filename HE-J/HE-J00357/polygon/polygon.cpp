#include<bits/stdc++.h>
using namespace std;
int n,k,a[10005],x,y;
long long h=1;
long long f(int a)
{
	int d=1;
	for(int i=1;i<=a;i++)d*=i;
	return d;
}
long long C(int a,int b)
{
	return f(a)/f(a-b)/f(b);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		{
			x+=a[i];
			y=a[1];
			if(y<a[i])y=a[i];
		}
		cout<<y;
	if(n<3)cout<<0;
	if(n==3)
	{
		if(x>2*y)cout<<1;
		else cout<<0;
	}
	if(y==1)
	{
		for(int i=3;i<n;i++)
		{
			h+=C(n,i);
			h=h%998244353;
		}
		cout<<h;
	}
	return 0;
}
