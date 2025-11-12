#include<bits/stdc++.h>
#define int long long
using namespace std;
long long n,m,k,fa[200200]={0},q,w,use[220]={0},qq,ww;
long long num[200200]={0},ding=0,dian[200200]={0},s=0;
long long firstcome[222]={0},build[222];
struct ff
{
	int u,v,w;
}way[2000200];
int cmp(ff aa,ff bb)
{
	if(aa.w==bb.w)
		return aa.u>bb.u;
	return aa.w<bb.w;
}
int find(int x)
{
	if(fa[x]==x)
		return x;
	return fa[x]=find(fa[x]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<n+100;i++)
		fa[i]=i;
	for(int i=0;i<n;i++)
		dian[i]=1;
	for(int i=0;i<m;i++)
	{
		scanf("%lld%lld%lld",&way[i].u,&way[i].v,&way[i].w);
		way[i].u--,way[i].v--;
	}
	ding=m;
	for(int i=0;i<k;i++)
	{
		cin>>build[i];
		for(int j=0;j<n;j++)
		{
			cin>>w;
			way[ding].u=n+i;
			way[ding].v=j;
			way[ding].w=w+build[i];
			ding++;
		}
	}
	sort(way,way+ding,cmp);
	for(int i=0;i<ding;i++)
	{
		qq=find(way[i].u);
		ww=find(way[i].v);
		if(qq==ww)
			continue;
		fa[qq]=ww;
		if(way[i].u>=n)
		{
			if(use[way[i].u-n]==0)
				firstcome[way[i].u-n]=way[i].w;
			else
				way[i].w-=build[way[i].u-n];
			use[way[i].u-n]++;
		}
		s+=way[i].w;
		dian[ww]+=dian[qq];
		if(dian[ww]==n)
		{
			for(int j=0;j<k;j++)
				if(use[j]==1)
					s-=firstcome[j];
//			for(int j=0;j<k;j++)
//				if(use[j]>1)
//					s+=build[j];
			cout<<s<<endl;
			return 0;
		}
	}
	return 0;
}
