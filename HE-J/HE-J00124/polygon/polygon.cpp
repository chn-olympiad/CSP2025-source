#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum=0,ma=-1;
int main()
{   
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		ma=max(ma,a[i]);
	}
    if(n<3)
	cout<<0;
	if(n==3)
	{
		if(sum>2*ma)
		cout<<1%998244353;
		else cout<<0;
	}
    return 0;
}
