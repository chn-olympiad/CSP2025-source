#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<iomanip>
#include<bits/stdc++.h>
using namespace std;
struct otto
{
	long long start;long long end;
	long long val;long long ci;
}z[2000001];
long long n,m,k;
long long a[1001][1001],c[1001][1001][2],q[1001],f[1001],cost[11],water[11],accept[11],ans;//0number,1val
long long u,v,w,zick=1,cick[11][1001];
int zick;
bool visit(long long xx,long long yy)
{
	if(f[xx]==f[yy])return false;
	else if(f[xx]!=xx||f[yy]!=yy){visit(f[xx],f[yy]);return visit(f[xx],f[yy])};
	else 
	{
		if(q[xx]>q[yy]){f[yy]=xx;q[xx]+=q[yy];}
		else {f[xx]=yy;q[yy]+=q[xx];}
		return true;
	}
	
}
int main()
{
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
cin>>n>>m>>k;
for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	c[i][j][1]=-1;
for(int i=1;i<=m;i++){cin>>u>>v>>w;a[u][v]=w;z[zick].start=u;z[zick].end=v;z[zick].val=w;z[zick].ci=0;zick++;}
for(int i=1;i<=k;i++)
{
	cin>>cost[i];
	for(int j=1;j<=n;j++)cin>>cick[i][j];
	for(int j=1;j<=n;j++)
	{
		for(int l=1;i<=n;l++)
		{
			if(c[j][l][1]>cick[i][j]+cick[i][l]){c[j][l][1]=cick[i][j]+cick[i][l];c[j][l][0]=j;}
		}
	}
}
	for(int i=1;i<=n;i++)
	{
	for(int j=1;j<=n;j++)
		{
			z[zick].start=i;
			z[zick].end=j;
			z[zick].val=c[i][j][1];
			z[zick].ci=c[i][j][0];
			zick++;
		}
	}
	sort(z+1,z+zick+1,[&](int x,int y){
	return z[x].val<z[y].val;});
	int p=0;
	for(int i=1;i<=zick;i++)
	{
		if (p==n-1)break;
		if(visit(z[zick].start,z[zick].end)==1&&z[zick].val!=-1)
		{
			water[z[zick].ci]+=a[z[zick].start][z[zick].end]-c[z[zick].start][z[zick].end][1];p++;
		}
		else continue;
	}
	for(int i=1;i<=k;i++)
	if(water[i]>=cost[i]){accept[i]=1;ans-=cost[i];}
	else {accept[i]=0;}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	c[i][j][1]=0;
	for(int i=1;i<=k;i++)
	{
		if(accept[i]==0)continue;
	for(int j=1;j<=n;j++)
	for(int j=1;j<=n;j++)
	{
		for(int l=1;i<=n;l++)
		{
			if(c[j][l][1]>cick[i][j]+cick[i][l]){c[j][l][1]=cick[i][j]+cick[i][l];c[j][l][0]=j;}
		}
	}
	}
	p=0;zick=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{z[zick].start=i;z[zick].end=j;z[zick].val=a[i][j];z[zick].ci=0;zick++;}
	}
	for(int i=1;i<=n;i++)
	{
	for(int j=1;j<=n;j++)
		{
			z[zick].start=i;
			z[zick].end=j;
			z[zick].val=c[i][j][1];
			z[zick].ci=c[i][j][0];
			zick++;
		}
	}
	sort(z+1,z+zick+1,[&](int x,int y){
	return z[x].val<z[y].val;});
	for(int i=1;i<=zick;i++)
	{
		if (p==n-1)break;
		if(visit(z[zick].start,z[zick].end)==1&&z[zick].val!=-1)
		{
			ans+=z[zick].val;p++;
		}
		else continue;
	}
	cout<<ans;
return 0;
}
