#include <bits/stdc++.h>
using namespace std;
int n,k,a[500010],dp[500010],b=1,t[500010];
int minx=INT_MAX,miny=INT_MIN;
struct xbx{
	int x,y;
}xb[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	dp[1]=a[1];
	for(int i=2;i<=n;i++) dp[i]=(dp[i-1]^a[i]);
	for(int i=1;i<=n;i++)
	{
		if(a[i]==k)
		{
			xb[b].x=xb[b].y=i,minx=min(minx,i);
			miny=max(miny,i),b++;
		}
	}
	for(int i=n;i>=2;i--)
	{
		for(int j=i-1;j>=1;j--)
		{
			if((dp[j]^dp[i])==k)
			{
				int f=j+1;
				if(i>=minx && i<=miny ||
				   f<=miny && f>=minx || 
				   i<=minx && f>=miny) b=b+1-1;
				else
				{
					xb[b].x=f,xb[b].y=i;
					minx=xb[b].x,miny=xb[b].y,b++;
				}
			}
		}
	}
	for(int i=2;i<=n;i++)
	{
		if(dp[i]==k)
		{
			if(1>=minx && 1<=miny ||
			   i<=miny && i>=minx || 
			   1<=minx && i>=miny) b=b+1-1;
			else
			{
				xb[b].x=1,xb[b].y=i;
				minx=xb[b].x,miny=xb[b].y,b++;
			}
		}
	}
	cout<<b-1;
	return 0;
}
