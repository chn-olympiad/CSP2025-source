#include <bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1e6+10;
struct edge
{
    int u,v,w;
    bool operator<(const edge &rhs) const
    {
        return w<rhs.w;
    }
}g[M];
int fa[N],c[N],a[20][N];
int find(int x)
{
    if(x==fa[x]) return x;
    else return fa[x]=find(fa[x]);
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m,k;
    long long ans=0,cnt=0;
    bool flagA=true;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>g[i].u>>g[i].v>>g[i].w;
    }
    for(int j=1;j<=k;j++)
    {
		cin>>c[j];
		if(c[j]!=0) flagA=false;
		for(int i=1;i<=n;i++)
        {
            cin>>a[j][i];
            //g[t+i].u=j,j[t+i].v=i,j[t+i].w=a[j][i];
        }
	}
    if(k==0)
    {
        sort(g+1,g+m+1);
        for(int i=1;i<=n;i++)
        {
            fa[i]=i;
        }
        for(int i=1;i<=m;i++)
        {
			int u=find(g[i].u),v=find(g[i].v);
			//cout<<" "<<g[i].u<<" "<<g[i].v<<" "<<g[i].w<<" "<<u<<" "<<v<<" "<<ans<<" "<<cnt<<"\n";
            if(u==v) continue;
            fa[u]=v;
            ans+=g[i].w;
            cnt++;
            if(cnt==n-1) break;
        }
        cout<<ans<<"\n";
    }
    else if(flagA)
    {
        for(int i=1;i<=n;i++)
        {
            for(int l=1;l<i;l++)
            {
                g[++m].u=i,g[m].v=l,g[m].w=1e9;
                for(int j=1;j<=k;j++)
                {
                    g[m].w=min(g[m].w,a[j][i]+a[j][l]);
                }
            }
        }
        sort(g+1,g+m+1);
        for(int i=1;i<=n;i++)
        {
            fa[i]=i;
        }
        for(int i=1;i<=m;i++)
        {
			int u=find(g[i].u),v=find(g[i].v);
			//cout<<" "<<g[i].u<<" "<<g[i].v<<" "<<g[i].w<<" "<<u<<" "<<v<<" "<<ans<<" "<<cnt<<"\n";
            if(u==v) continue;
            fa[u]=v;
            ans+=g[i].w;
            cnt++;
            if(cnt==n-1) break;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
