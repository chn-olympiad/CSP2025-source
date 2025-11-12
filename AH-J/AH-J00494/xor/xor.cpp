#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500005];
struct Node{
	int lx,rx;
}x[500005];
bool cmp(Node x,Node y)
{
	if(x.lx!=y.lx)
	{
		return x.lx<y.lx;
	}
	else if(x.rx!=y.rx)
	{
		return x.rx<y.rx;
	}
}
long long dp[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int i,j,l;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int cnt=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-i+1;j++)
		{
			long long xo=a[i];
			for(l=i+1;l<=i+j-1;l++)
			{
				xo^=a[l];
			}
			if(xo==k)
			{
				cnt++;
				x[cnt].lx=i;
				x[cnt].rx=i+j-1;
			}
		}
	}
	sort(x+1,x+1+cnt,cmp);
	for(i=1;i<=cnt;i++)
	{
		dp[i]=1;
	}
	for(i=1;i<=cnt;i++)
	{
		for(j=1;j<i;j++)
		{
			if(x[i].lx>x[j].rx)
			{
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
	}
	long long maxn=0;
	for(i=1;i<=cnt;i++)
	{
		maxn=max(maxn,dp[i]);
	}
	cout<<maxn;
	return 0;
}
