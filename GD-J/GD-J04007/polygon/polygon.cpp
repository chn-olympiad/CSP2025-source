#include<bits/stdc++.h>
using namespace std;
long long n,a[504],ans=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+1+n);
	if(n==3)
	{
		if(a[1]+a[2]>a[3])
		{
			cout<<1;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	if(a[1+n]==1)
	{
		long long g=n-2;
		long long anser=(1+g)*g/2;
		cout<<anser;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
