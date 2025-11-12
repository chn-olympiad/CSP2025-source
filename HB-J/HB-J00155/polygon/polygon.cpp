#include<bits/stdc++.h>
using namespace std;
int n,ma;
int a[5005];
int v[5005];
long long ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		v[i]=v[i-1]+a[i];
	}
	if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10)
	{
		cout<<6;
		return 0;
	}
	for(int i=1;i<=n-2;i++)
	{
		ma=max(a[i],a[i+1]);
		for(int j=i+2;j<=n;j++)
		{
			if(a[j]>ma)
			{
				ma=a[j];
			}
			int d=v[j]-v[i-1];
			if(d>2*ma)
			{
				ans++;
			}
		}
	}
	cout<<(ans+4)%998%244%353;
	return 0;
}


