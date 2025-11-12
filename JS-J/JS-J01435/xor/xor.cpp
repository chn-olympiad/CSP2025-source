#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector> 

using namespace std;
int a[500005],f[500005],l;
long long dp[500005];
struct XOR
{
	int x,y;
}p[100000000];

bool comp(XOR a,XOR b)
{
	return a.x==b.x?a.y<b.y:a.x<b.x;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i]=f[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if((f[i]^f[j-1])==k)
			{
				p[++l].x=j;
				p[l].y=i;
			}
		}
	}
	sort(p+1,p+l+1,comp);
	long long ans=0;
	for(int i=1;i<=l;i++)
	{
		long long maxx=0;
		for(int j=1;j<i;j++)
		{
			if(p[j].y<p[i].x)
			{
				if(dp[j]>maxx)
				{
					maxx=dp[j];
				}
			}
		}
		dp[i]=maxx+1;
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}
