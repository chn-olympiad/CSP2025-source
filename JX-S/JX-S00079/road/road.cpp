#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
const int M=1e6+10;
int n,m,k;
int se[N];
int find(int x)
{
    if(x==se[x])return x;
    else return se[x]=find(se[x]);
}
struct edge
{
    int u,v,w;
    bool operator<(const edge&t)const
    {
        return w<t.w;
    }
}e[M];
vector<edge>tree;
long long ans=0;
void kr()
{
    sort(e+1,e+1+m);
    for(int i=1;i<=m;i++)
    {
        int u=e[i].u,v=e[i].v,w=e[i].w;
        int x=find(u),y=find(v);
        if(x==y)continue;
        se[x]=y;
        tree.push_back(e[i]);
        ans+=w;
    }
}
int tmp[N];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)se[i]=i;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        e[i].u=u;
        e[i].v=v;
        e[i].w=w;
    }
    kr();
    //cout<<ans<<'\n';
    for(int i=1;i<=k;i++)
    {
        vector<edge>re=tree;
        int cnt=0;
        cin>>cnt;
        for(int i=1;i<=n;i++)
        {
            cin>>tmp[i];
        }
        for(auto[u,v,w]:re)
        {
            //cout<<tmp[u]+tmp[v]<<' '<<w<<'\n';
            if(tmp[u]+tmp[v]<w)
            {
                w=tmp[u]+tmp[v];
                cnt+=tmp[u]+tmp[v];
            }
            cnt+=w;
        }
        if(cnt<ans)
        {
            ans=cnt;
            tree=re;
        }
    }
    cout<<ans;
    return 0;
}
