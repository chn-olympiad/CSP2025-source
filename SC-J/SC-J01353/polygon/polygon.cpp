#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int n,cnt,maxn;
int a[5005];

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cnt+=a[i];
		maxn=max(maxn,a[i]);
	}
	if(n==3)
	{
		if(2*maxn>cnt)
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
	return 0;
}