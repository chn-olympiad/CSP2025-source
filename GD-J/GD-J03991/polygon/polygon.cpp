#include<iostream>
#include<algorithm>
using namespace std;
long long n,k,a[1000005],b[10005][10005],sum;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool b=0;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			b=1;
		}
	}
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	if(n==3)
	{
		sort(a+1,a+3+1);
		if(a[1]+a[2]>a[3])
		{
			cout<<1;
			return 0;
		}
		cout<<0;
	}
	return 0;
}
