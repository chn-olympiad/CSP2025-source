#include<bits/stdc++.h>
using namespace std;
long long jiecheng(long long x)
{
	long long l=1;
	for(long long j=2;j<=x;++j) l*=j;
	return l;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	cin>>n;
	long long s=0;
	for(long long i=3;i<=n;++i)
	{
		s=(s+jiecheng(n)/(jiecheng(i)*jiecheng(n-i)))%998244353;
	}
	cout<<s;
	return 0;
}
