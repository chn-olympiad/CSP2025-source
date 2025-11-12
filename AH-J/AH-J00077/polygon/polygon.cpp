#include<bits/stdc++.h>
using namespace std;
int a[5010];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long ans=1,anse=1,sum=0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=3;i<=n;i++)
    {
		for(int j=n;j>=n-i+1;j--)ans=ans*j%998244353;
		for(int j=1;j<=i;j++)
		{
			anse=anse*j%998244353;
		}
		sum=(sum+ans/anse)%998244353;
		anse=1;
		ans=1;
	}
	cout<<sum;
    return 0;
}
