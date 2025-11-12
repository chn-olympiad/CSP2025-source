#include<bits/stdc++.h>
#define fre(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout);
using ll=long long;
using namespace std;
const int N=1e4+105;
const int M=1e6+5;
int n,m,k,lim[12];
int c[12];
array<int,3>edge[M],e[12][N];
int fa[N],cnt;
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main()
{
	fre(road);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>edge[i][1]>>edge[i][2]>>edge[i][0];
	}
	for(int i=1;i<=k;i++)
	{
		lim[i+1]=n;
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>e[i+1][j][0];
			e[i+1][j][1]=n+i;
			e[i+1][j][2]=j;
		}
		sort(e[i+1]+1,e[i+1]+n+1);
	}
	sort(edge+1,edge+m+1);
	iota(fa+1,fa+n+1,1);
	ll res=0;
	for(auto [w,u,v]:edge)
	{
		int fu=find(u),fv=find(v);
		if(fu!=fv)
		{
			fa[fu]=fv;
			cnt++;
			res+=w;
			e[1][cnt]={w,u,v};
		}
		if(cnt==n-1)break;
	}
	lim[1]=cnt;
	cerr<<clock()<<endl;
	for(int s=1;s<(1<<k);s++)
	{
		int zj[12],add=0;
		ll sum=0;
		vector<int>hav;
		hav.push_back(1);
		for(int j=1;j<=k;j++)
		{
			if(s&(1<<j-1))hav.push_back(j+1),add++,sum+=c[j];
		}
		fill(zj+1,zj+k+1+1,1);
		iota(fa+1,fa+n+k+1,1);
		int tot=0;
		while(tot!=(n+add-1))
		{
			if(sum>res)break;
			int mn=1e9,at=0;
			for(int i=0;i<hav.size();i++)
			{
				int x=hav[i];
				if(zj[x]<=lim[x])
				{
					mn=min(mn,e[x][zj[x]][0]);
					if(mn==e[x][zj[x]][0])at=x;
				}
			}
			auto [w,u,v]=e[at][zj[at]];
			int fu=find(u),fv=find(v);
			zj[at]++;
			if(fu!=fv)
			{
				tot++;
				sum+=w;
				fa[fu]=fv;
			}
		}
		if(tot==n+add-1)
		res=min(res,sum);
	}
	cerr<<res<<endl;
	cerr<<clock();
	printf("%lld\n",res);
}