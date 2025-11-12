#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	long long num,sum;
	for(long long i=1;i<=n;i++)
	{
		num*=i;
	}
	for(long long i=1;i<=m;i++)
	{
		sum*=i;
	}
	num/=sum;
	cout<<num%998244353;
	return 0;
}
