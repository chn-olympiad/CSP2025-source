#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=1e6+10;
const int N=1e4+10;
int n,m,k;
int fa[N];
struct node 
{
    int u,v,w;
}a[M];

inline bool cmp(node a,node b)
{
    return a.w<b.w;
}

inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}

signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    int cnt=0,ans=0;
    for(int i=1;i<=n;++i)
        fa[i]=i;
    for(int i=1;i<=m;++i)
        cin>>a[i].u>>a[i].v>>a[i].w;
    sort(a+1,a+1+m,cmp);
    for(int i=1;i<=m;++i)
    {
        int fx=find(a[i].u),fy=find(a[i].v);
        if(fx!=fy)
        {
            ans+=a[i].w;
            fa[fx]=fy;
            ++cnt;
        }
        if(cnt==n-1)
            break;
    }
    cout<<ans;
    return 0;
}

//zhuijile
