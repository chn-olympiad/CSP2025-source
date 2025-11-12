#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k,cnt,num,mpro;
ll res,ans=1e18;
int c[11];
int fa[10015];
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
int wai[11],nowp[11];
struct bian
{
	int u,v,w;
	bool operator <(bian res)
	{
		return w<res.w;
	}
}eori[1000005],e[10010],ctl[11][100005];
void calc()
{
	memset(nowp,0,sizeof nowp);
	int posie=0;
	while(cnt>1)
	{
		int sels=0,val=posie<mpro?e[posie+1].w:1e9;
		for(int i=1;i<=num;i++)
		{
			if(nowp[i]==n)continue;
			if(ctl[wai[i]][nowp[i]+1].w<=val)sels=i;
		}
		int u,v,w;
		if(sels==0)
		{
			posie++;
			u=e[posie].u,v=e[posie].v,w=e[posie].w;
		}
		else
		{
			nowp[sels]++;
			bian xx=ctl[wai[sels]][nowp[sels]];
			u=xx.u,v=xx.v,w=xx.w;
		}
		u=find(u),v=find(v);
		if(u==v)continue;
		fa[u]=v;
		cnt--;
		res+=w;
	}
}
void pre()
{
	cnt=n;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u=eori[i].u,v=eori[i].v;
		u=find(u),v=find(v);
		if(u==v)continue;
		fa[u]=v;
		e[++mpro]=eori[i];
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		eori[i]={u,v,w};
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
			int w;
			scanf("%d",&w);
			ctl[i][j]={i+n,j,w};
		}
	}
	sort(eori+1,eori+m+1);
	for(int i=1;i<=k;i++)sort(ctl[i]+1,ctl[i]+n+1);
	pre();
	for(int i=0;i<(1<<k);i++)
	{
		num=0;
		for(int j=1;j<=n+k;j++)fa[j]=j;
		res=0,cnt=n,num=0;
		for(int j=0;j<k;j++)
		{
			if((i>>j)&1)
			{
				res+=c[j+1];
				cnt++;
				num++;
				wai[num]=j+1;
			}
		}
		calc();
		ans=min(ans,res);
	}
	printf("%lld",ans);
	return 0;
}
