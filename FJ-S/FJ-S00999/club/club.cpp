#include<bits/stdc++.h>
using namespace std;
void jj()
{
	int ans=0;
	int n;
	cin>>n;
	int myd[n+1][4],sum[4];
	int vis[4],inb[n+1],ren=n;
	for(int i=1;i<=3;i++)
	{
		vis[i]=n/2;
		sum[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		inb[i]=0;
		for(int j=1;j<=3;j++)
		{
			cin>>myd[i][j];
			sum[j]+=myd[i][j];
		}
	}
	while(ren)
	{
		int mx=-1000000000,hao;
		for(int i=1;i<=3;i++)
		{
			if(sum[i]>mx&&vis[i])
			{
				mx=sum[i];
				hao=i;
			}
		}
		int mmx=-1000000000,hs;
		for(int i=1;i<=n;i++)
		{
			if(myd[i][hao]>mmx&&!inb[i])
			{
				mmx=myd[i][hao];
				hs=i;
			}
		}
		ans+=mmx;
		inb[hs]=1;
		ren--;
		vis[hao]--;
		for(int i=1;i<=3;i++)
		sum[i]=sum[i]-myd[hs][i];
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		jj();
	}
	return 0;
}
