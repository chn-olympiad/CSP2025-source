#include<bits/stdc++.h>
using namespace std;
int a[110],c[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		c[i]=-1; 
	}
	int s=0,cnt=0;
	for(int i=1;i<=n*m;i++)
	{
		int ans=-1,s=0;
		for(int j=1;j<=n*m;j++)
		{
			if(a[j]!=c[j])
			{
				if(a[j]>=ans)
				{
					ans=a[j];
					s=j;
				}
			}
		}
		c[s]=ans;
		if(ans!=a[1])
		{
			cnt++;
		}
		else
		{
			cnt++;
			break;
		}
	}
	int hs=0,ls=0;
	ls=(cnt+n-1)/n;
	cout<<ls<<' ';
	if(ls%2==0)
	{
		hs=n-cnt%n+1;
		if(hs==0)
		{
			hs++;
		}
	}
	else
	{
		hs=cnt%n;
		if(hs==0)
		{
			hs=n;
		}
	}
	cout<<hs;
	return 0;
} 