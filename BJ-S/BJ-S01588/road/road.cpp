#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,m,k;
struct edge
{
    int u,v,w;
}a[N],val[N];
int tp[15][10005];
int c[15],cc[N],vl[N];
int fa[N],cnt,tt;
bool vis[N];
vector<pair<int,int> >qq[N];
int find(int x)
{
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
bool cmp(edge a,edge b)
{
    return a.w<b.w;
}
bool cp(int a,int b)
{
    return cc[a]<cc[b];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        a[i]={u,v,w};
    }
    for(int i=1;i<=n;i++)fa[i]=i;
    sort(a+1,a+1+m,cmp);
    long long ans=0;
    for(int i=1;i<=m;i++)
    {
        int x=a[i].u,y=a[i].v;
        if(find(x)==find(y))continue;
        val[++cnt]=a[i];
        fa[find(y)]=find(x);
        vl[++tt]=a[i].w;
		ans+=a[i].w;
    }
    for(int j=1;j<=k;j++)
    {
        cin>>c[j];
        for(int i=1;i<=n;i++)
        {
            cin>>tp[j][i];
            vl[++tt]=tp[j][i];
        }
    }
    sort(vl+1,vl+1+tt);
    tt=unique(vl+1,vl+1+tt)-(vl+1);
    for(int i=1;i<=cnt;i++)
    {
        val[i].w=lower_bound(vl+1,vl+1+tt,val[i].w)-vl;
    }
    for(int j=1;j<=k;j++)
    {
        for(int i=1;i<=n;i++)
        {
            tp[j][i]=lower_bound(vl+1,vl+1+tt,tp[j][i])-vl;
        }
    }

    for(int x=0;x<(1<<k);x++)
    {
        for(int i=1;i<=tt;i++)qq[i].clear();
        for(int i=1;i<=n+k;i++)fa[i]=i;
        long long as=0;
        for(int j=1;j<=k;j++)
        {
			if((x>>(j-1))&1)
			{
				for(int k=1;k<=n;k++)
				{
					qq[tp[j][k]].push_back({j+n,k});
				}
				as+=c[j];
			}
		}
		for(int j=1;j<=cnt;j++)qq[val[j].w].push_back({val[j].u,val[j].v});
		for(int i=1;i<=tt;i++)
		{
			for(auto xx:qq[i])
			{
				if(find(xx.first)!=find(xx.second))
				{
					fa[find(xx.second)]=xx.first;
					as+=vl[i];
				}
			}
		}
        //(x==0)cerr<<as<<"!!\n";
        ans=min(ans,as);
    }
    cout<<ans<<'\n';
}
