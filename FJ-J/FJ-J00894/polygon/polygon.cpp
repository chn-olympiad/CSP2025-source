#include<bits/stdc++.h>
using namespace std;
long long n,a[50005],ans,su,maxx=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		su+=a[i];
		maxx=max(a[i],maxx);
	}
	if(n==3)
	{
		if(su>maxx*2)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	return 0;
}
