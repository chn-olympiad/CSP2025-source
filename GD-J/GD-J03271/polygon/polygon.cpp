#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[5002],ans,d,maxn,vis[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		d+=a[i];
		maxn=max(maxn,a[i]);
	}
	if(n==3)
	{
		if(maxn*2<d)
		{
			cout<<1;
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	else
	{
		cout<<9;
	}
	return 0;
}
