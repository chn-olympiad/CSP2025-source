#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e9;
ll n,a[5001],num,maxn,ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	if(n==3)
	{
		if(a[1]+a[2]+a[3]>2*a[3]) cout<<1;
		else cout<<0;
		return 0;
	}
	for(int k=3;k<=n;k++)
	{
		for(int i=1;i<=n-k+1;i++)
		{
			for(int j=0;j<k;j++)
			{
				num+=a[i+j];
			}
			if(num>2*a[i+k-1])
			{
				ans+=n-i+1-k+1;
				ans+=n-(i+k-1);
			}
		}
	}
	cout<<ans;
	return 0;
}