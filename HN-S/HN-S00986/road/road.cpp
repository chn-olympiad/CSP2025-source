#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
int n,m,k,c[maxn],fa[maxn*2],siz[maxn];
struct node{int x,y,w;};
vector<node> edge;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void unionn(int x,int y){fa[find(x)]=find(y);}
bool cmp(node a,node b){return a.w<b.w;}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edge.push_back({u,v,w});
    }
    sort(edge.begin(),edge.end(),cmp);
    for(int i=1;i<=n;i++) fa[i]=i;
    vector<node> tmp;
    for(auto [u,v,w]:edge)
        if(find(u)!=find(v)) unionn(u,v),tmp.push_back({u,v,w});
    swap(tmp,edge);
    for(int i=1;i<=k;i++)
    {
        cin>>c[i];
        for(int j=1;j<=n;j++)
        {
            int w;
            cin>>w;
            edge.push_back({i+n,j,w});
        }
    }
    sort(edge.begin(),edge.end(),cmp);
    long long mini=1e18;
    for(int s=0;s<(1<<k);s++)
    {
        long long sum=0;
        for(int i=1;i<=n+k;i++) fa[i]=i;
        for(auto [u,v,w]:edge)
        {
            if(u>n&&(((s>>u-n-1)&1)==0)) continue;
            if(find(u)!=find(v)) sum+=w,unionn(u,v);
        }
        for(int i=1;i<=k;i++)
            if(((s>>i-1)&1)==1) sum+=c[i];
        mini=min(mini,sum);
    }
    cout<<mini;
}