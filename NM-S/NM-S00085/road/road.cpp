#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans=0x3f3f3f3f3f3f3f3f;
struct qkhm{
    long long w;
    int u,v;
};
vector<qkhm>e,E;
int c[11],vis[11],fa[20004],siz[20004];
bool cmp(qkhm x,qkhm y)
{
	return x.w<y.w;
}
int read()
{
	char c;
	int x=0;
	c=getchar();
	while(c<'0'||c>'9')
		c=getchar();
	while(c>='0'&&c<='9')
	{
		x*=10;
		x+=c-'0';
		c=getchar();
	}
	return x;
}
int find(int x)
{
    if(fa[x]==x)
        return x;
    return fa[x]=find(fa[x]);
}
void dfs(int nw)
{
    if(nw==k+1)
    {
        long long sum=0,cnt=n;
        for(int i=1;i<=k;i++)
            if(vis[i]==1)
            {
                sum+=c[i];
                cnt++;
            }
        for(int i=1;i<=n+k;i++)
        {
            fa[i]=i;
            siz[i]=1;
        }
        for(auto i:e)
            if(i.u<=n||vis[i.u-n]==1)
            {
                if(find(i.u)!=find(i.v))
                {
                    if(siz[find(i.u)]<siz[find(i.v)])
                    {
                        fa[find(i.u)]=find(i.v);
                        siz[find(i.v)]+=siz[find(i.u)];
                    }
                    else
                    {
                        fa[find(i.v)]=find(i.u);
                        siz[find(i.u)]+=siz[find(i.v)];
                    }
                    cnt--;
                    sum+=i.w;
                    if(cnt==1)
                        break;
                }
            }
        ans=min(ans,sum);
        return;
    }
    vis[nw]=0;
    dfs(nw+1);
    vis[nw]=1;
    dfs(nw+1);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1,u,v,w;i<=m;i++)
    {
        u=read();
        v=read();
        w=read();
        e.push_back({w,u,v});
    }
    sort(e.begin(),e.end(),cmp);
    ans=0;
    long long cnt=n;
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
        siz[i]=1;
    }
    for(auto i:e)
        if(find(i.u)!=find(i.v))
        {
            if(siz[find(i.u)]<siz[find(i.v)])
            {
                fa[find(i.u)]=find(i.v);
                siz[find(i.v)]+=siz[find(i.u)];
            }
            else
            {
                fa[find(i.v)]=find(i.u);
                siz[find(i.u)]+=siz[find(i.v)];
            }
            E.push_back(i);
            cnt--;
            ans+=i.w;
            if(cnt==1)
                break;
        }
    swap(e,E);
    for(int i=1;i<=k;i++)
    {
        c[i]=read();
        for(int j=1,w;j<=n;j++)
        {
            w=read();
            e.push_back({w,n+i,j});
        }
    }
    sort(e.begin(),e.end(),cmp);
    dfs(1);
    printf("%lld",ans);
    return 0;
}
