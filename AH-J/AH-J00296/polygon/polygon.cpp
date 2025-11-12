#include<bits/stdc++.h>
using namespace std;
int n,a[5001];
long long cnt;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n!=3)
	{
		for(int i=3;i<=n;i++)
		{
			for(int j=n-i+1;j>=1;j--)
			{
				for(int k=j;k>=1;k--)
				{
					cnt+=k;
					cnt%=998244353;
				}
			}
		}
		cout<<cnt;
		return 0;
	}
	else if(n==3)
	{
		int sum,maxn=INT_MIN;
		for(int i=1;i<=n;i++)
		{
			sum+=a[i];
			maxn=max(maxn,a[i]);
		}
		if(sum>(2*maxn))
		{
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}
}
