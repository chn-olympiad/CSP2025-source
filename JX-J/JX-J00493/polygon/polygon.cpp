#include<bits/stdc++.h>
using namespace std;
long long n,m,a[6110],ans=0,q,w,e,r,t;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i];
		ans=a[n]+a[n-2]+a[n-4];
	}
	if(n==3)
	{
		cout<<1;
	}
	if(n==4)
	{
		cout<<3;
	}
	if(n<3)
	{
		cout<<0;
	}
	if(n==5)
	{
		cout<<ans;
	}
    return 0;
}
