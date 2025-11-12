#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=1e4+10;	//N存边,M存点
int read()
{
	int ans=0;
	char cx;
	while(1)
	{
		cx=getchar();
		if(cx>'9'||cx<'0')break;
		ans=ans*10+cx-'0';
	}
	return ans;
}
int n,m,k,cu[15],cun[15][M];	//cu为建村费用，cun为边权
int fa[M],sum,bb2,b1;
bool b[15],bol;
long long ans;
struct bian{
	int begin,next,value;
}bi[N],b2[N+M*15],b3[N+M*15];	//bi为原图（无村庄），b2为生成的树边
int find(int x)	//并查集
{
	while(fa[x]!=x)x=fa[x]=fa[fa[x]];
	return x;
}
bool cmp(bian x1,bian x2)
{
	return x1.value<x2.value;
}
void dfs(int x1,long long asw)	//asw是建村花费，as是答案
{
	if(b[x1])return;
	b[x1]=1;
	asw+=cu[x1];
	long long as=asw;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=n;i++)
	b2[bb2++]={i,x1+n+1,cun[x1][i]};
	for(int i=0;i<bb2;i++)
	b3[i]=b2[i];
	sort(b3,b3+bb2,cmp);
	int u,v;
/*	for(int i=0;i<bb2;i++)
	cout<<b3[i].begin<<" "<<b3[i].next<<" "<<b3[i].value<<endl;
*/	for(int i=0;i<bb2;i++)
	{
		u=b3[i].begin;
		v=b3[i].next;
		u=find(u);
		v=find(v);
		if(u!=v)
		{
			fa[u]=v;
			as+=b3[i].value;
		}
	}
	if(ans<=as)
	{
		b[x1]=0;
		bb2-=n;
		return;
	}
	ans=as;
	for(int i=0;i<k;i++)
	dfs(i,asw);
	bb2-=n;
	b[x1]=0;
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	int u,v,w;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=0;i<m;i++)
	{
		u=read();
		v=read();
		w=read();
		bi[b1++]={u,v,w};
	}
	if(k==0)
	{
		sort(bi,bi+m,cmp);
		for(int i=0;i<m&&sum<n-1;i++)
		{
			u=bi[i].begin;
			v=bi[i].next;
			u=find(u);
			v=find(v);
			if(u!=v)
			{
				fa[u]=v;
				ans+=bi[i].value;
				sum++;
			}
		}
		cout<<ans;
	}
	for(int i=0;i<k;i++)
	{
		cu[i]=read();
		if(cu[i])bol=1;
		for(int j=1;j<=n;j++)
		cun[i][j]=read();
	}
	if(!bol)
	{
		for(int j=0;j<k;j++)
		for(int i=1;i<=n;i++)
		bi[b1++]={i,j+n+1,cun[j][i]};
		for(int i=0;i<b1;i++)
		{
			u=bi[i].begin;
			v=bi[i].next;
			u=find(u);
			v=find(v);
			if(u!=v)
			{
				b2[bb2++]=bi[i];
				fa[u]=v;
				ans+=bi[i].value;
				sum++;
			}
		}
		cout<<ans;
		return 0;
	}
	sort(bi,bi+b1,cmp);
	for(int i=0;i<b1&&sum<n-1;i++)
	{
		u=bi[i].begin;
		v=bi[i].next;
		u=find(u);
		v=find(v);
		if(u!=v)
		{
			b2[bb2++]=bi[i];
			fa[u]=v;
			ans+=bi[i].value;
			sum++;
		}
	}
	for(int i=0;i<k;i++)dfs(i,0);
	cout<<ans;
	return 0;
}
