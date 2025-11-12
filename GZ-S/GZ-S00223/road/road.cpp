//GZ-S00223 贵州省铜仁第一中学 李宜鸿
#include <bits/stdc++.h>
using namespace std;
int mp[10100][10100];
int ck[20];
int mpk[20][10100];
int nv[10100];
int n,m,k;
int u,v,w;
int cnt,min1,zz1,zz2,zz3;
int min2=1e7;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n>>m>>k;
	memset(mp,127,sizeof(mp));
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		mp[u][v]=w;
		mp[v][u]=w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>ck[i];
		for(int j=1;j<=n;j++)
		{
			cin>>mpk[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(nv[i]==1)continue;
		for(int j=1;i!=j && j<=n;j++)
		{
			zz3=j;
			for(int s=2;s<=k;s++)
			{
				min1=min(ck[s-1]+mpk[s-1][i]+mpk[s-1][j],ck[s]+mpk[s][i]+mpk[s][j]);
				if(min1==ck[s-1]+mpk[s-1][i]+mpk[s-1][j])
				{
					zz1=s-1;
				}else
				{
					zz1=s;
				}
			}
			min1=min(min1,mp[i][j]);
			min2=min(min1,min2);
			if(min2==min1)
			{
				zz3=j;
				if(min1==mp[i][j])
				{
					zz1=0;
					zz2=j;
				}else
				{
					zz2=0;
				}
			}
		}
		nv[zz3]=1;
		ck[zz1]=0;
		mpk[zz1][i]=0;
		mpk[zz1][zz3]=0;
		mp[i][zz2]=0;
		cnt+=min2;
	}
	cout<<cnt;
	return 0;
}
