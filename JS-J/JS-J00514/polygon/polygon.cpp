#include<bits/stdc++.h>
using namespace std;
int n,a[2][5010],m,q=998244353;
int h(int z,int x)
{
	int ma=0;
	for(;x;x--)
	{
		if(a[0][z+x]>ma)
		{
			ma=a[0][z+x];
		}
	}
	return ma;
}
int f(int z,int x)
{
	if(a[1][z+x]-a[1][z]>h(z,x))
	{
		return 1;
	}
	else return 0;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n>>a[0][0];
	a[1][0]=a[0][0];
	for(int i=1;i<n;i++)
	{
		cin>>a[0][i];
		a[1][i]=a[0][i]+a[1][i-1];
	}
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	if(n==3)
	{
		cout<<f(0,3);
		return 0;
	}
	for(int i=0;i<n-3;i++)
	{
		for(int j=3;j<=n-i;j++)
		{
			m+=f(i,j);
//			cout<<m<<"--"<<i<<" "<<j<<endl;
			if(m>q) m-=q;
		}
	}
	cout<<m;
	return 0;
}
